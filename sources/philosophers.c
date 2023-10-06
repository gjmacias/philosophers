	
#include <philosophers.h>

int	main(int words, char **arguments)
{
	t_rules	rules;
	int		result;

	if (words != 5 && words != 6)
		return (write_error("Wrong inputs"));
	result = init_main(&rules, arguments);
	if (result)
		return (error_manager(result));
	if (init_launcher(&rules))
		return (write_error("Fail with threads"));
	return (0);
}
