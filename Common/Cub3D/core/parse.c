/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:02:48 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/30 14:47:08 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

char	*cb_normline(char *line, int maxlen)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(*tmp) * (maxlen + 2));
	if (!tmp)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		tmp[i] = line[i];
		i++;
	}
	while (i < maxlen)
		tmp[i++] = ' ';
	tmp[i++] = '\n';
	tmp[i] = '\0';
	free(line);
	return (tmp);
}

int	cb_normalize(char **map)
{
	unsigned int	i;
	unsigned int	maxlen;

	i = -1;
	maxlen = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > maxlen)
			maxlen = ft_strlen(map[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) < maxlen)
		{
			map[i] = cb_normline(map[i], maxlen);
			if (!map[i])
				return (1);
		}
		i++;
	}
	return (0);
}

static char	*cb_parsemap_extension(int fd, t_cub *cub)
{
	char	*line;

	line = get_next_line(fd);
	while (line && cb_isparamline(line))
	{
		if (!cb_isspaceline(line))
			if (cb_setparam(line, cub))
				ft_error(2);
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	cb_parsemap(char *path, t_cub *cub, int fd, char *line)
{
	char	**map;

	fd = open(path, O_RDONLY);
	if (!ft_endswith(path, ".cub") || fd == -1)
		ft_error(1);
	line = cb_parsemap_extension(fd, cub);
	if (!cub->no || !cub->so || !cub->ea
		|| !cub->we || cub->c_col == -1 || cub->f_col == -1)
		ft_error(3);
	map = NULL;
	while (line)
	{
		if (!cb_ismapline(line))
			ft_error(4);
		map = ms_appendtoarr(map, line);
		line = get_next_line(fd);
	}
	if (!map)
		ft_error(4);
	if (cb_normalize(map))
		ft_error(3);
	cub -> map = map;
	if (check_map(cub, ft_vector2_new(0, 0), ft_vector2_new(0, 0)))
		ft_error(4);
	cb_setxy(cub);
}
