/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:44:41 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/15 20:05:21 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/*********************************************************/
/*                                                       */
/*                      STRUCTURES                       */
/*    Various structures for easier variable handling    */
/*                                                       */
/*********************************************************/

/* Color structure for specifying colors (Alpha, Red, Green, Blue)
Variables: (unsigned char) a, r, g, b */
typedef struct s_color {
	t_byte	a;
	t_byte	r;
	t_byte	g;
	t_byte	b;
}	t_color;

/* Vector 3 structure for 3D coordinates
Variables: (int) x, y, z */
typedef struct s_vector3 {
	int		x;
	int		y;
	int		z;
}	t_vector3;

/* Vector 2 structure for 2D coordinates
Variables: (int) x, y */
typedef struct s_vector2 {
	int		x;
	int		y;
}	t_vector2;

/* Chained list structure
Variables: (void*) content, (s_list*) next */
typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

/* Binary tree structure
Variables: (void*) content, (s_btree*) left, right */
typedef struct s_btree {
	void			*content;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

#endif
