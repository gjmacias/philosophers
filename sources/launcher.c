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
		pthread_mutex_unlock(&(r->fork[p[0]->left_fork]));
	i = -1;
	while (++i < r->n_philo)
		pthread_join(p[i].thread_id, NULL);
	i = -1;
	while (++i < r->n_philo)
		pthread_mutex_destroy(&(r->fork[i]));
	pthread_mutex_destroy(&(r->writing));
	pthread_mutex_destroy(&(r->meal_check));
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
	int	i;

	while (!(r->eating_goal))
	{
		i = -1;
		while (++i < r->n_philo && r->death == 0)
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(the_time(), p[i].last_meal) > r->death_time)
			{
				ft_writing(r, i, "died");
				r->death = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(50);
		}
		if (r->death)
			break ;
		i = 0;
		while ((r->must_eat != -1) && (i < r->n_philo)
			&& (p[i].count_eat >= r->must_eat))
			i++;
		if (i == r->n_philo)
			r->eating_goal = 1;
	}
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
	p->last_meal = the_time();
	(p->count_eat)++;
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

	p = (t_philosopher *)void_p;
	r = (t_rules *)p->rules;
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
		p[i].last_meal = the_time();
	}
	death_checker_loop(r, r->philosophers);
	exit_launcher(r, p);
	return (0);
}
