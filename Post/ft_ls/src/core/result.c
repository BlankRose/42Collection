/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  result.c                                               */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 15, 2024 [11:18 am]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "ft_ls.h"

typedef
struct groups
{
	char *  owner;
	char *  group;
}
s_grp;

static void print_short_folder(const s_args *args, const s_dir *dir);
static void print_long_folder(const s_args *args, const s_dir *dir);
static s_grp *get_groups(const s_dir *dir, int fetch);
static void free_groups(s_grp *grp, ssize_t n);
static void get_date(char buffer[DATE_SIZE], const time_t *stat);
static void get_link(const char *dir, const char *file);
static int has_acl(const char *dir, const char *file);

void print_folder(const s_args *args, const s_dir *dir)
{
	// DISPLAY COMMON ELEMENTS
	if (dir->path && (args->count > 1 || hasBit(args->flags, FLAG_RECURSIVE)))
		print(1, "%s:\n", dir->path);
	if (dir->total <= 0 || !dir->content.files)
		return;

	// CHOOSE APPROPRIATE DISPLAY FUNCTION
	if (hasBit(args->flags, FLAG_LONG))
		print_long_folder(args, dir);
	else
		print_short_folder(args, dir);
}

static
void print_long_folder(const s_args *args, const s_dir *dir)
{
	size_t   max[6] = { 0, 0, 0, 0, 0, 0 };
	mode_t   mode   = 0;
	size_t   length = 0;
	s_grp *  owners = NULL;
	char *   buffer = NULL;
	size_t   size   = 0;
	char     hasACL = 0;

	// RETRIEVE BASE INFORMATIONS
	owners = get_groups(dir,
		  (hasBit(args->flags, FLAG_HIDEGROUP) ? 0 : GET_GROUP)
		| (hasBit(args->flags, FLAG_HIDEOWNER) ? 0 : GET_OWNER));

	// RETRIEVE MAXIMUM WIDTHS
	for (ssize_t i = 0; i < dir->total; i++)
	{
		// CALCULATE TOTAL BLOCK SIZE
		size += ceiling(dir->stats[i].st_blocks * LS_FILE_SIZE / args->blksize);
		if (hasBit(args->flags, FLAG_BLKSIZE))
			dir->stats[i].st_size = ceiling((float) dir->stats[i].st_size / args->blksize);

		// ACCESS CONTROL LIST
		if (!hasACL)
			hasACL = has_acl(dir->path, get_path(dir, i));

		// LINK COUNTER
		length = nlen(dir->stats[i].st_nlink);
		if (length > max[0]) max[0] = length;
		if (owners)
		{
			// OWNER NAME
			length = len(owners[i].owner);
			if (length > max[1]) max[1] = length;
			// GROUP NAME
			length = len(owners[i].group);
			if (length > max[2]) max[2] = length;
		}
		// FILE SIZE
		if (!dir->stats[i].st_rdev)
		{
			length = nlen(dir->stats[i].st_size);
			if (length > max[3]) max[3] = length;
		}
		// DEVILE IDS
		else
		{
			length = nlen(major(dir->stats[i].st_rdev));
			if (length > max[4]) max[4] = length;
			length = nlen(minor(dir->stats[i].st_rdev));
			if (length > max[5]) max[5] = length;
			length = max[4] + max[5] + /*[, ]*/ 2;
			if (length > max[3]) max[3] = length;
		}
	}
	print(1, "total %d\n", size);

	// CREATE BASE BUFFER
	size = PERMS_SIZE + hasACL + SPACE + max[0] +
		(!owners ? 0 :
			  (!hasBit(args->flags, FLAG_HIDEOWNER) ? (SPACE + max[1]) : 0)
			+ (!hasBit(args->flags, FLAG_HIDEGROUP) ? (SPACE + max[2]) : 0))
		+ SPACE + max[3] + SPACE + DATE_SIZE + SPACE;
	buffer = malloc(size);
	if (!buffer)
	{
		swrite(2, "ft_ls: allocation failure\n");
		return;
	}

	for (ssize_t x = 0; x < dir->total; x++)
	{
		size_t i = PERMS_SIZE;

		// TYPE AND PERMISSIONS FIELD
		mode = dir->stats[x].st_mode;
		switch (mode & S_IFMT)
		{
			case S_IFREG:  buffer[0] = '-'; break;
			case S_IFDIR:  buffer[0] = 'd'; break;
			case S_IFLNK:  buffer[0] = 'l'; break;
			case S_IFCHR:  buffer[0] = 'c'; break;
			case S_IFBLK:  buffer[0] = 'b'; break;
			case S_IFIFO:  buffer[0] = 'p'; break;
			case S_IFSOCK: buffer[0] = 's'; break;
			default:       buffer[0] = '?'; break;
		}
		buffer[1] = mode & S_IRUSR ? 'r' : '-';
		buffer[2] = mode & S_IWUSR ? 'w' : '-';
		buffer[3] = mode & S_IXUSR ? 'x' : '-';
		buffer[4] = mode & S_IRGRP ? 'r' : '-';
		buffer[5] = mode & S_IWGRP ? 'w' : '-';
		buffer[6] = mode & S_IXGRP ? 'x' : '-';
		buffer[7] = mode & S_IROTH ? 'r' : '-';
		buffer[8] = mode & S_IWOTH ? 'w' : '-';
		buffer[9] = mode & S_IXOTH ? 'x' : '-';

		// SHOW EXTENDED ACLS
		if (hasACL)
			buffer[i++] = has_acl(dir->path, get_path(dir, x)) ? '+' : ' ';

		// LINK COUNTER FIELD
		length = nlen(dir->stats[x].st_nlink);
		for (size_t j = 0; j < max[0] - length + 1; j++)
			buffer[i++] = ' ';
		inplace_nb(&buffer[i], dir->stats[x].st_nlink);
		i += length;

		if (owners)
		{
			// OWNER USER FIELD
			if (!hasBit(args->flags, FLAG_HIDEOWNER))
			{
				buffer[i++] = ' ';
				length = len(owners[x].owner);
				copy(owners[x].owner, &buffer[i], length);
				i += length;
				for (size_t j = 0; j < max[1] - length; j++)
					buffer[i++] = ' ';
			}

			// OWNER GROUP FIELD
			if (!hasBit(args->flags, FLAG_HIDEGROUP))
			{
				buffer[i++] = ' ';
				length = len(owners[x].group);
				copy(owners[x].group, &buffer[i], length);
				i += length;
				for (size_t j = 0; j < max[2] - length; j++)
					buffer[i++] = ' ';
			}
		}

		// FILE SIZE FIELD
		if (!dir->stats[x].st_rdev)
		{
			length = nlen(dir->stats[x].st_size);
			for (size_t j = 0; j < max[3] - length + 1; j++)
				buffer[i++] = ' ';
			inplace_nb(&buffer[i], dir->stats[x].st_size);
			i += length;
		}

		// DEVICE IDS FIELD
		else
		{
			length = max[4] + max[5] + /*[, ]*/ 2;
			for (size_t j = 0; j < max[3] - length + 1; j++)
				buffer[i++] = ' ';
			length = nlen(major(dir->stats[x].st_rdev));
			for (size_t j = 0; j < max[4] - length; j++)
				buffer[i++] = ' ';
			inplace_nb(&buffer[i], major(dir->stats[x].st_rdev));
			i += length;
			buffer[i++] = ',';
			length = nlen(minor(dir->stats[x].st_rdev));
			for (size_t j = 0; j < max[5] - length + 1; j++)
				buffer[i++] = ' ';
			inplace_nb(&buffer[i], minor(dir->stats[x].st_rdev));
			i += length;
		}

		// FILE DATE FIELD
		buffer[i++] = ' ';
		if (hasBit(args->flags, FLAG_CTIME))
			get_date(&buffer[i], &dir->stats[x].st_ctim.tv_sec);
		else if (hasBit(args->flags, FLAG_ATIME))
			get_date(&buffer[i], &dir->stats[x].st_atim.tv_sec);
		else
			get_date(&buffer[i], &dir->stats[x].st_mtim.tv_sec);
		i += DATE_SIZE;
		buffer[i++] = ' ';
		write(1, buffer, i);

		// FILE NAME FIELD
		swrite(1, get_path(dir, x));
		if (buffer[0] == 'l')
			get_link(dir->path, get_path(dir, x));

		cwrite(1, '\n');
	}
	free(buffer);
	free_groups(owners, dir->total);
}

