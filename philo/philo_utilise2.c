/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utilise2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:54:45 by aennaouh          #+#    #+#             */
/*   Updated: 2023/06/21 15:43:49 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_data	*ft_lstnew(int content)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_data **lst, t_data *new)
{
	t_data	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = new;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != *lst)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
		new->next = *lst;
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *) malloc(count * (size));
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
