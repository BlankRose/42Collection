/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:43:07 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/17 21:38:52 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "../libft.h"

/*********************************************************/
/*                                                       */
/*                  CHARACTER TESTINGS                   */
/*      Functions for testing specifics characters       */
/*                                                       */
/*********************************************************/

/* Test if C is a lower case character
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_islower(int c);

/* Test if C is an upper case character
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_isupper(int c);

/* Test if C is alphabetic
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_isalpha(int c);

/* Test if C is digital
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_isdigit(int c);

/* Test if C is alphanumeric
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_isalnum(int c);

/* Test if C is part of the ASCII table
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_isascii(int c);

/* Test if C is printable
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_isprint(int c);

/* Test if C is a whitespace
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_isspace(int c);

/* Test if C is a sign positive or negative
Return: 1 (POSITIVE) or 0 (FALSE) or -1 (NEGATIVE) */
int			ft_issign(int c);

/* Test if C reprensents a valid number
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_isnum(char *c);

/* Test if C exist within a definied SET 
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_isset(int c, const char *set);

/* Test if STR contains any character existing within a definied SET
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_contains(const char *str, const char *set);

/* Test if STR starts with the string S
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_startswith(const char *str, const char *s);

/* Test if STR ends with the string S
Return: 1 (TRUE) or 0 (FALSE) */
int			ft_endswith(const char *str, const char *s);

/*********************************************************/
/*                                                       */
/*                  CHARACTERS FINDER                    */
/*       Functions to locate specifics characters        */
/*                                                       */
/*********************************************************/

/* Counts how many times C apears in the string S
Return: number of times C was found */
size_t		ft_strnchr(const char *s, int c);

/* Locates the first C in the string S
Return: address of first C found */
char		*ft_strchr(const char *s, int c);

/* Locates the last C in the string S
Return: address of last C found */
char		*ft_strrchr(const char *s, int c);

/* Counts how many times NEEDLE appears in string STR within LEN characters
Return: number of times NEEDLE was found */
char		*ft_strnstr(const char *str, const char *needle, size_t len);

/* Locates the first occurance of NEEDLE in string STR within LEN character
Return: address of NEEDLE's first character found */
size_t		ft_strlstr(const char *str, const char *needle, size_t len);

/* Converts the lowercase C into its uppercase variant
Return: uppercase variant of C if it exists */
int			ft_toupper(int c);

/* Converts the uppercase C into its lowercase variant
Return: lowercase variant of C if it exists */
int			ft_tolower(int c);

/*********************************************************/
/*                                                       */
/*                 STRING MANIPULATIONS                  */
/*      Functions to modify strings in various ways      */
/*                                                       */
/*********************************************************/

/* Copies DSTSIZE characters of the string SRC into DST
Return: length of the string it tried to create */
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

/* Copies DSTSIZE characters of the string SRC into DST
Return: length of the string it tried to create */
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

/* Check the length of the string S
Return: length of S */
size_t		ft_strlen(const char *s);

/* Check the length of the string S before the character C appears
Return: length of S */
size_t		ft_strlenlimit(const char *s, char c);

/* Check the length of the string S before the character C disappears
Return: length of S */
size_t		ft_strlenlimitrev(const char *s, char c);

/* Check the length of the string S before any specified characters in
SET appears
Return: length of S */
size_t		ft_strlenlimitset(const char *s, char *set);

/* Check the length of the string S before any specified characters in
SET disapears
Return: length of S */
size_t		ft_strlenlimitsetrev(const char *s, char *set);

/* Compare the strings S1 and S2 within N characters
Return: difference between S1 and S2 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/* Create a clone of the char C (usually for char to string usage)
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char		*ft_chrdup(const char c);

/* Create a clone of the string S1
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char		*ft_strdup(const char *s1);

/* Create a clone of the string S1, starting at index START and limits at
LEN characters
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char		*ft_substr(const char *s, unsigned int start, size_t len);

/* Joins togheter the strings S1 and S2 into a new string
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() ! */
char		*ft_strjoin(const char *s1, const char *s2);

/* Joins togheter multiple strings into a new string
Return: newly created string or NULL if allocation failed
CAUTION: Should end with NULL string !
REQUIERD: malloc(), free() and va_arg() !*/
char		*ft_strjoin_multi(const char *base, ...);

