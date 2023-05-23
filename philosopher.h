/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 07:33:37 by aennaouh          #+#    #+#             */
/*   Updated: 2023/05/23 18:58:54 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<limits.h>
# include<pthread.h>
# include<sys/time.h>

typedef struct s_data t_data; // Forward declaration

typedef struct s_info
{
	t_data         *data;
	int      number_of_philosophers;
	long    long time_to_sleep;
	long    long      time_to_die;
	long    long      time_to_eat;
	long    long      number_of_times_each_philosopher_must_eat;
	long    long start_time;
}t_info;

struct s_data
{
	int             index;
	int             content;
	long long       last_eat;
	pthread_t       thread;
	pthread_mutex_t *mutex;
	struct s_data   *next;
	t_info          info;
};

void    *routine(void *arg);
void    to_eat(t_data *insid);
void    to_sleep(t_data *insid);
void    to_think(t_data *insid);
void	ft_check_caracter(char **str);
 void  creat_threads(t_data *insid, t_info info);
void	ft_check_biger(char **str);
void	ft_check_zero(char **str);
int     ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void    read_instraction(t_info *insid, char **argv, int argc);
t_data	*ft_lstnew(int content);
void	ft_lstadd_back(t_data **lst, t_data *new);
long    long gettime();
void    init(t_data **insid, int nb_philo, t_info info);
void    time_finish(t_data *insid);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
