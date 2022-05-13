/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:16:35 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/12 17:17:36 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "../libft/libft.h"
# include "../pipexx/pipex.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_main
{
    int exit;
    int fds[2];

    char **envp;

}   t_main;

#endif