static
void print_short_folder(const s_args *args, const s_dir *dir)
{
	char *  buffer    = NULL;
	size_t  max_len   = 0;
	size_t  total_len = 0;
	size_t  cols      = 0;

	// SINGLE COLUMN: redirect | -1
	if (hasBit(args->flags, FLAG_SINGLE) || args->width <= 2)
	{
		for (ssize_t i = 0; i < dir->total; i++)
			print(1, "%s\n", get_path(dir, i));
		return;
	}

	// MULTIPLE COLUMNS: tty | -C
	for (ssize_t i = 0; i < dir->total; i++)
	{
		cols = len(get_path(dir, i));
		total_len += cols + 2;
		max_len = cols > max_len ? cols : max_len;
	}

	// OPTIMIZATION CASE: Can fit in one row
	total_len -= 2;
	if (total_len < args->width)
	{
		for (ssize_t i = 0; i < dir->total; i++)
		{
			swrite(1, get_path(dir, i));
			if (i + 1 < dir->total)
				swrite(1, "  ");
		}
		cwrite(1, '\n');
		return;
	}

	// OPTIMIZATION CASE: Cannot fit in more than 2 columns
	max_len += 2;
	if (max_len * 2 > args->width)
	{
		for (ssize_t i = 0; i < dir->total; i++)
			print(1, "%s\n", get_path(dir, i));
		return;
	}

	// UN-OPTIMIZED CASE
	buffer = malloc(args->width);
	if (!buffer)
	{
		swrite(2, "ft_ls: allocation failure\n");
		return;
	}
	cols = args->width / max_len;
	total_len = ceiling((float) dir->total / cols);
	for (size_t x = 0; x < total_len; x++)
	{
		size_t i = 0;
		for (size_t y = 0; y < cols; y++)
		{
			const ssize_t  pos = y * total_len + x;
			if (pos >= dir->total)
				continue;

			// WRITE FILE/DIR NAME
			const char *   path   = get_path(dir, pos);
			const size_t   length = len(path);
			for (size_t j = 0; j < length; j++)
				buffer[i++] = path[j];

			// DO SPACES WITH OPTIMIZATIONS
			if (y != cols - 1)
				for (size_t j = 0; j < max_len - length; j++)
					buffer[i++] = ' ';
		}
		buffer[i++] = '\n';
		write(1, buffer, i);
	}
	free(buffer);
	return;
}

