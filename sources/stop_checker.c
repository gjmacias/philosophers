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

int	ft_stop_checker(int death, int goal)
{
	int	i;

	if (death || goal)
		i = 1;
	else
		i = 0;
	return (i);
}

/*
** Aqui comprobamos por cada filosofo la diferencia de tiempo entre su ultima
** comida y cuanto tiempo esta vivo, si es mayor a su tiempo de muerte.
** 	(r->death = 1) se convierte en verdad
*/

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

/*
** Aqui comprobamos por cada filosofo cuantas veces a comido, en esta funcion
** comprobamos que:
** 	p->count_eat == r->must_eat (el filosofo coma las veces OBLIGATORIAS)
** esto lo hacemos para cada filosofo en un bucle, ya que nos contara cuantos
** filosofos ya lo han hecho. Al final, comprobamos si todos los filosofos 
** cumplen la meta;
** r->count_goal == r->n_philo (el numero de conseguidos son TODOS los filos)
*/

void	death_by_goal(t_rules *r, t_philosopher *p)
{
	if (p->count_eat == r->must_eat)
	{
		r->count_goal++;
	}
	if (r->count_goal == r->n_philo)
	{
		r->eating_goal = 1;
	}
}

/*
** Este es complejo asi que vamos poco a poco: este es el bucle principal para
** Comprobar si se debe cerrar el launcher. STOP depende de si alguien muere o
** todos cumplen la meta. al depeder de dos casos distintos, pos separamos en
** dos funciones distintas:
** - para comprobar si mueren de hambre: death_by_hungry()
** - para comprobar si acaban por meta: death_by_goal()
** si una de las dos cumple, se cierra el programa.
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
	}
}
