
/*
** Las estructura de filosofos guardan los enteros:
** id(n, identificador), i_eat(Bool, si esta comiendo o no), Left(n) y Right(n)
** guardando el identificador de los tenedores, last meal(Guarda el tiempo que vive)
** Guardan el hilo y el proceso:
** thread(identificador de hilo), proces(identificador de proceso)
*/

typedef struct	s_philosopher
{
	int		id;
	int		i_eat;
	int		left_fork;
	int		right_fork;
	long long int	last_meal;
	pthread_t	thread_id;
	pid_t		process_id;
}	t_philosopher;

/*
** Las reglas guardan los enteros:
** filosofos(n), T. muerte(ms), T. comer(ms), T. dormir(ms), muerto(Bool), comiendo(n)
** Guardan los siguientes procesos de mutex:
** , fork(posibles mutex), writing().
** Y guardamos la estructura de filosofos, tantos como mutex haya.
*/

typedef struct	s_rules
{
	int		n_philo;
	int		death_time;
	int		eat_time;
	int		sleep_time;
	int		death;
	int		n_eating;
	long long int	first_time;
	pthread_mutex_t	;
	pthread_mutex_t	fork[250];
	pthread_mutex_t	writing;
	t_philosopher	philosophers[250];
}	t_rules;
