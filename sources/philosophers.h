

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
	pthread_mutex_t	;
	t_philosopher	philosophers[250];
}	t_rules;
