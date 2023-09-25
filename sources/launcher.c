
#include "philo.h"

void	launcher(t_rules *r, t_philosopher * p)
{
	int i;
	
	while(!(r->everyone_ate))
	{
		i = -1;
		while
	}
}

/*
** Creamos un puntero para recorrer todos lo filosofos, creando un hilo para cada uno
** de ellos. Tambien guarda el tiempo de creación tanto de las reglas como de cada filosofo
** Una vez todo creado, ejecutamos el programa de los filosofos
*/

int	init_launcher(t_rules *rules)
{
	int	i;
	t_philosopher *p;

	i = -1;
	p = rule->philosophers;
	rules->first_time = the_time();
	while (++i < rules->n_philo)
	{
		if (pthread_create(&(p[i].thread_id), NULL, p_thread, &(p[i])))
			return (1);
		p[i].last_meal = the_time();
	}
	launcher(rules, rules->philosophers);
	exit_launcher(rules, p);
	return (0);
}