/* Create a clone of the string S1, but removes every characters in SET at
the beginning and the end of the string
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char		*ft_strtrim(const char *s1, const char *set);

/* Splits the string S into a table, using C as a seperator
Return: newly created table of strings or NULL if allocation failed
REQUIERD: malloc() and free() !*/
char		**ft_split(const char *s, char c);

/* Apply a function F() to every characters of a string S */
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/* Clone the string S and apply the function F() on every characters
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/* A simple converters which uses the first character of SRC and converts
ARGS to their corresponding conversions sets by SRC
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() and va_arg() !*/
char		*ft_convert(const char *src, va_list *args);

/* A function that creates a new string out of S, using some converters
Return: newly created string or NULL if allocations failed
REQUIERD: malloc(), free(), write() and va_arg() !*/
char		*ft_strconvert(const char *s, ...);

/*********************************************************/
/*                                                       */
/*                     MATHEMATICS                       */
/*       Functions to help solving maths problems        */
/*                                                       */
/*********************************************************/

/* Generates a new array of INTs containing all numbers between
the specified MIN and MAX included.
Return: newly created array of INTs
REQUIERD: malloc() !*/
int			*ft_range(int min, int max);

/* Generates a new array of INTs containing all numbers between
the specified MIN and MAX included in the reversed order
Return: newly created array of INTs
REQUIERD: malloc() !*/
int			*ft_rangerev(int min, int max);

/* Generates a new array of a single INT, containing NBR
Return: newly created array of INT
REQUIERD: malloc() !*/
int			*ft_rangeone(int nbr);

/* Generates a new array of INTs, containing every content of LST
Return: newly created array of INTs
REQUIERD: malloc() !*/
int			*ft_lst2range(t_list *lst);

/* Check the length of the number X but allows massive numbers
Return: length of X */
size_t		ft_nbrlen_long(unsigned long long x);

/* Check the length of the number X
Return: length of X */
size_t		ft_nbrlen(unsigned int x);

/* Check the length of the number X within the size of another BASE
Return: length of X in BASE */
size_t		ft_nbrlen_base(unsigned long long x, size_t base);

/* Limits the number X in a range between MIN and MAX
Return: MIN or X or MAX */
int			ft_clamp(int x, int min, int max);

/* Limits the number X in a range between MIN and inf
Return: MIN or X */
int			ft_min(int x, int min);

/* Limits the number X in a range between -inf and MAX
Return: X or MAX */
int			ft_max(int x, int max);

/* Calculates N to the power of POW
Return: Result of N ^ POW */
int			ft_power(int n, int pow);

/* Find the Greatest Common Divider between X and Y
Return: found value */
t_uint		ft_get_gcd(int x, int y);

/* Checks wether the string N could overflow within an 'int'
Return: TRUE (1) or FALSE (0) */
int			ft_intoverflow(char *n);

/* Checks wether the string N could overflow within an 'long long'
Return: TRUE (1) or FALSE (0) */
int			ft_longoverflow(char *n);

/*********************************************************/
/*                                                       */
/*                      CONVERTERS                       */
/*   Functions to convert various things into anything   */
/*                                                       */
/*********************************************************/

/* Interpret and converts the number N into a string
Return : string counterpart found
REQUIERD: malloc() !*/
char		*ft_itoa(int n);

/* Interpret and converts the string STR into an int
Return: number counterpart found */
int			ft_atoi(const char *str);

/* Interpret and converts the number N into a string but allows massive numbers
Return : string counterpart found
REQUIERD: malloc() !*/
char		*ft_itoa_long(long long n);

/* Interpret and converts the unsigned number N into a string
Return : string counterpart found
REQUIERD: malloc() !*/
char		*ft_itoa_unsigned(unsigned int n);

/* Interpret and converts the unsigned number N into a string but
allows massive numbers
Return : string counterpart found
REQUIERD: malloc() !*/
char		*ft_itoa_unsigned_long(unsigned long long n);

/* Check if the BASE is valid (no whitespaces, no signs, no doubles)
Return: length of BASE or 0 if invalid base */
size_t		ft_checkbase(char *base);

