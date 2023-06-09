
#include "philo.h"

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

long long	the_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec/1000));
}

long long time_diff(long long past, long long present)
{
	return (present - past)
}

void	
