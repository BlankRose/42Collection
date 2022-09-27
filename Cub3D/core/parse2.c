/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:02:52 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 14:48:07 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	cb_setxy(t_cub *cub)
{
	char	**map;
	int		y;

	map = cub -> map;
	y = 0;
	if (!map)
		return ;
	while (map[y])
		y++;
	cub -> mapy = y;
	if (!(map[0]))
		return ;
	cub -> mapx = ft_strlen(map[0]);
}

char	**ms_appendtoarr(char **arr, char *str)
{
	char	**tmp;
	int		i;
	int		len;

	len = cb_arraylen(arr);
	tmp = malloc(sizeof(*tmp) * (len + 2));
	i = 0;
	while (arr && arr[i])
	{
		tmp[i] = arr[i];
		i++;
	}
	tmp[i++] = str;
	tmp[i] = NULL;
	if (arr)
		free(arr);
	return (tmp);
}

int	cb_ismapline(char *line)
{
	int	i;
	int	pos;
	int	space;

	space = 1;
	pos = 0;
	i = -1;
	while (line[++i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line [i] == 'S'\
			|| line[i] == 'E' || line[i] == 'W' )
			pos++;
		else if (!(line[i] == ' ' || line[i] == '0' || line[i] == '1'))
			return (0);
	}
	if (pos > 1)
		return (0);
	return (1);
}

static void	cb_setparam_extension(char **args, t_cub *cub)
{
	if (!ft_strncmp(args[0], "NO", 3))
		cub -> no = cb_load_asset(cub, ft_substr(args[1], 0, \
		ft_strlenlimit(args[1], '\n')));
	if (!ft_strncmp(args[0], "EA", 3))
		cub -> ea = cb_load_asset(cub, ft_substr(args[1], 0, \
		ft_strlenlimit(args[1], '\n')));
	if (!ft_strncmp(args[0], "SO", 3))
		cub -> so = cb_load_asset(cub, ft_substr(args[1], 0, \
		ft_strlenlimit(args[1], '\n')));
	if (!ft_strncmp(args[0], "WE", 3))
		cub -> we = cb_load_asset(cub, ft_substr(args[1], 0, \
		ft_strlenlimit(args[1], '\n')));
	if (!ft_strncmp(args[0], "F", 2))
		cub -> f_col = cb_setcolor(ft_strdup(args[1]), 0, 0, 0);
	if (!ft_strncmp(args[0], "C", 2))
		cub -> c_col = cb_setcolor(ft_strdup(args[1]), 0, 0, 0);
}

int	cb_setparam(char *line, t_cub *cub)
{
	char	**args;

	args = ft_split(line, ' ');
	if ((!ft_strncmp(args[0], "NO", 3) && cub -> no) || (!ft_strncmp(args[0], \
		"SO", 3) && cub -> so) || (!ft_strncmp(args[0], "EA", 3) && cub -> ea) \
		|| (!ft_strncmp(args[0], "WE", 3) && cub -> we) || (!ft_strncmp(\
		args[0], "F", 2) && cub -> f_col) || (!ft_strncmp(args[0], "C", 2) \
		&& cub -> c_col))
	{
		ft_freemem(args);
		return (1);
	}
	cb_setparam_extension(args, cub);
	ft_freemem(args);
	return (0);
}
