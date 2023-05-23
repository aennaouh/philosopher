/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_of_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 07:33:03 by aennaouh          #+#    #+#             */
/*   Updated: 2023/05/23 21:40:13 by aennaouh         ###   ########.fr       */
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

void	read_instraction(t_info *insid, char **argv, int argc)
{
	
	insid->number_of_philosophers = ft_atoi(argv[1]);
	if(insid->number_of_philosophers == 0 || insid->number_of_philosophers > 200)
	{
		printf("Mr,zero philo\n");
		exit(1);
	}
	insid->time_to_die = ft_atoi(argv[2]);
	insid->time_to_eat = ft_atoi(argv[3]);
	insid->time_to_sleep = ft_atoi(argv[4]);
	if(argc == 6)
	{
		insid->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}
	else 
			insid->number_of_times_each_philosopher_must_eat = -1;
	insid->start_time = gettime();
}
