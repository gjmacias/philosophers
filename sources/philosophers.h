#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
/*
** Las estructura de filosofos guardan los enteros:
** id(n, identificador), i_eat(Bool, si esta comiendo o no), Left(n) y Right(n)
** guardando el identificador de los tenedores, last meal(Guarda el tiempo que vive)
** Guardan el hilo:
** thread(identificador de hilo)
*/

typedef struct	s_philosopher
{
	int		id;
	int		i_eat;
	int		left_fork;
	int		right_fork;
	long long int	last_meal;
	pthread_t	thread_id;
}	t_philosopher;

/*
** Las reglas guardan los enteros:
** filosofos(n), T. muerte(ms), T. comer(ms), T. dormir(ms), muerto(Bool), comiendo(n),todos comieron(Bool)
** Guardan los siguientes procesos de mutex:
** , fork(posibles mutex), writing(bloqueo por funcionamiento), checking(bloqueo por comprobacion).
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
	int		everyone_ate;
	long long int	first_time;
	pthread_mutex_t	checking;
	pthread_mutex_t	fork[250];
	pthread_mutex_t	writing;
	t_philosopher	philosophers[250];
}	t_rules;




/	---	utils	---	/
int		ft_atoi(const char *str);
long long	the_time(void);
long long	time_diff(long long past, long long present);


/	---	init rules, mutex and philosophers	---	/
int 		init_main( t_rules *rules, char **arguments);


/	---	launcher	---	/
void		launcher(t_rules *r, t_philosopher *p);


/	---	error manager	---	/
int		write_error(char *str);
int		error_manager(int error);

#endif
