
#include <philosophers.h>

/*
** Exit teune todos los hilos, a parte te destruye todos los bloqueos;
** De los tenedores, para escribir y para chequear el tiempo de la ultima comida
** 
*/

void	exit_launcher(t_rules *r, t_philosopher *p)
{
	int	i;

	i = -1;
	while(++i < r->n_philo)
		pthread_join(p[i].thread_id, NULL);
	i = -1;
	while(++i < r->n_philo)
		pthread_mutex_destroy(&(rules->fork[i]));
	pthread_mutex_destroy(&(rules->writing));
	pthread_mutex_destroy(&(rules->meal_check));
}

void	death_loop_checker(t_rules *r, t_philosopher *p)
{
	int i;
	
	while(!(r->eating_goal))
	{
		i = -1;
		while (++i <r->n_philo && r->death == 0)
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(p[i].last_meal, the_time()) > r->death_time)
			{
				ft_writing(r, i, "died");
				r->death = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->death)
			break ;
		i = 0;
		while((r->must_eat != -1) && (i < r->n_philo) && (p[i].i_eat >= r->must_eat))
			i++;
		if (i >= r->must_eat)
			r->eating_goal = 1;
	}
}

/*
** El proceso de comer: bloquea tenedores, comprueba que come y toma tiempo en comer
** Luego libera todo e indica que come con (i_eat)
** 
** IMPORTANTE: Bloquea con meal_check por que modifica el tiempo de su ultima comida
** entonces para que la comprobacion para death_checker no confunda el tiempo de muerte
** lo bloquea y trabajan con el mismo valor 
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
** En esta funcion nos aseguramos de que coman.
** Repetiran el proceso hasta asegurarse de que no mueren o cumplen el objetivo de comer
** 
*/

void	eating_loop_process(void *void_p)
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
		if (r->eating_goal)
			break ;
		ft_writing(r, p->id, "is sleeping");
		ft_sleep(r->sleep_time, r);
		ft_writing(r, p->id, "is thinking");
	}
}

/*
** Creamos un puntero para recorrer todos lo filosofos, creando un hilo para cada uno
** de ellos. Tambien guarda el tiempo de creación tanto de las reglas como de cada filosofo
** genera un hilo para cada filosofo con la FUNCION_DEL_HILO(eating_process)
** Una vez todo creados, los dejamos comer mientras el programa entra a la comprobacion.
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
		if (pthread_create(&(p[i].thread_id), NULL, eating_loop_process, &(p[i])))
			return (1);
		p[i].last_meal = the_time();
	}
	death_loop_checker(rules, rules->philosophers);
	exit_launcher(rules, p);
	return (0);
}
