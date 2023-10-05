	
#include <philosophers.h>

int	main(int words, char **arguments)
{
	t_rules	rules;
	int		result;
	
	if (words != 5 && words != 6)
		return (write_error("Wrong inputs"));
	if (result = init_main(&rules, arguments))
		return (error_manager(result));
	if (death_loop_checker(&rules))
		return(write_error("Murio"));
	return (0);
}
