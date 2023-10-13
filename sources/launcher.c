/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:18:35 by gmacias-          #+#    #+#             */
/*   Updated: 2023/10/09 10:18:37 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

/*
** Exit teune todos los hilos, a parte te destruye todos los bloqueos;
** De los tenedores, para escribir y para chequear el tiempo de la ultima comida
** 
*/

void	exit_launcher(t_rules *r, t_philosopher *p)
{
	int	i;

	if (r->n_philo == 1)
		pthread_mutex_unlock(&(r->fork[p[0].left_fork]));
	i = -1;
	while (++i < r->n_philo)
		pthread_join(p[i].thread_id, NULL);
	i = -1;
	while (++i < r->n_philo)
		pthread_mutex_destroy(&(r->fork[i]));
	pthread_mutex_destroy(&(r->writing));
	pthread_mutex_destroy(&(r->meal_check));
	pthread_mutex_destroy(&(r->stop_check));
}

/*
** El proceso de comer: bloquea tenedores, comprueba que come y toma tiempo en
** comer y luego libera todo e indica que come con (count_eat)
** 
** IMPORTANTE: Bloquea con meal_check por que modifica el tiempo de su ultima
** comida entonces para que la comprobacion para death_checker no confunda el
** tiempo de muerte lo bloquea y trabajan con el mismo valor 
*/

void	philo_is_eating(t_philosopher *p, t_rules *r)
{
	pthread_mutex_lock(&(r->fork[p->left_fork]));
	ft_writing(r, p->id, "has taken a fork");
	if (r->n_philo == 1)
	{
		pthread_mutex_lock(&(r->fork[p->left_fork]));
		pthread_mutex_unlock(&(r->fork[p->left_fork]));
		return ;
	}
	pthread_mutex_lock(&(r->fork[p->right_fork]));
	ft_writing(r, p->id, "has taken a fork");
	pthread_mutex_lock(&(r->meal_check));
	ft_writing(r, p->id, "is eating");
	pthread_mutex_lock(&(r->stop_check));
	(p->count_eat)++;
	p->last_meal = the_time();
	death_by_goal(r, p);
	pthread_mutex_unlock(&(r->stop_check));
	pthread_mutex_unlock(&(r->meal_check));
	ft_sleep(r->eat_time, r);
	pthread_mutex_unlock(&(r->fork[p->left_fork]));
	pthread_mutex_unlock(&(r->fork[p->right_fork]));
}

/*
** En la funcion solo podemos pasar un parametro, por ello añadimos rules a cada
** filosofo. En esta funcion nos aseguramos de que coman.
** Repetiran el proceso hasta asegurarse de que no mueren o cumplen el objetivo
** de comer, al cumplirlo, dara igual que duerman o piensen. 
*/

void	*eating_loop(void *void_p)
{
	t_philosopher	*p;
	t_rules			*r;
	int				stop;

	p = (t_philosopher *)void_p;
	r = (t_rules *)p->rules;
	if (p->id % 2)
		usleep(15000);
	while (42)
	{
		philo_is_eating(p, r);
		pthread_mutex_lock(&(r->stop_check));
		stop = ft_stop_checker((r->death), (r->eating_goal));
		pthread_mutex_unlock(&(r->stop_check));
		if (stop)
			break ;
		ft_writing(r, p->id, "is sleeping");
		ft_sleep(r->sleep_time, r);
		ft_writing(r, p->id, "is thinking");
	}
	return (NULL);
}

/*
** Creamos un puntero para recorrer todos lo filosofos, creando un hilo para cada
** uno de ellos. Tambien guarda el tiempo de creación tanto de las reglas como de
** cada filosofo genera un hilo para cada filosofo con la funcion;
** FUNCION_DEL_HILO(eating_process). Una vez todo creados, los dejamos comer
** mientras el programa entra a la comprobacion.
*/

int	init_launcher(t_rules *r)
{
	int				i;
	t_philosopher	*p;

	p = r->philosophers;
	r->first_time = the_time();
	i = -1;
	while (++i < r->n_philo)
	{
		if (pthread_create(&(p[i].thread_id), NULL, eating_loop, &(p[i])))
			return (1);
		pthread_mutex_lock(&(r->meal_check));
		p[i].last_meal = the_time();
		pthread_mutex_unlock(&(r->meal_check));
	}
	death_checker_loop(r, r->philosophers);
	exit_launcher(r, p);
	return (0);
}
