/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  colors.h                                               */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: February 01, 2024 [07:41 pm]             */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#ifndef _COLORS
# define _COLORS

# define NO_COLOR            "\033[0m"

# define COLOR_DIR           "\033[34;1m"
# define COLOR_EXEC          "\033[32;1m"
# define COLOR_SYMLINK       "\033[36;1m"
# define COLOR_BROKENLINK    "\033[31;40;1m"
# define COLOR_ARCHIVE       "\033[31;1m"
# define COLOR_MEDIA         "\033[35m"
# define COLOR_AUDIO         "\033[36m"

# define COLOR(color, str)   color str NO_COLOR

#endif /* _COLORS */
