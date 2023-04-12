
#include "philo.h"

init_semaphore(t_rules *rule)
{
	sem_unlink();
	sem_unlink();
	sem_unlink();
	rules-> = sem_open();	
	rules-> = sem_open();	
	rules-> = sem_open();	
	if(rules-> <= 0 || rules-> <= 0 || rules-> <= 0)
		return (1);
	return (0);
}

int	init_philosophers()
{
	int i;

	i = n_philo;
	while (--i >= 0)
	{
		rules->philosophers[i].id = i;
		rules->philosophers[i]. = 0;
		rules->philosophers[i]. = 0;
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
	if (rules->n_eating == 1)
		rules->n_eating++;
	if (init_semaphore(rules));
		reutn (2);
	init_philosophers();
	return (0);
}
