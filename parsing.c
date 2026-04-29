#include "philo.h"

int	valid_input(char *str)
{
	int	i = 0;
	int	len = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;

	if (str[i] == '-' || str[i] == '+')
		return (0);

	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);

	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
		len++;
	}
	if (len > 10)
		return (0);
	return (1);
}

long	ft_atol(const char *str)
{
	long	result = 0;
	int		i = 0;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX)
			return (-1);
		i++;
	}
	return (result);
}

int	parse_input(t_table *table, char **av)
{
	if (!valid_input(av[1]) || !valid_input(av[2])
		|| !valid_input(av[3]) || !valid_input(av[4]))
		return (printf("Error: invalid input\n"), 1);

	table->philo_number = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]) * 1000;
	table->time_to_eat = ft_atol(av[3]) * 1000;
	table->time_to_sleep = ft_atol(av[4]) * 1000;

	if (av[5])
	{
		if (!valid_input(av[5]))
			return (printf("Error: invalid input\n"), 1);
		table->number_limit_meals = ft_atol(av[5]);
	}
	else
		table->number_limit_meals = -1;

	if (table->time_to_die < 60000
		|| table->time_to_eat < 60000
		|| table->time_to_sleep < 60000)
		return (printf("Error: time too small\n"), 1);

	return (0);
}