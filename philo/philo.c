/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:51:45 by aennaouh          #+#    #+#             */
/*   Updated: 2023/06/22 16:11:33 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init(t_data **insid, int nb_philo, t_info *info)
{
	int		i;
	t_data	*new_data;

	i = 0;
	while (i < nb_philo)
	{
		new_data = malloc(sizeof(t_data));
		if (!new_data)
			return ;
		new_data->index = i + 1;
		new_data->content = 0;
		new_data->next = NULL;
		new_data->mutex = malloc(sizeof(pthread_mutex_t));
		if (!new_data->mutex)
			return ;
		pthread_mutex_init(new_data->mutex, NULL);
		new_data->next = NULL;
		new_data->info = info;
		ft_lstadd_back(insid, new_data);
		i++;
	}
}

int	count(t_info *fix, t_data *insid)
{
	init(&insid, fix->number_of_philosophers, fix);
	creat_threads(insid);
	if (time_finish(insid))
	{
		pthread_mutex_destroy(insid->mutex);
		pthread_mutex_destroy(insid->info->mut);
		return (0);
	}
	return (1);
}

void	initialize(t_info *fix)
{
	fix->split = NULL;
	fix->join = NULL;
	fix->i = 1;
}

void	suit_main(t_info *fix, int argc, char **argv)
{
	fix->split = ft_split(fix->join, ' ');
	free(fix->join);
	ft_check_caracter(fix->split);
	ft_check_biger(fix->split);
	ft_check_zero(fix->split);
	fix->mut = malloc(sizeof(pthread_mutex_t));
	if (!fix->mut)
	{
		return ;
	}
	pthread_mutex_init(fix->mut, NULL);
	read_instraction(&fix, argv, argc);
}

int	main(int argc, char **argv)
{
	t_data		*insid;
	t_info		*fix;

	insid = NULL;
	if (argc != 5 && argc != 6)
		return (error("erro arg\n"));
	fix = (t_info *)malloc(sizeof(t_info));
	if (!fix)
		return (error("erro malloc\n"));
	initialize(fix);
	if (argc == 5 || argc == 6)
	{
		fix->i = 1;
		fix->join = ft_strdup("");
		while (argv[fix->i])
		{
			fix->join = ft_strjoin(fix->join, " ");
			fix->join = ft_strjoin(fix->join, argv[fix->i]);
			fix->i++;
		}
		suit_main(fix, argc, argv);
	}
	if (!count(fix, insid))
		return (0);
}
