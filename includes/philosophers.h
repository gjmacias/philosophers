/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:17:33 by gmacias-          #+#    #+#             */
/*   Updated: 2023/10/09 10:17:39 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>

struct	s_rules;

/*
** Las estructura de filosofos guardan los enteros:
** id(n, identificador), count_eat(Bool, si esta comiendo o no), Left(n) y 
** Right(n) guardando el identificador de los tenedores, 
** last meal(Guarda el tiempo que vive). 
** Guardan el hilo:
** thread(identificador de hilo)
*/

typedef struct s_philosopher
{
	int						id;
	int						count_eat;
	int						left_fork;
	int						right_fork;
	long long int			last_meal;
	pthread_t				thread_id;
	struct t_rules			*rules;
}	t_philosopher;

/*
** Las reglas guardan los enteros:
** filosofos(n), T. muerte(ms), T. comer(ms), T. dormir(ms), muerto(Bool), 
** cuanto debe comer(n), cumplio must_eat(Bool).
**
** Guardan los siguientes procesos de mutex:
** -fork: para bloquear los tenedores
** -writing: para bloquear la opcion de escritura, que solo uno escriba.
** -checking(bloqueo por comprobacion).
**
** Y guardamos la estructura de filosofos, tantos como mutex haya.
*/

typedef struct s_rules
{
	int				n_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				death;
	int				must_eat;
	int				eating_goal;
	long long int	first_time;
	pthread_mutex_t	meal_check;
	pthread_mutex_t	fork[200];
	pthread_mutex_t	writing;
	pthread_mutex_t	stop_check;
	t_philosopher	philosophers[200];
}	t_rules;

/*		---	utils	---		*/
void		ft_writing(t_rules *r, int id, char *s);
int			ft_atoi(const char *str);
long long	the_time(void);
long long	time_diff(long long present, long long past);
void		ft_sleep(long long time_sleep, t_rules *r);

/*		---	stop checker	---		*/
int			ft_stop_checker(int death, int goal);
void		death_checker_loop(t_rules *r, t_philosopher *p);

/*		---	init rules, mutex and philosophers	---		*/
int			init_main(t_rules *rules, char **arguments);

/*		---	launcher	---		*/
int			init_launcher(t_rules *rules);

/*		---	error manager	---		*/
int			write_error(char *str);
int			error_manager(int error);

#endif
