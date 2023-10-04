
#include "philosophers.h"

void	launcher(t_rules *r, t_philosopher *p)
{
	int i;
	
	while(!(r->everyone_ate))
	{
		i = -1;
		while
	}
}

/*
** El proceso de comer: bloquea tenedores, comprueba que come y toma tiempo en comer
** Luego libera todo e indica que come con (i_eat)
** 
*/

void	philo_is_eating(t_philosopher *p, t_rules *r)
{
	pthread_mutex_lock(&(r->forks[p->left_fork]));
	ft_writing(r, p->id, "has taken a fork");
	pthread_mutex_lock(&(r->forks[p->right_fork]));
	ft_writing(r, p->id, "has taken a fork");
	pthread_mutex_lock(&(r->meal_check));
	ft_writing(r, p->id, "is eating");
	p->last_meal = the_time();
	pthread_mutex_unlock(&(r->meal_check));
	ft_sleep(r->eat_time, r);
	(p->i_eat)++;
	pthread_mutex_unlock(&(r->forks[p->left_fork]));
	pthread_mutex_unlock(&(r->forks[p->right_fork]));
}

/*
** En la funcion solo podemos pasar un parametro, por ello añadimos rules a cada filosofo.
** En esta funcion nos aseguramos que todos coman, repetira el proceso hasta asegurarse de ello
** 
*/

void	first_meal(void *void_p)
{
	t_philosopher	*p;
	t_rules			*r;

	p = (t_philosopher *)void_p;
	r = p->rules;
	if (p->id % 2)
		usleep(15000);
	while (!(r->death))
	{
		philo_is_eating(p, r);
		if (r->everyone_ate)
			break ;
		ft_writing(r, p->id, "is sleeping");
		ft_sleep(r->sleep_time, r);
		ft_writing(r, p->id, "is thinking");
	}
}

/*
** Creamos un puntero para recorrer todos lo filosofos, creando un hilo para cada uno
** de ellos. Tambien guarda el tiempo de creación tanto de las reglas como de cada filosofo
** genera un hilo para cada filosofo con la FUNCION_DEL_HILO(function_thread)
** Una vez todo creado, ejecutamos el programa de los filosofos.
*/

int	init_launcher(t_rules *rules)
{
	int				i;
	t_philosopher	*p;

	p = rule->philosophers;
	rules->first_time = the_time();
	i = -1;
	while (++i < rules->n_philo)
	{
		if (pthread_create(&(p[i].thread_id), NULL, first_meal, &(p[i])))
			return (1);
		p[i].last_meal = the_time();
	}
	launcher(rules, rules->philosophers);
	exit_launcher(rules, p);
	return (0);
}
