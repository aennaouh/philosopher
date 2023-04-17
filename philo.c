/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:51:45 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/17 02:08:01 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int argc, char **argv)
{
	int	i;
	char **split;
	char *join;

	join = NULL;
	split = NULL;
	if (argc == 5 || argc == 6)
	{
		i = 1;
		join = ft_strdup("");
			while (argv[i])
		{
			join = ft_strjoin(join, " ");
			join = ft_strjoin(join, argv[i]);
			i++;
		}
		split = ft_split(join, ' ');
		free(join);
		
		ft_check_caracter(split);
		ft_check_biger(split);
		ft_check_zero(split);
	}
	else
		printf("Invalid number of args\n");
}