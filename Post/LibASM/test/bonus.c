/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   LibASM - bonus.c                                */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Apr 13 18:43:18 CEST 2023     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "tools.h"

static void		print_list(t_list *begin)
{
	printf("\n=== PRINTING LIST ===\n");

	t_list *	tmp;
	for (t_list * cur = begin; cur; cur = tmp)
	{
		tmp = cur->next;
		printf("\nCURRENT = %p\n", cur);
		printf("NEXT = %p\n", cur->next);
		printf("DATA = %p\n", cur->data);
		if (cur->data)
			printf(" | VALUE = %d\n", *(int *)(cur->data));
		printf("REMAINING = %d\n", ft_list_size(cur) - 1);
	}
}

static void		destroy_list(t_list **begin)
{
	t_list *	tmp;
	for (t_list *cur = *begin; cur; cur = tmp)
	{
		tmp = cur->next;
		free(cur);
	}
	*begin = NULL;
}

t_list *	test_insert(void)
{
	t_list *	lst = NULL;
	int			a = 5, b = 42, c = -45613;

	lst = ft_list_new(NULL);
	ft_list_push_front(&lst, NULL);
	ft_list_push_front(&lst, NULL);
	ft_list_push_front(&lst, NULL);

	print_list(lst);
	return lst;
}

static int	is_empty(void *src)
{
	if (!src)
		return 0;
	return 1;
}

static int	cmp(void *src, void *other)
{
	if (*(int *) src == *(int *) other)
		return 0;
	return 1;
}

static void	set(void *i)
{
	*(int *) i = 45;
}

void	test_destroy(t_list **lst)
{
	printf("\nSuppresing NULL data...\n");
	ft_list_remove_if(lst, NULL, is_empty, NULL);
	print_list(*lst);
	destroy_list(lst);

	int		a = 5;
	ft_list_push_front(lst, &a);
	print_list(*lst);
	ft_list_remove_if(lst, &a, cmp, set);
	print_list(*lst);
	destroy_list(lst);
	printf("Final Value: %d\n", a);
}

void	test_atoi(void)
{
	int		i = ft_atoi_base("53F", "XX");
	printf("A: %d\n", i);

	i = ft_atoi_base("53F", "0123456789ABCDEF");
	printf("B: %d\n", i);

	i = ft_atoi_base("FFF", "F");
	printf("C: %d\n", i);

	i = ft_atoi_base("53F", "53XX");
	printf("D: %d\n", i);

	i = ft_atoi_base("-53F", "0123456789ABCDEF");
	printf("E: %d\n", i);

	i = ft_atoi_base("-53F", "0123456789");
	printf("F: %d\n", i);
}
