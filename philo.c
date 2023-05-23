/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:51:45 by aennaouh          #+#    #+#             */
/*   Updated: 2023/05/23 21:34:12 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init(t_data **insid, int nb_philo, t_info info)
{
	int		i;
	t_data	*new_data;

	i = 0;
	while (i < nb_philo)
	{
		new_data = malloc(sizeof(t_data));// Create a new t_data instance
		new_data->index = i + 1;
		new_data->content = 0;
		new_data->mutex = malloc(sizeof(pthread_mutex_t));// Allocate memory for mutex
		pthread_mutex_init(new_data->mutex, NULL); // Initialize the mutex
		new_data->next = NULL;
		new_data->info = info;
		ft_lstadd_back(insid, new_data);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int				i;
	char			**split;
	char			*join;
	t_info			fix;
	t_data			*insid;
	pthread_mutex_t	mutex;

	insid = NULL;
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
	read_instraction(&fix, argv, argc);
	init(&insid, fix.number_of_philosophers, fix);
	pthread_mutex_init(&mutex, NULL);
	creat_threads(insid, fix);
	time_finish(insid);
	pthread_mutex_destroy(&mutex);
	while (1);
}
