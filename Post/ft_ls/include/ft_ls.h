/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  ft_ls.h                                                */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 15, 2024 [09:42 am]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

// 
//   INCLUDES
// All neccesary includes used by the projects
// aswell as side includes files created
// 
// ///////////////////////////

#include <acl/libacl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/xattr.h>
#include <errno.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#include "bits.h"
#include "utils.h"
#include "constants.h"


// 
//   FLAGS
// Used for keeping track of every options and arguments
// passed or special stuff that occured
// 
//  Files : options.c
// 
// ///////////////////////////

typedef
enum flags
{
	FLAG_ERROR       = 1 << 15, // Found unknown flags
	FLAG_REDIRECTED  = 1 << 14, // Detected redirected output

	FLAG_ALL         = 1 <<  0, // -a | --all         | Includes hidden files
	FLAG_RECURSIVE   = 1 <<  1, // -R | --recursive   | Recursively list
	FLAG_REVERSE     = 1 <<  2, // -r | --reverse     | Reverses the output
	FLAG_LONG        = 1 <<  3, // -l |               | Long listing formatting

	FLAG_DIRECTORY   = 1 <<  4, // -d | --directory   | List directory themselves
	FLAG_HIDEOWNER   = 1 <<  5, // -g |               | Long listing without Owner
	FLAG_SINGLE      = 1 <<  6, // -1 |               | Single column format (cancel MULTIPLE)
    FLAG_MULTIPLE    = 1 <<  7, // -C |               | Multiple column format (cancel SINGLE)
	FLAG_COLOR       = 1 <<  8, //    | --color[=]    | Colorize output
	FLAG_BLKSIZE     = 1 <<  9, //    | --block-size= | Defines the LS_BLOCK_SIZE for calculus
	FLAG_CTIME       = 1 << 10, // -c |               | Sort by or displays creation time (cancel ATIME)
	FLAG_ATIME       = 1 << 11, // -u |               | Sort by or displays access time (cancel CTIME)
	FLAG_HIDEGROUP   = 1 << 12, // -o |               | Long listing without Group
}
e_flags;

typedef
enum sort
{
	SORT_NONE        = 0,       // -U | No sort (faster), ignores reverse option
	SORT_MOD_TIME    = 1,       // -t | Sort by last edited time, newer first
	SORT_NEW_TIME    = 2,       // -c | Sort by creation time, newer first
	SORT_ALPHABETIC  = 3,       //    | Default sorting
	SORT_SIZE        = 4,       // -S | Sort by file size, largest first
	SORT_ACCESS_TIME = 5,       // -u | Sort by access time, newer first
}
e_sort;

typedef unsigned short t_flags;

typedef
struct target
{
	char *        path;
	char          is_dir;
}
s_target;

typedef
struct arguments
{
	t_flags       flags;
	e_sort        sort;
	s_target *    targets;
	size_t        count;
	size_t        width;
	size_t        blksize;
}
s_args;

void		parse_options(int argc, char **argv, s_args *args);
char **		parse_arguments(int argc, char **argv, size_t *store);


// 
//   ARGUMENTS
// Used for storing FLAGS and targets given to run ls on
// aswell as any additional useful informations
// 
//  Files : init.c
// 
// ///////////////////////////

#define FAIL_SAFE_WIDTH 80

typedef struct stat s_stat;

typedef
union dir_content
{
	char **       paths;
	s_dirent **   files;
}
u_content;

typedef
struct folder
{
	const char *  path;
	s_stat *      stats;
	ssize_t       total;
	u_content     content;
}
s_dir;

s_args *	ls_init(int argc, char **argv);
void		ls_end(s_args *args);


//   OUTPUT
// Functions dedicated to simple output logics
// (e.g., error messages)
// 
//  Files : output.c result.c
// 
// ///////////////////////////

typedef
enum error
{
	ERR_NONE         = 0,
	ERR_ALLOC        = 1,
	ERR_OPENDIR      = 2,
	ERR_READDIR      = 3,
	ERR_SUBDIR       = 4,
}
e_err;

void		color_error(t_flags *flags, const char *sub, const char *cause);
void		opt_error(t_flags *flags, const char *info, const char *opt);
void *		mem_error(char **raw, size_t len);
void		print_help();
void		print_folder(const s_args *args, const s_dir *dir);
char *		get_path(const s_dir *dir, const size_t i);

// 
//   LOGIC
// Primary functions to handle the LS logic
// 
//  Files : unfold.c stat.c date.c sort.c
// 
// ///////////////////////////

int			ls_start_unfold(s_args *args);
e_err		ls_stat_folder(s_dir *dir, const s_args *args);
e_err		ls_clear_dots(s_dir *dir);
void		ls_sort(s_dir *dir, const e_sort sort);
void		ls_reverse(s_dir *dir);
void		clear_dir(s_dir *dir);

#endif /* FT_LS */
