/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   LibASM - libasm.h                               */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Apr 13 18:41:40 CEST 2023     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __LIBASM__
# define __LIBASM__

# include <sys/_types/_size_t.h>
# include <sys/errno.h>

// STRUCTURES

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

// MANDATORY

extern int		ft_read(int fd, void * buffer, size_t size);
extern int		ft_write(int fd, const void * buffer, size_t size);

extern size_t	ft_strlen(const char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char *	ft_strcpy(char *dest, const char *src);
extern char *	ft_strdup(const char *src);

// ADDITIONAL

extern int		ft_contains(const char *base, char target);
extern t_list *	ft_list_new(void *data);

// BONUS

extern int		ft_atoi_base(const char *str, const char *base);
extern void		ft_list_push_front(t_list **begin, void *data);
extern void		ft_list_remove_if(t_list **begin, void *ref, int (*cmp)(), void (*del)(void *));
extern void		ft_list_sort(t_list **begin, int (*cmp)());
extern int		ft_list_size(t_list *begin);

#endif /* __LIBASM__ */