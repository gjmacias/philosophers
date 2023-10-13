/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:18:24 by gmacias-          #+#    #+#             */
/*   Updated: 2023/10/09 10:18:29 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

/*
** iniciamos tantos mutex como tenedores haya, a parte, iniciamos un mutex para
** writing y otro para el chequeo de la comida
** Devuele 2 en caso de que mutex no se genere correctamente.
*/

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->n_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(rules->fork[i]), NULL))
			return (2);
	}
	if (pthread_mutex_init(&(rules->writing), NULL))
		return (2);
	if (pthread_mutex_init(&(rules->meal_check), NULL))
		return (2);
	if (pthread_mutex_init(&(rules->stop_check), NULL))
		return (2);
	return (0);
}

/*
** iniciamos la Estructura de filosofos dandoles si identificador, el de sus 
** tenedores y reseteamos la ultima vez que comieron. Luego pasamos las rules, 
** sera necesario para despues.
*/

int	init_philosophers(t_rules *rules)
{
	int	i;

	i = rules->n_philo;
	while (--i >= 0)
	{
		rules->philosophers[i].id = i;
		rules->philosophers[i].count_eat = 0;
		rules->philosophers[i].left_fork = i;
		rules->philosophers[i].right_fork = (i + 1) % rules->n_philo;
		rules->philosophers[i].last_meal = 0;
		rules->philosophers[i].rules = (struct t_rules *)rules;
	}
	return (0);
}

/*
** iniciamos las reglas, guardmos numero de filosofos y tiempos, comprobamos que 
** cumplan las normas y por ultimo iniciamos:
** 	-init_mutex (para los tenedores)
**	-init_philosophers
*/

int	init_main(t_rules *rules, char **arguments)
{
	rules->n_philo = ft_atoi(arguments[1]);
	rules->death_time = ft_atoi(arguments[2]);
	rules->eat_time = ft_atoi(arguments[3]);
	rules->sleep_time = ft_atoi(arguments[4]);
	rules->death = 0;
	rules->count_goal = 0;
	rules->eating_goal = 0;
	if (rules->n_philo < 1 || rules->death_time < 0 || rules->eat_time < 0
		|| rules->sleep_time < 0 || rules->n_philo > 200)
		return (1);
	if (arguments[5])
	{
		rules->must_eat = ft_atoi(arguments[5]);
		if (rules->must_eat <= 0)
			return (1);
	}
	else
		rules->must_eat = -1;
	if (init_mutex(rules))
		return (2);
	init_philosophers(rules);
	return (0);
}