/* Convert the string S from a BASE to a decimal base
Return: converted string or 0 if invalid base */
t_uint		ft_base2dec(char *s, char *base);

/* Convert the number S from a decimal base to a BASE
Return: converted number or NULL if allocation failed or invalid base
REQUIERD: malloc() !*/
char		*ft_dec2base(unsigned int n, char *base);

/* Convert the pointer X from a decimal base to a BASE
Return: converted pointer or NULL if allocation failed or invalid base
REQUIERD: malloc() !*/
char		*ft_ptr2base(void *x, char *base);

/* Convert the string S from the base B1 to the base B2
Return: converted string or NULL if allocation failed or invalid bases
REQUIERD: malloc() and free() !*/
char		*ft_base2base(char *s, char *b1, char *b2);

/* Convert C into a 8-bits representative string 
Return: Newly created string or NULL if allocation failed
REQUIERD: malloc() !*/
char		*ft_byte2binary(t_byte c);

/* Converts the 8-bits representation string S into its
corresponding byte value
Return: Unsigned char found */
t_byte		ft_binary2byte(char *s);

/*********************************************************/
/*                                                       */
/*                  DATA MANIPULATIONS                   */
/*           Functions to handle easily data             */
/*                                                       */
/*********************************************************/

/* Creates a new color structure with specified color tones
Return: newly created color struct */
t_color		ft_color_new(int a, int r, int g, int b);

/* Creates a new vector 3 structure with specified coordinates
Return: newly created vector3 */
t_vector3	ft_vector3_new(int x, int y, int z);

/* Creates a new vector 2 structure with specified coordinates
Return: newly created vector2 */
t_vector2	ft_vector2_new(int x, int y);

/* Quickly sorts an ARRAY of N ints */
void		ft_sort_array(int *array, size_t n);

/* Creates a new list structure, initialized with CONTENT
Return: newly created list
REQUIERD: malloc() !*/
t_list		*ft_lstnew(void *content);

/* Duplicates LST, using the function F to duplicate its content
Return: newly created list
REQUIERD: malloc() !*/
t_list		*ft_lstdup(t_list *lst, void *(*f) (void *));

/* Fetch the last list content from the chain LST
Return: address of last list */
t_list		*ft_lstlast(t_list *lst);

/* Creates a list of N entries based of an ARRAY. Setting N to 0 will
cause to keep on creating lists until it find a NULL value
Return: newly created list
REQUIERD: malloc() !*/
t_list		*ft_array2lst(void **array, size_t n);

/* Locate the list structure in LST at index N
Return: located LST or NULL if none exists */
t_list		*ft_lstlocate(t_list *lst, size_t n);

/* Count the amount of content in the chained list LST
Return: length of LST */
size_t		ft_lstsize(t_list *lst);

/* Add the NEW list in the chained list LST at first position 
and pass the pointer LST back to NEW */
void		ft_lstadd_front(t_list **lst, t_list *new);

/* Add the NEW list in the chained list LST at last position */
void		ft_lstadd_back(t_list **lst, t_list *new);

/* Iterates accross a list, starting fron LST and apply a function F
on each content */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/* Iterates accross a list, starting from LST and apply a function F
on each content, with PARAM passed as its argument aswell */
void		ft_lstiter_arg(t_list *lst, void (*f)(void *, void *), void *param);

/* Create a new chained list out of the list LST and apply the function F
on each content (uses the function DEL if needed) 
Return: newly created list
REQUIERD: malloc() !*/
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* Create a new chained list out of the list LST and apply the function F on
each content (uses the function DEL if needed), with PARAM passed as its argument
Return: newly created list
REQUIERD: malloc() !*/
t_list		*ft_lstmap_arg(t_list *lst, void *(*f)(void *, void *),
				void (*del)(void *), void *param);

/* Update the content of LST by using DEL to clear its old content and
remplaces it with the NEW content */
void		ft_lstupdate(t_list *lst, void (*del)(void *), void *new);

/* Clear the element LST using the function DEL to clear its content properly
REQUIERD: free() !*/
void		ft_lstdelone(t_list *lst, void (*del)(void*));

/* Clear the whole list LST using the function DEL to clear its content properly
REQUIERD: free() !*/
void		ft_lstclear(t_list **lst, void (*del)(void*));

