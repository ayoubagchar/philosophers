#include "philo.h"

static int	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->table_mutex, NULL))
		return (1);
	if (pthread_mutex_init(&table->write_mutex, NULL))
		return (1);
	return (0);
}

static int	init_forks(t_table *table)
{
	long	i;

	table->forks = malloc(sizeof(t_fork) * table->philo_number);
	if (!table->forks)
		return (1);

	i = 0;
	while (i < table->philo_number)
	{
		table->forks[i].fork_id = i;
		if (pthread_mutex_init(&table->forks[i].fork_mutex, NULL))
			return (1);
		i++;
	}
	return (0);
}

static int	init_philos(t_table *table)
{
	long	i;

	table->philos = malloc(sizeof(t_philo) * table->philo_number);
	if (!table->philos)
		return (1);

	i = 0;
	while (i < table->philo_number)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meal_count = 0;
		table->philos[i].full = false;
		table->philos[i].last_meal_time = 0;

		table->philos[i].table = table;

		table->philos[i].first_fork = &table->forks[i];
		table->philos[i].second_fork = &table->forks[(i + 1) % table->philo_number];

		pthread_mutex_init(&table->philos[i].philo_mutex, NULL);
		i++;
	}
	return (0);
}

int	data_init(t_table *table)
{
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->threads_running_nbr = 0;

	if (init_mutexes(table))
		return (1);
	if (init_forks(table))
		return (1);
	if (init_philos(table))
		return (1);

	return (0);
}