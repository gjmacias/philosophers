
#include <philosophers.h>

/*
** iniciamos tantos mutex como tenedores haya, a parte, iniciamos un mutex para writing
** y otro para ...
** Devuele 1 en caso de que mutex no se genere correctamente.
*/

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->n_philo;
	while(--i >= 0)
	{
		if (phread_mutex_init(&(rules->fork[i]), NULL))
			return (2);
	}
	if (phread_mutex_init(&(rules->writing), NULL))
		return(2);
	if (phread_mutex_init(&(rules->meal_check), NULL))
		return(2);
	return (0);
}

/*
** iniciamos la Estructura de filosofos dandoles si identificador, el de sus tenedores
** y reseteamos la ultima vez que comieron. Luego pasamos rules, sera necesario despues.
*/

int	init_philosophers(t_rules *rules)
{
	int i;

	i = rules->n_philo;
	while (--i >= 0)
	{
		rules->philosophers[i].id = i;
		rules->philosophers[i].i_eat = 0;
		rules->philosophers[i].left_fork = i;
		rules->philosophers[i].right_fork = (i + 1) % rules->n_philo;
		rules->philosophers[i].last_meal = 0;
		rules->philosophers[i].rules = rules;
	}
	return (0);
}

/*
** iniciamos las reglas, guardmos numero de filosofos y tiempos, comprobamos que 
** cumplan las normas y por ultimo iniciamos:
** 	-init_mutex (para los tenedores)
**	-init_philosophers
*/

int init_main( t_rules *rules, char **arguments)
{
	rules->n_philo = ft_atoi(arguments[1]);
	rules->death_time = ft_atoi(arguments[2]);
	rules->eat_time = ft_atoi(arguments[3]);
	rules->sleep_time = ft_atoi(arguments[4]);
	rule->death = 0;
	rule->eating_goal = 0;
	if (rules->n_philo < 2 || rules->death_time < 0 || rules->eat_time < 0
	    	|| rules->sleep_time < 0 || rules->n_philo > 250)
		return (1);
	if (arguments[5])
	{
		rules->must_eat = ft_atoi(arguments[5])
		if (rules-> must_eat <= 0)
			return (1);
	}
	else
		rules->must_eat = -1;
	if (init_mutex(rules));
		return (2);
	init_philosophers(rules);
	return (0);
}
