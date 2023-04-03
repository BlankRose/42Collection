/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:44:55 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/07 11:51:47 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H
# include "../libft.h"

/*********************************************************/
/*                                                       */
/*                     DEFINITIONS                       */
/*  Various macros for easier handling across functions  */
/*                                                       */
/*********************************************************/

/* Definition for buffers' size (Used by read()) */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

/* Definitions of booleans */
# define TRUE 1
# define FALSE 0

/*********************************************************/
/*                                                       */
/*                          BASES                        */
/* A list of every commonly used bases across the planet */
/*                                                       */
/*********************************************************/

# define BINARY "01"
# define OCTAL "01234567"
# define DECIMAL "0123456789"
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"
# define HEXA HEXA_UP

/*********************************************************/
/*                                                       */
/*                    FONTS AND COLORS                   */
/*   A bunch of quick color picker for coloring texts    */
/*                                                       */
/*********************************************************/

/* Colors */
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
/* Background */
# define BG_BLACK "\033[40m"
# define BG_RED "\033[41m"
# define BG_GREEN "\033[42m"
# define BG_YELLOW "\033[43m"
# define BG_BLUE "\033[44m"
# define BG_PURPLE "\033[45m"
# define BG_CYAN "\033[46m"
# define BG_WHITE "\033[47m"
/* Light Colors */
# define LIT_BLACK "\033[90m"
# define LIT_RED "\033[91m"
# define LIT_GREEN "\033[92m"
# define LIT_YELLOW "\033[93m"
# define LIT_BLUE "\033[94m"
# define LIT_PURPLE "\033[95m"
# define LIT_CYAN "\033[96m"
# define LIT_WHITE "\033[97m"
/* Light Background */
# define LIT_BG_BLACK "\033[100m"
# define LIT_BG_RED "\033[101m"
# define LIT_BG_GREEN "\033[102m"
# define LIT_BG_YELLOW "\033[103m"
# define LIT_BG_BLUE "\033[104m"
# define LIT_BG_PURPLE "\033[105m"
# define LIT_BG_CYAN "\033[106m"
# define LIT_BG_WHITE "\033[107m"
/* Fonts */
# define BOLD "\033[1m"
# define DARK "\033[2m"
# define ITALIC "\033[3m"
# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"
# define BG_REVERSE "\033[7m"
# define HIDDEN "\033[8m"
# define STRIKE "\033[9m"
/* Resetters */
# define COLORLESS "\033[39m"
# define FONTLESS "\033[22;23m"
# define RESETFONT "\033[0m"

/*********************************************************/
/*                                                       */
/*                     GLOBAL LIMITS                     */
/*             Here is a few limits preset               */
/*                                                       */
/*********************************************************/

// Character
# define CHAR_MAX 127
# define CHAR_MIN -128
# define UN_CHAR_MAX 255
# define UN_CHAR_MIN 0

// Short
# define SHORT_MAX 32767
# define SHORT_MIN -32768
# define UN_SHORT_MAX 65535
# define UN_SHORT_MIN 0

// Integer
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define UN_INT_MAX 4294967295
# define UN_INT_MIN 0

// Long
# define LONG_MAX 9223372036854775807L
# define LONG_MIN -9223372036854775807L
# define UN_LONG_MAX 18446744073709551615L
# define UN_LONG_MIN 0L

/*********************************************************/
/*                                                       */
/*                   KEYBOARD KEYCODES                   */
/*      Its just a complete list of every keycodes       */
/*                                                       */
/*********************************************************/

# ifdef __APPLE__
/* Upper Row */
#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_E 14
#  define KEY_R 15
#  define KEY_T 16
#  define KEY_Y 17
#  define KEY_U 32
#  define KEY_I 34
#  define KEY_O 31
#  define KEY_P 35

/* Middle Row */
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_F 3
#  define KEY_G 5
#  define KEY_H 4
#  define KEY_J 38
#  define KEY_K 40
#  define KEY_L 37

