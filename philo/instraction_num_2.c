/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction_num_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:13:58 by aennaouh          #+#    #+#             */
/*   Updated: 2023/06/22 16:56:04 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_all_ate(t_data *insid)
{
	int	i;

	i = 0;
	while (i < insid->info->number_of_philosophers)
	{
		if (insid->count_eat < \
		insid->info->number_of_times_each_philosopher_must_eat)
			return (0);
		insid = insid->next;
		i++;
	}
	return (1);
}

int	time_finish(t_data *insid)
{
	while (1)
	{
		pthread_mutex_lock(insid->info->mut);
		if (insid->last_eat > 0 && \
		gettime() - insid->last_eat > insid->info->time_to_die)
		{
			printf("%lld %d is died\n", \
			gettime() - insid->info->start_time, insid->index);
			return (1);
		}
		if (insid->info->number_of_times_each_philosopher_must_eat != -1)
		{
			if (is_all_ate(insid))
				return (1);
		}
		insid = insid->next;
		pthread_mutex_unlock(insid->info->mut);
	}
	return (0);
}

size_t	gettime(void)
{
	long long		time;
	struct timeval	tv;

	gettimeofday (&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	usleep1(size_t time_give)
{
	long long	time;

	time = gettime();
	while (1)
	{
		if (gettime() - time >= time_give)
			break ;
		else
			usleep(100);
	}
}

int	error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}
