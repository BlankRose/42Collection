/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:21:47 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/10 15:43:32 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*********************************************************/
/*                                                       */
/*                      STRUCTURES                       */
/*    Various structures for easier variable handling    */
/*                                                       */
/*********************************************************/

/* A structure to store information about stacks */
typedef struct s_info{
	size_t		size;
	int			value_min;
	int			value_max;
}	t_info;

/*********************************************************/
/*                                                       */
/*               ALGORYTHMES SORTING RULES               */
/*    Functions to handle programme's specifics rules    */
/*                                                       */
/*********************************************************/

/* Swap the first 2 elements at the top of stack A.
Do nothing if there is only one or no elements. */
void	ps_swap_a(t_list **a);

/* Swap the first 2 elements at the top of stack B.
Do nothing if there is only one or no elements. */
void	ps_swap_b(t_list **b);

/* Swap the first 2 elements at the top for both stacks A and B.
Do nothing if there is only one or no elements.
NOTE: equivalent to swap_a and swap_b */
void	ps_swap_s(t_list **a, t_list **b);

/* Take the first element at the top of B and put it at the top of A.
Do nothing if B is empty. */
void	ps_push_a(t_list **a, t_list **b);

/* Take the first element at the top of A and put it at the top of B.
Do nothing if A is empty. */
void	ps_push_b(t_list **a, t_list **b);

/* Shift up all elements of stack A by 1.
The first element becomes the last one. */
void	ps_rotate_a(t_list **a);

/* Shift up all elements of stack B by 1.
The first element becomes the last one. */
void	ps_rotate_b(t_list **b);

/* Shift up all elements of stacks A and B by 1.
The first element becomes the last one.
NOTE: equivalent to rotate_a and rotate_b */
void	ps_rotate_r(t_list **a, t_list **b);

/* Shift down all elements of stack A by 1.
The last element becomes the first one. */
void	ps_rotate_ra(t_list **a);

/* Shift down all elements of stack B by 1.
The last element becomes the first one. */
void	ps_rotate_rb(t_list **b);

/* Shift up all elements of stacks A and B by 1.
The last element becomes the first one.
NOTE: equivalent to rotate_a and rotate_b */
void	ps_rotate_rr(t_list **a, t_list **b);

/*********************************************************/
/*                                                       */
/*                   PROGRAMM FUNCTIONS                  */
/*    Specifics functions to run properly the program    */
/*                                                       */
/*********************************************************/

/* Initialize a 't_info' struct to 0
Return: t_info set to 0 */
t_info	ps_data_init(t_list **stack);

/* Sorts large stack A, using the secondary stack B and DATA */
void	ps_sort_big(t_list **a, t_list **b, t_info *data);

/* Sorts small stack A, using the secondary stack B and DATA */
void	ps_sort_small(t_list **a, t_list **b, t_info *data);

/* Checks if the STACK is sorted
Return: 1 (TRUE) or 0 (FALSE) */
t_bool	ps_issorted(t_list **stack);

/* Checks wether the VALUE is closer to the top of the STACK or
closer to the lowest
Return: 1 (TOP) or 0 (LOW) */
int		ps_get_closest(t_list **stack, int value);

/* Sorts the ARGS and stores them in the STACK
Return: STACK */
t_list	**ps_args_handler(int c, char **args, t_list **stack);

/* Converts the STACK into their respective index */
void	ps_pre_emptive(t_list **stack);

/* Starts sorting the stacks A and B accordingly to the subject
given for this project */
void	ps_sorting_init(t_list **a, t_list **b);

#endif