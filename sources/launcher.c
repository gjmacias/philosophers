
#include "philo.h"

int	launcher(t_rules *rules)
{
	int	i;
	t_philosopher *philo;

	i = -1;
	while (++i < rules->n_philo)
	{
		philo[i].process_id = fork();
		if (philo[i].process_id < 0)
			return (1);
		if (philo[i].process_id == 0)
			function(rules, &(philo[i]));
		usleep(100);
	}
	exit_launcher(rules);
	return (0);
}
