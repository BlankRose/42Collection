/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 20:08:45 by flcollar          #+#    #+#             */
/*   Updated: 2022/05/15 20:16:48 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_btree_delone(t_btree *tree, void del(void *))
{
	if (!tree)
		return ;
	if (del)
		del(tree->content);
	free(tree);
}

void	ft_btree_clear(t_btree **tree, void del(void *))
{
	t_btree		*current;

	if (!tree)
		return ;
	while (!(*tree))
	{
		current = *tree;
		while (!current->right && !current->left)
		{
			if (current->left)
				current = current->left;
			else
				current = current->right;
		}
		ft_btree_delone(current, del);
	}
	*tree = 0;
}
