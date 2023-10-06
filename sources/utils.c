
#include <philosophers.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int	n;
	int			sign;

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
		if ((*str >= '0' && *str <= '9') && sign == 1)
			n = n * 10 + (*str++ - '0');
		else
			return (-1);
	}
	return ((int)(n * sign));
}

/*
** Sacamos el tiempo multiplicando los segundos por 1000 (para dejar 3 cifras 
** para los ms) los picosegundos los dividimos por mil para quedarnos 
** con 3 cifras (los ms) y los sumamos
*/

long long	the_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	time_diff(long long present, long long past)
{
	return (present - past);
}

void	ft_sleep(long long time_sleep, t_rules *r)
{
	long long	i;

	i = the_time();
	while (!r->death)
	{
		if (time_diff(the_time(), i) >= time_sleep)
			break ;
		usleep(100);
	}
}
