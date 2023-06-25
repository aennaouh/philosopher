/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:46:35 by aennaouh          #+#    #+#             */
/*   Updated: 2023/06/22 19:56:42 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	to_eat(t_data *insid)
{
	pthread_mutex_lock(insid->mutex);
	pthread_mutex_lock(insid->info->mut);
	printf("%lld %d has taken a fork\n", gettime() \
	- insid->info->start_time, insid->index);
	pthread_mutex_unlock(insid->info->mut);
	pthread_mutex_lock(insid->next->mutex);
	pthread_mutex_lock(insid->info->mut);
	printf("%lld %d has taken a fork\n", gettime() \
	- insid->info->start_time, insid->index);
	pthread_mutex_unlock(insid->info->mut);
	pthread_mutex_lock(insid->info->mut);
	printf("%lld %d is eating\n", gettime() \
	- insid->info->start_time, insid->index);
	pthread_mutex_unlock(insid->info->mut);
	pthread_mutex_lock(insid->info->mut);
	insid->last_eat = gettime();
	pthread_mutex_unlock(insid->info->mut);
	pthread_mutex_lock(insid->info->mut);
	insid->count_eat++ ;
	pthread_mutex_unlock(insid->info->mut);
	usleep1(insid->info->time_to_eat);
	pthread_mutex_unlock(insid->mutex);
	pthread_mutex_unlock(insid->next->mutex);
}

void	to_sleep(t_data *insid)
{
	pthread_mutex_lock(insid->info->mut);
	printf("%lld %d is sleeping\n", \
	gettime() - insid->info->start_time, insid->index);
	pthread_mutex_unlock(insid->info->mut);
	usleep1(insid->info->time_to_sleep);
}

void	to_think(t_data *insid)
{
	pthread_mutex_lock(insid->info->mut);
	printf ("%lld %d is thinking\n", \
	gettime() - insid->info->start_time, insid->index);
	pthread_mutex_unlock(insid->info->mut);
}

void	*routine(void *arg)
{
	t_data	*insid;

	insid = (t_data *)arg;
	if (insid->index % 2 == 0)
		usleep (100);
	insid->count_eat = 0;
	pthread_mutex_lock(insid->info->mut);
	insid->last_eat = gettime();
	pthread_mutex_unlock(insid->info->mut);
	while (1)
	{
		to_eat(insid);
		to_sleep(insid);
		to_think(insid);
	}
	return (NULL);
}

void	creat_threads(t_data *insid)
{
	int			i;
	pthread_t	newthread1;

	i = 0;
	while (i < insid->info->number_of_philosophers)
	{
		insid->count_eat = 0;
		pthread_create (&newthread1, NULL, &routine, insid);
		insid = insid->next;
		i++;
	}
}
