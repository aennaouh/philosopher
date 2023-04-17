/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaouh <aennaouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 07:33:37 by aennaouh          #+#    #+#             */
/*   Updated: 2023/04/17 19:58:15 by aennaouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <pthread.h>

typedef struct s_philo
{
    int         index;
    thread_t    thrd;
    int content;
    struct s_data *next;
}t_philo; 

typedef struct s_info
{
    
    size_t      number_of_philosophers;
    size_t      time_to_sleep 
    size_t      time_to_die;
    size_t      time_to_eat;
    size_t      number_of_times_each_philosopher_must_eat;
    size_t      start_time;
    
} t_info;

void	ft_check_caracter(char **str);
void	ft_check_biger(char **str);
void	ft_check_zero(char **str);
int     ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);

#endif
