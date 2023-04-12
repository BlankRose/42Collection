/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Framework.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <flcollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:10:24 by flcollar          #+#    #+#             */
/*   Updated: 2023/03/23 16:51:51 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAMEWORK_H
# define FRAMEWORK_H

# include "Assets.h"
# include "more_types.h"

typedef struct s_Framework	t_fw;

t_fw	*new_framework(void);
t_fw	*del_framework(t_fw *this);

/**
 * Framework Class, which handles MLX main stuff
 * */
struct s_Framework
{
	void		*mlx;
	void		*win;
	t_int32		win_length;
	t_int32		win_height;

	int			(*new_window)(t_fw *, t_int32, t_int32, t_string);
	void		(*put_tile)(t_fw *, t_img *, t_int32, t_int32);
	void		(*clear_tile)(t_fw *);
};

#endif /* FRAMEWORK_H */