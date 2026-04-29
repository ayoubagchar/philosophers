#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
#include <limits.h>
# define DEBUG_MODE 0

// ================= FORWARD DECLARATIONS =================
typedef struct s_table t_table;
typedef struct s_fork t_fork;
typedef struct s_philo t_philo;

// ================= ENUMS =================

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH
}	t_opcode;

typedef enum e_philo_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FIRST_FORK,
	TAKE_SECOND_FORK,
	DIED
}	t_philo_status;

typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_code;

// ================= STRUCTS =================

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			meal_count;
	bool			full;
	long			last_meal_time;

	t_fork			*first_fork;
	t_fork			*second_fork;

	pthread_t		thread_id;
	pthread_mutex_t	philo_mutex;

	t_table			*table;

}	t_philo;

typedef struct s_table
{
	long			philo_number;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			number_limit_meals;

	long			start_simulation;
	bool			end_simulation;
	bool			all_threads_ready;

	long			threads_running_nbr;

	t_fork			*forks;
	t_philo			*philos;

	pthread_mutex_t	table_mutex;
	pthread_mutex_t	write_mutex;

	pthread_t		monitor;

}	t_table;

// ================= FUNCTIONS =================

long	ft_atol(const char *str);
int		valid_input(char *str);
int		parse_input(t_table *table, char **av);
int	data_init(t_table *table);

#endif