/* Lower Row */
#  define KEY_Z 6
#  define KEY_X 7
#  define KEY_C 8
#  define KEY_V 9
#  define KEY_B 11
#  define KEY_N 45
#  define KEY_M 46

/* Symbols */
#  define KEY_BRACKET_IN 33
#  define KEY_BRACKET_OUT 30
#  define KEY_BACKSLASH 42
#  define KEY_SEMISILICON 41
#  define KEY_QUOTES 39
#  define KEY_SILICON 34
#  define KEY_DOT 47
#  define KEY_SLASH 44
#  define KEY_TILD 50

/* Numbers (Top) */
#  define KEY_TOP_1 18
#  define KEY_TOP_2 19
#  define KEY_TOP_3 20
#  define KEY_TOP_4 21
#  define KEY_TOP_5 23
#  define KEY_TOP_6 22
#  define KEY_TOP_7 26
#  define KEY_TOP_8 28
#  define KEY_TOP_9 25
#  define KEY_TOP_0 29
#  define KEY_TOP_MINUS 27
#  define KEY_TOP_PLUS 24

/* Numbers (Numpad) */
#  define KEY_NUMPAD_0 82
#  define KEY_NUMPAD_1 83
#  define KEY_NUMPAD_2 84
#  define KEY_NUMPAD_3 85
#  define KEY_NUMPAD_4 86
#  define KEY_NUMPAD_5 87
#  define KEY_NUMPAD_6 88
#  define KEY_NUMPAD_7 89
#  define KEY_NUMPAD_8 91
#  define KEY_NUMPAD_9 92
#  define KEY_NUMPAD_MULTI 67
#  define KEY_NUMPAD_DIV 75
#  define KEY_NUMPAD_MINUS 78
#  define KEY_NUMPAD_PLUS 69
#  define KEY_NUMPAD_EQUAL 81
#  define KEY_NUMPAD_DOT 65
#  define KEY_NUMPAD_CLEAR 71

/* Controls */
#  define KEY_ENTER 76
#  define KEY_RETURN 36
#  define KEY_SPACE 49
#  define KEY_CTRL_L 59
#  define KEY_CTRL_R 62
#  define KEY_CMD 55
#  define KEY_OPTION_L 58
#  define KEY_OPTION_R 61
#  define KEY_FN 63
#  define KEY_SHIFT_L 57
#  define KEY_SHIFT_R 60
#  define KEY_CAPSLOCK 57
#  define KEY_TAB 48
#  define KEY_DELETE 51
#  define KEY_ESC 53

/* Movements */
#  define KEY_ARROW_UP 126
#  define KEY_ARROW_LEFT 123
#  define KEY_ARROW_DOWN 125
#  define KEY_ARROW_RIGHT 124
#  define KEY_PAGE_UP 116
#  define KEY_PAGE_DOWN 121
#  define KEY_HOME 115
#  define KEY_END 119

/* Functions */
#  define KEY_F1 122
#  define KEY_F2 120
#  define KEY_F3 99
#  define KEY_F4 118
#  define KEY_F5 96
#  define KEY_F6 97
#  define KEY_F7 98
#  define KEY_F8 100
#  define KEY_F9 101
#  define KEY_F10 109
#  define KEY_F11 103
#  define KEY_F12 111
#  define KEY_F13 105
#  define KEY_F14 107
#  define KEY_F15 113
#  define KEY_F16 106
#  define KEY_F17 64
#  define KEY_F18 79
#  define KEY_F19 80
#  define KEY_F20 90
# endif

/*********************************************************/
/*                                                       */
/*                QUICK TYPES DEFINITIONS                */
/*        For faster and more comprehensible code        */
/*                                                       */
/*********************************************************/

typedef unsigned int	t_uint;
typedef unsigned char	t_byte;
typedef int				t_bool;

#endif
