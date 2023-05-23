/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:46:35 by aennaouh          #+#    #+#             */
/*   Updated: 2023/05/23 16:12:47 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void number_of_times_each_philosopher_must_eat(t_data *insid)
{
	while(1)
	{
		if (insid->info.number_of_times_each_philosopher_must_eat) 
		{
				time_finish(insid);
				printf("%s", "----the_stimulation_stop_when_philo_dies----");
		}
	else if ( insid->info.time_to_eat > insid->info.number_of_times_each_philosopher_must_eat)
		{	
			printf("%s", "----the stimulation stop----");
				exit(1);
		}
	}
}

void	to_eat(t_data *insid)
{
	pthread_mutex_lock(insid->mutex);
	printf(" %lld %d has taken a fork\n", \
	gettime() - insid->info.start_time, insid->index);
	pthread_mutex_lock(insid->next->mutex); 
	printf(" %lld %d has taken a fork\n", \
	gettime() - insid->info.start_time, insid->index);
	printf(" %lld %d is eat\n", \
	gettime() - insid->info.start_time, insid->index);
	insid->last_eat = gettime();
	usleep(insid->info.time_to_eat * 1000);
	pthread_mutex_unlock(insid->mutex);
	pthread_mutex_unlock(insid->next->mutex);
}

void	to_sleep(t_data *insid)
{
	printf(" %lld %d is sleeping\n", \
	gettime() - insid->info.start_time, insid->index);
	usleep(insid->info.time_to_sleep * 1000);
}

void	to_think(t_data *insid)
{
	printf (" %lld %d is thinking\n", \
	gettime() - insid->info.start_time, insid->index);
}

void	*routine(void *arg)
{
	t_data	*insid;

	insid = (t_data *)arg;
	if (insid->index % 2 == 0)
		usleep(100);
	insid->last_eat = insid->info.start_time;
	while (1)
	{
		to_eat(insid);
		to_sleep(insid);
		to_think(insid);
		number_of_times_each_philosopher_must_eat(insid);
	}
	return (NULL);
}

void	creat_threads(t_data *insid, t_info info)
{
	int			i;
	pthread_t	newthread1;

	i = 0;
	while (i < info.number_of_philosophers)
	{
		pthread_create (&newthread1, NULL, &routine, insid);
		insid = insid->next;
		i++;
	}
}
