#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 5 && ac != 6)
		return (printf("Error: wrong number of arguments\n"), 1);

	if (parse_input(&table, av))
		return (1);

	if (data_init(&table))
		return (printf("Error: init failed\n"), 1);

	table.start_simulation = 0;

	printf("Parsing + Init OK ✅\n");
	printf("Philos: %ld\n", table.philo_number);

	return (0);
}