static
s_grp *get_groups(const s_dir *dir, const int fetch)
{
	if (!fetch || !dir)
		return NULL;

	s_grp *  res = malloc(dir->total * sizeof(s_grp));
	if (!res)
		return NULL;

	void  *tmp;
	for (ssize_t i = 0; i < dir->total; i++)
	{
		if (hasBit(fetch, GET_OWNER)
				&& (tmp = getpwuid(dir->stats[i].st_uid)))
			res[i].owner = sdup(((struct passwd *) tmp)->pw_name, -1);
		else
			res[i].owner = NULL;

		if (hasBit(fetch, GET_GROUP)
				&& (tmp = getgrgid(dir->stats[i].st_gid)))
			res[i].group = sdup(((struct group *) tmp)->gr_name, -1);
		else
			res[i].group = NULL;
	}
	return res;
}

static
void free_groups(s_grp *grp, ssize_t n)
{
	if (!grp)
		return;
	for (ssize_t i = 0; i < n; i++)
	{
		free(grp[i].owner);
		free(grp[i].group);
	}
	free(grp);
}

static
void get_date(char buffer[DATE_SIZE], const time_t *stat)
{
	static const size_t  off  = 4;
	char *               time = ctime(stat);

	if (time)
		for (size_t i = 0; i < DATE_SIZE; i++)
			buffer[i] = time[i + off];
	else
		for (size_t i = 0; i < DATE_SIZE; i++)
			buffer[i] = '\0';
}

static
void get_link(const char *dir, const char *file)
{
	char *   tmp[2] = { NULL, NULL };
	char     buf[PATH_MAX + 1];
	ssize_t  i = 0;

	tmp[0] = join(dir, "/");
	if (!tmp[0])
	{
		swrite(1, " -> ?");
		return;
	}
	tmp[1] = join(tmp[0], file);
	free(tmp[0]);
	if (!tmp[1])
	{
		swrite(1, " -> ?");
		return;
	}

	for (size_t j = 0; j < PATH_MAX + 1; j++)
		buf[j] = '\0';
	i = readlink(tmp[1], buf, PATH_MAX);
	if (i > 0)
	{
		swrite(1, " -> ");
		write(1, buf, i);
	}
	else
		swrite(1, " -> ?");
	free(tmp[1]);
}

static
int has_acl(const char *dir, const char *file)
{
	char *  tmp[2] = { NULL, NULL };
	int     res    = 0;

	tmp[0] = join(dir, "/");
	if (!tmp[0])
		return 0;
	tmp[1] = join(tmp[0], file);
	free(tmp[0]);
	if (!tmp[1])
		return 0;
	res = acl_extended_file_nofollow(tmp[1]);
	free(tmp[1]);
	return res > 0;
}

char *get_path(const s_dir *dir, const size_t i)
{
	return dir->path
		? dir->content.files[i]->d_name
		: dir->content.paths[i];
}
