/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcollar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:10:15 by flcollar          #+#    #+#             */
/*   Updated: 2022/04/06 20:01:31 by flcollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_getaddress(void *p)
{
	char	*temp;
	char	*str;

	temp = ft_ptr2base(p, HEXA_LOW);
	str = ft_strjoin("0x", temp);
	ft_free_multi(temp, 0);
	return (str);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -sign;
	result = 0;
	while (ft_isdigit(str[i]))
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}

char	**ft_list2array(t_list *lst)
{
	char	**res;
	t_list	*current;
	size_t	i;

	if (!lst)
		return (0);
	res = (char **) malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	if (!res)
		return (0);
	i = 0;
	current = lst;
	while (current)
	{
		res[i] = ft_strdup(current->content);
		if (!res[i])
			return ((char **) ft_free_array((void **) res, i));
		current = current->next;
		i++;
	}
	return (res);
}
