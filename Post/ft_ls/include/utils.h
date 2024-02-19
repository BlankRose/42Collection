/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  utils.h                                                */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 14, 2024 [12:50 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#ifndef _UTILS
# define _UTILS

#include <sys/types.h>
#include <stddef.h>

// 
//   STRINGS
// 
// Utilities functions related to strings
// or raw memory
// 
// ///////////////////////////

size_t	len(const char *s);
size_t	nlen(const long long n);
size_t	ulen(unsigned long long n);
int		cmp(const void *a, const void *b, size_t n);
void	copy(const void *s, void *d, size_t n);
void	*mdup(const void *s, size_t n);
char	*sdup(const char *s, size_t n);
char	*join(const char *a, const char *b);
void	inplace_nb(char *buffer, const long long n);


// 
//   DIRECTORIES
// 
// Utilities functions related to directories,
// useful for later usages
// 
// ///////////////////////////

typedef struct dirent s_dirent;

ssize_t		dirlen(const char *path);
int			hasAccess(const char *path);


// 
//   MATHS
// 
// Short mathematics functions
// 
// ///////////////////////////

float				ceiling(float value);
unsigned long long	stoi(const char *str);


// 
//   OUTPUT
// 
// Implements functions to print various types
// of values, across any provided fds
// 
// ///////////////////////////

int			cwrite(const int fd, const int c);
int			swrite(const int fd, const char *str);
int			nwrite(const int fd, const long long nbr);

int			print(const int fd, const char *format, ...);

#endif /* _UTILS */
