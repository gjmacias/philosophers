
#include "philo.h"

int	init_mutex(t_rules *rules)
{
	int	i;

	i = rules->n_philo;
	while(--i >= 0)
	{
		if ()
			return (1);
	}
	if ()
		return(1);
	if ()
		return(1);
	return (0);
}

int	init_philosophers(t_rules *rules)
{
	int i;

	i = n_philo;
	while (--i >= 0)
	{
		rules->philosophers[i].id = i;
		rules->philosophers[i].i_ate = 0;
		rules->philosophers[i].left_fork = i;
		rules->philosophers[i].right_fork = (i + 1) % rules->n_philo;
		rules->philosophers[i].last_meal = 0;
	}
	return (0);
}

int init_main( t_rules *rules, char **arguments)
{
	rules->n_philo = ft_atoi(arguments[1]);
	rules->death_time = ft_atoi(arguments[2]);
	rules->eat_time = ft_atoi(arguments[3]);
	rules->sleep_time = ft_atoi(arguments[4]);
	rule->death = 0;
	if (rules->n_philo < 2 || rules->death_time < 0 || rules->eat_time < 0
	    	|| rules->sleep_time < 0 || rules->n_philo > 250)
		return (1);
	if (arguments[5])
	{
		rules->n_eating = ftatoi(arguments[5])
		if (rules-> nb_eat <= 0)
			return (1);
	}
	else
		rules->nb_eat = -1;
	if (init_mutex(rules));
		reutn (2);
	init_philosophers(rules);
	return (0);
}
