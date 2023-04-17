/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_of_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 07:33:03 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/13 02:27:55 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_check_caracter(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-')
		{
			write(1, "this is negative\n", 17);
			exit(1);
		}
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
			{
				write(2, "Error:\n arguments aren't integers", 33);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_biger(char **str)
{
	int		i;
	int		j;
	long	pid;

	i = 0;
	pid = ft_atoi(str[i]);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (pid > INT_MAX)
			{
				write(2, "Error\n:bigger than integer", 25);
			}
			else if (pid < INT_MIN)
			{
				write (2, "Error\n:littel than int_min", 26);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_zero(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == '0')
			{
				write(2, "Erro:\n Mr,zero", 17);
				exit(1);
			}
			j++;
		}
		i++;
	}
}
