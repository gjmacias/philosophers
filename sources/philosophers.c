	
#include "philo.h"

int	main(int words, char **arguments)
{
	t_rules	rules;
	int		result;
	
	if (words != 5 && words != 6)
		return (write_error("Wrong inputs"));
	if (result = init_main(&rules, arguments))
		return (error_manager(result));
	if ()
	return (0);
}
