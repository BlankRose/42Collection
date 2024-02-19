/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  sort.c                                                 */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 14, 2024 [02:44 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "ft_ls.h"

typedef int (*t_cmp)(const s_dir *, const size_t, const size_t);

static void ls_sort_algo(s_dir *dir, t_cmp cmp);
static void ls_swap(const s_dir *dir, const size_t a, const size_t b);

static int ls_cmp_atime(const s_dir *dir, const size_t a, const size_t b);
static int ls_cmp_mtime(const s_dir *dir, const size_t a, const size_t b);
static int ls_cmp_ctime(const s_dir *dir, const size_t a, const size_t b);
static int ls_cmp_alpha(const s_dir *dir, const size_t a, const size_t b);
static int ls_cmp_size(const s_dir *dir, const size_t a, const size_t b);

void ls_sort(s_dir *dir, const e_sort sort)
{
	// SELECT APPROPRIATE COMPARATOR
	t_cmp  comparator = NULL;
	switch (sort)
	{
		case SORT_ACCESS_TIME:
			comparator = ls_cmp_atime;
			break;
		case SORT_MOD_TIME:
			comparator = ls_cmp_mtime;
			break;
		case SORT_NEW_TIME:
			comparator = ls_cmp_ctime;
			break;
		case SORT_ALPHABETIC:
			comparator = ls_cmp_alpha;
			break;
		case SORT_SIZE:
			comparator = ls_cmp_size;
			break;
		default:
			return;
	}

	// EXECUTE SORTING ALGORITHM
	if (comparator)
		ls_sort_algo(dir, comparator);
}

void ls_reverse(s_dir *dir)
{
	// SWAP BEGIN TO END TOWARDS MIDDLE
	for (ssize_t s = 0, e = dir->total - 1; s < e; s++, e--)
		ls_swap(dir, s, e);
}

// QUICK SORT ALGORITHM
// ///////////////////////////

static
ssize_t ls_partition(s_dir *dir, t_cmp cmp, ssize_t low, ssize_t top)
{
	ssize_t  i = low - 1;
	for (ssize_t y = low; y < top; y++)
		if (cmp(dir, y, top) < 0)
			ls_swap(dir, ++i, y);
	ls_swap(dir, i + 1, top);
	return i + 1;
}

static
void ls_quicksort(s_dir *dir, t_cmp cmp, ssize_t low, ssize_t top)
{
	if (low < top)
	{
		ssize_t  p = ls_partition(dir, cmp, low, top);
		ls_quicksort(dir, cmp, low, p - 1);
		ls_quicksort(dir, cmp, p, top);
	}
}

static
void ls_sort_algo(s_dir *dir, t_cmp cmp)
{
	// SPECIAL CASE: Only 2 elements
	if (dir->total == 2 && cmp(dir, 1, 0) < 0)
	{
		ls_swap(dir, 1, 0);
		return;
	}
	ls_quicksort(dir, cmp, 0, dir->total - 1);
}

// COMPARATOR FUNCTIONS
// ///////////////////////////

static
int ls_cmp_atime(const s_dir *dir, const size_t a, const size_t b)
{
	if (dir->stats[a].st_atim.tv_sec == dir->stats[b].st_atim.tv_sec)
	{
		if (dir->stats[a].st_atim.tv_nsec < dir->stats[b].st_atim.tv_nsec)
			return 1;
		if (dir->stats[a].st_atim.tv_nsec == dir->stats[b].st_atim.tv_nsec)
			return ls_cmp_alpha(dir, a, b);
	}
	else if (dir->stats[a].st_atim.tv_sec < dir->stats[b].st_atim.tv_sec)
		return 1;
	return -1;
}

static
int ls_cmp_mtime(const s_dir *dir, const size_t a, const size_t b)
{
	if (dir->stats[a].st_mtim.tv_sec == dir->stats[b].st_mtim.tv_sec)
	{
		if (dir->stats[a].st_mtim.tv_nsec < dir->stats[b].st_mtim.tv_nsec)
			return 1;
		if (dir->stats[a].st_mtim.tv_nsec == dir->stats[b].st_mtim.tv_nsec)
			return ls_cmp_alpha(dir, a, b);
	}
	else if (dir->stats[a].st_mtim.tv_sec < dir->stats[b].st_mtim.tv_sec)
		return 1;
	return -1;
}

static
int ls_cmp_ctime(const s_dir *dir, const size_t a, const size_t b)
{
	if (dir->stats[a].st_ctim.tv_sec == dir->stats[b].st_ctim.tv_sec)
	{
		if (dir->stats[a].st_ctim.tv_nsec < dir->stats[b].st_ctim.tv_nsec)
			return 1;
		if (dir->stats[a].st_ctim.tv_nsec == dir->stats[b].st_ctim.tv_nsec)
			return ls_cmp_alpha(dir, a, b);
	}
	else if (dir->stats[a].st_ctim.tv_sec < dir->stats[b].st_ctim.tv_sec)
		return 1;
	return -1;
}

static
int ls_cmp_alpha(const s_dir *dir, const size_t a, const size_t b)
{
	size_t        i     = 0;
	const char *  str_a = get_path(dir, a);
	const char *  str_b = get_path(dir, b);
	char          char_a, char_b, side = 0;

	// IGNORE DOTS
	while (*str_a == '.')
		str_a++;
	while (*str_b == '.')
		str_b++;
	if (!*str_a && !*str_b)
		return len(get_path(dir, a)) - len(get_path(dir, b));

	// CHECKS FOR DIFFERENT CHARACTERS
	while (str_a[i] && str_b[i])
	{
		char_a = str_a[i] + (str_a[i] >= 'A' && str_a[i] <= 'Z' ? 'a' - 'A' : 0);
		char_b = str_b[i] + (str_b[i] >= 'A' && str_b[i] <= 'Z' ? 'a' - 'A' : 0);
		if (char_a != char_b)
			return char_a - char_b;
		if (!side && str_a[i] != str_b[i])
			side = str_b[i] - str_a[i];
		i++;
	}

	// CHECKS FOR DIFFERENT LENGTH
	if (str_a[i] || str_b[i])
		return str_a[i] ? 1 : -1;

	// CHECKS FOR OTHERS PRIORITY
	if (side)
		return side;
	return len(get_path(dir, b)) - len(get_path(dir, a));
}

static
int ls_cmp_size(const s_dir *dir, const size_t a, const size_t b)
{
	if (dir->stats[a].st_size == dir->stats[b].st_size)
		return ls_cmp_alpha(dir, a, b);
	if (dir->stats[a].st_size < dir->stats[b].st_size)
		return 1;
	return -1;
}

static
void ls_swap(const s_dir *dir, size_t a, const size_t b)
{
	// SWAP PATHS
	void *           path = dir->content.files[b];
	dir->content.files[b] = dir->content.files[a];
	dir->content.files[a] = path;

	// SWAP STATS
	if (dir->stats)
	{
		s_stat   stat = dir->stats[b];
		dir->stats[b] = dir->stats[a];
		dir->stats[a] = stat;
	}
}
