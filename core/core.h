/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:35 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/13 18:22:28 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

/*********************************************************/
/*                                                       */
/*                    LIBRARY INCLUDES                   */
/*     Every includes prefined by the library itself     */
/*                                                       */
/*********************************************************/

# include "../libft/libft.h"
# include "../pipexx/pipex.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

/*********************************************************/
/*                                                       */
/*                      STRUCTURES                       */
/*    Various structures for easier variable handling    */
/*                                                       */
/*********************************************************/

typedef struct s_main {
	int		exit;
	int		fds[2];
	char	**envp;
	char	*prompt_msg;
}	t_main;

/*********************************************************/
/*                                                       */
/*                   PROGRAMM FUNCTIONS                  */
/*    Specifics functions to run properly the program    */
/*                                                       */
/*********************************************************/

/* Handles a signal SIG, with its INFO and CONTEXT */
void	ms_signal_handler(int sig, siginfo_t *info, void *context);

/* Duplicates the whole ARRAY of chars
Return: newly created array */
char	**ms_array_cpy(char **arr);

/* Finds the length of the ARRAY
Return: length of ARRAY */
int		ms_arraylen(char **arr);

/* Converts the ARRAY into a list
Return: newly created list */
t_list	*ms_arrtolist(char **arr);

/* Gets a new prompt ready */
void	ms_prompt_new(t_main *main);

#endif