/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:19:35 by gmacias-          #+#    #+#             */
/*   Updated: 2023/10/09 10:19:44 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	ft_stop_checker(int x, int y)
{
	int	i;

	if (x || y)
		i = 1;
	else
		i = 0;
	return (i);
}

void	death_by_hungry(t_rules *r, t_philosopher *p)
{
	int	i;

	i = -1;
	while (++i < r->n_philo)
	{
		pthread_mutex_lock(&(r->meal_check));
		if (time_diff(the_time(), p[i].last_meal) > r->death_time)
		{
			ft_writing(r, i, "died");
			pthread_mutex_lock(&(r->stop_check));
			r->death = 1;
			pthread_mutex_unlock(&(r->stop_check));
		}
		pthread_mutex_unlock(&(r->meal_check));
		usleep(50);
	}
}

void	death_by_goal(t_rules *r, t_philosopher *p)
{
	int	i;
	int	n;

	i = 0;
	pthread_mutex_lock(&(r->meal_check));
	n = p[i].count_eat;
	pthread_mutex_unlock(&(r->meal_check));
	while ((r->must_eat != -1) && (i < r->n_philo)
		&& (n >= r->must_eat))
	{
		i++;
		pthread_mutex_lock(&(r->meal_check));
		n = p[i].count_eat;
		pthread_mutex_unlock(&(r->meal_check));
		usleep(50);
	}
	if (i == r->n_philo)
	{
		pthread_mutex_lock(&(r->stop_check));
		r->eating_goal = 1;
		pthread_mutex_unlock(&(r->stop_check));
	}
}

/*
** Este es complejo asi que vamos poco a poco: el bucle principal se ejecuta
** mientras la meta de comer (eating_goal) no se haya alcanzado.
** El segundo verifica cada filosofo para ver si uno a muerto, en caso de ser
** asi, masca la muerte
** El if es por si muere, que pare el bucle principal.
** El 3r bucle es por si hay una regla para comer: comprueba que cada filosofo
** supere el minimo de comer, CUENTA LOS FILOSOFOS QUE CUMPLEN
** si TODOS cumplen, la meta esta alcanzada
*/

void	death_checker_loop(t_rules *r, t_philosopher *p)
{
	int	stop;

	while (42)
	{
		death_by_hungry(r, p);
		pthread_mutex_lock(&(r->stop_check));
		stop = ft_stop_checker((r->death), (r->eating_goal));
		pthread_mutex_unlock(&(r->stop_check));
		if (stop)
			break ;
		death_by_goal(r, p);
	}
}
