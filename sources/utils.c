
#include "philosophers.h"

int	ft_atoi(const char *str)
{
	long int	n;
	int		sign;

	n = 0;
	sign = 1;
	while ((*str <= 13 && *str >= 9) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str)
	{
		if ((*str >= '0' && *str <= 9) && sign == 1)
			n = n * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return((int)(n * sign));
}

/*
** Sacamos el tiempo multiplicando los segundos por 1000 (para dejar 3 cifras para los ms)
** los picosegundos los dividimos por mil para quedarnos con 3 cifras (los ms) y los sumamos
*/

long long	the_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec/1000));
}

long long time_diff(long long present, long long past)
{
	return (present - past)
}

void	ft_sleep(long long time_sleep, t_rules *r)
{
	long long i;

	i = the_time();
	while(!r->death)
	{
		if (time_diff(the_time(), i) >= time_sleep)
			break ;
		usleep(100);
	}
}

/*
** Hacemos una funcion especifica para escribir ya que no todos pueden escribir por pantalla
** a la vez, para eso esta esta funcion con su mutex propio.
*/

void	ft_writing(t_rules *r, int id, char *s)
{
	pthread_mutex_lock(&(r->writing));
	if(!(r->death))
	{
		printf("%lli ", the_time() - r->first_time);
		printf("%i ", id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(r->writing));
}
