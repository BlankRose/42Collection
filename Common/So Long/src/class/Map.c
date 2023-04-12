/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:09:12 by flcollar          #+#    #+#             */
/*   Updated: 2023/04/12 14:04:06 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.h"

#include <stdlib.h>
#include <fcntl.h>

int		sl_error(int err, t_string extra);
int		sl_check_map(t_map *map);

/**
 * Loads the entire map correctly and returns it
 * 
 * @warning		May returns NULL if OPEN or GNL failed!
 * */
t_list	*load_map(t_map *this, t_string path)
{
	t_list	*lst;
	int		fd;

	if (!this)
		return (NULL);
	this->unload_map(this);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (sl_error(2, path), NULL);
	lst = get_all_lines(fd);
	close(fd);
	if (!lst)
		return (sl_error(2, path), NULL);
	this->data = lst;
	this->name = path;
	this->player = new_vector3_param(0, 0, 0);
	if (sl_check_map(this))
		return (this->unload_map(this), NULL);
	return (lst);
}

/**
 * Clears the current stored map data loaded if any
 * */
void	unload_map(t_map *this)
{
	if (!this)
		return ;
	if (this->data)
		ft_lstclear(&this->data, free);
	if (this->player)
		this->player = del_vector3(this->player);
	this->data = NULL;
	this->length = 0;
	this->height = 0;
	this->frame = 0;
	this->moves = 0;
	this->items = 0;
	this->entry = 0;
	this->exit = 0;
	this->verify = ft_vector2_new(0, 0);
}

/**
 * Default Constructor
 * */
t_map	*new_map(void)
{
	t_map	*this;

	this = malloc(sizeof(t_map));
	if (!this)
		return (NULL);
	this->data = NULL;
	this->name = NULL;
	this->height = 0;
	this->length = 0;
	this->items = 0;
	this->entry = 0;
	this->exit = 0;
	this->verify = ft_vector2_new(0, 0);
	this->player = NULL;
	this->load_map = load_map;
	this->unload_map = unload_map;
	return (this);
}

/**
 * Destructor
 * */
t_map	*del_map(t_map *this)
{
	if (!this)
		return (NULL);
	this->unload_map(this);
	free(this);
	return (NULL);
}
