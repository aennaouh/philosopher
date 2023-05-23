/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utilise1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:36:56 by aennaouh          #+#    #+#             */
/*   Updated: 2023/05/22 18:19:43 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	ft_words(char *s, char c)
{
	int	i;
	int	nw;

	i = 0;
	nw = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			nw++;
		}
	}
	return (nw);
}

static int	len_caracter(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	execute(char *s, char c, char **str)
{
	int		i;
	int		j;
	int		k;
	size_t	length;

	i = 0;
	j = -1;
	while (s[i])
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		length = len_caracter(s + i, c) + 1;
		str[++j] = malloc(length * sizeof(char));
		if (str[j] == NULL)
			return (-1);
		while (s[i] && s[i] != c)
			str[j][k++] = s[i++];
		str[j][k] = '\0';
	}
	return (0);
}

static void	free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*str;

// 	str = (void *) malloc(count * (size));
// 	if (!str)
// 		return (NULL);
// 	ft_bzero(str, count * size);
// 	return (str);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t	i;
// 	char	*str;

// 	str = (char *)s;
// 	i = 0;
// 	while (i < n)
// 	{
// 		str[i] = 0;
// 		i++;
// 	}
// }

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	length;
	int		err;

	if (!s)
		return (NULL);
	length = ft_words((char *)s, c) + 1;
	str = ft_calloc(length, sizeof(char *));
	if (!str)
		return (NULL);
	err = execute((char *)s, c, str);
	if (err == -1)
		return (free_tab(str), NULL);
	return (str);
}
