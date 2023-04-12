

typedef struct	s_philosopher
{
	int		id;
	int		;
	int		left_fork;
	int		right_fork;
	long long	;
	pthread_t	;
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
	long long	;
	sem_t		;
	sem_t		;
	sem_t		;
	t_philosopher	philosophers[250];
}	t_rules;