/*********************************************************/
/*                                                       */
/*                 MEMORY MANIPULATIONS                  */
/*          Functions to modify raw memory bits          */
/*                                                       */
/*********************************************************/

/* Check the length of the memory S
Return: length of S */
size_t		ft_memlen(const void *s);

/* Change LEN octets of given data B with data C
Return: modified data B */
void		*ft_memset(void *b, int c, size_t len);

/* Copy N octets from data SRC to DST
Return: modifed data DST */
void		*ft_memcpy(void *dst, const void *src, size_t n);

/* Move N octets from data SRC to DST
Return: modified data DST */
void		*ft_memmove(void *dst, const void *src, size_t len);

/* Duplicates the memory MEM
Return: newly created memory or NULL if allocation failed
REQUIERD: malloc () !*/
void		*ft_memdup(void *mem);

/* Locates data C within data S in the N first octets
Return: address of C found */
void		*ft_memchr(const void *s, int c, size_t n);

/* Replace N octets in data S with 0 */
void		ft_bzero(void *s, size_t n);

/* Compare N octets of datas S1 and S2
Return: difference between S1 and S2 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/* Allocate SIZE * COUNT memory and initialize eveything at 0
Return: allocated memory or NULL if allocation failed
REQUIERD: malloc() !*/
void		*ft_calloc(size_t count, size_t size);

/* Extend the memory PREV by allocating a new and wider memory slot by N bytes
and free the old one
Return: newly created memory or NULL if allocation failed
REQUIERD: malloc() and free() !*/
void		*ft_realloc(void *prev, size_t n);

/* Extends the memory PREV by allocating a new and wider memory slot to fit
TMP within PREV and free PREV and free TMP aswell if ISFREE is TRUE
Return: newly created string or NULL if allocation failed
REQUIERD: malloc() and free() !*/
char		*ft_strexpend(char *prev, char *tmp, t_bool isfree);

/* Catch the address of the point P
Return: address as a string or NULL if allocation failed
REQUIERD: malloc() !*/
char		*ft_getaddress(void *p);

/* Allows to free multiples strings at once
Return: NULL
REQUIERD: free() !*/
void		*ft_free_multi(void *s1, void *s2);

/* Allows to free multiples N strings of an ARRAY of strings
Return: NULL
REQUIERD: free() !*/
void		**ft_free_array(void **array, size_t n);

/* Check the length of the ARRAY
Return: length of ARRAY */
size_t		ft_array_len(void **array);

/*********************************************************/
/*                                                       */
/*                  IN & OUT HANDLER                     */
/*  Functions to handle programme's inputs and outputs   */
/*                                                       */
/*********************************************************/

/* Fetch the next line on the file FD
Return: string which contains the line
REQUIERD: malloc(), free() and read() !*/
char		*get_next_line(int fd);

/* Fetch every lines on the file FD
Return: table containing every lines converted into strings
REQUIERD: malloc(), free() and read() !*/
t_list		*get_all_lines(int fd);

/* Print out a single character C, in a specified output/file FD
Return: amount of characters written
REQUIERD: write() !*/
size_t		ft_putchar_fd(char c, int fd);

/* Print out the string S in a specified output/file FD
Return: amount of characters written
REQUIERD: write() !*/
size_t		ft_putstr_fd(char *s, int fd);

/* Print out the string S and add a new line in a specified output/file FD
Return: amount of characters written
REQUIERD: write() !*/
size_t		ft_putendl_fd(char *s, int fd);

/* Print out the number N in a specified output/file FD
Return: amount of characters written
REQUIERD: write() !*/
size_t		ft_putnbr_fd(int n, int fd);

/* Print out the string S in a specified output/file FD
Return: amount of characters written
REQUIERD: write() !*/
size_t		ft_putnstr_fd(const char *s, int fd, size_t n);

/* Print out the string S to the output FD, and converts using various flags
Return: amount of caracters printed or -1 if an error occured
REQUIERD: malloc(), free(), write() and va_arg() !*/
int			ft_printf(int fd, const char *s, ...);

/* Print out the whole LST to the output FD, using SEP to seperate each
each output
Return: amount of characters written
REQUIERD: write() !*/
int			ft_printlst(int fd, const t_list *lst, const char *sep);

#endif
