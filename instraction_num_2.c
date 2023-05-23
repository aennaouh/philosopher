/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction_num_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:13:58 by aennaouh          #+#    #+#             */
/*   Updated: 2023/05/23 11:29:13 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	time_finish(t_data *insid)
{
	while (1)
	{
		if (insid->last_eat > 0 && \
		gettime() - insid->last_eat > insid->info.time_to_die)
		{
			printf(" %lld %d is died\n", \
			gettime() - insid->info.start_time, insid->index);
			exit(1);
		}
		insid = insid->next;
	}
}

long long	gettime(void)
{
	long long		time;
	struct timeval	tv;

	gettimeofday (&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

// void usleep1(unsigned int milliseconds) 
// {
//     struct timespec req;
//     req.tv_sec = milliseconds / 1000;
//     req.tv_nsec = (milliseconds % 1000) * 1000000L;

//     while (nanosleep(&req, &req) == -1);
// }
