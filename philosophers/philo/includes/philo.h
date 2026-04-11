#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_table t_table;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	long			last_meal; // Ultima vez que empezo a comer
	pthread_t		thread;
	pthread_mutex_t	meal_mutex; // protege a last_meal y meals_eaten
	t_table			*table;
}	t_philo;

typedef struct s_table
{
	int				nb_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_count;
	int				simulation_end;
	long			start_time;
	pthread_mutex_t	*forks; // el array de mutexes, uno por tenedor
	pthread_mutex_t	print_mutex; // evita logs mezclados
	pthread_mutex_t	state_mutex; // protege simulation_end
	t_philo			*philo;
}	t_table;

/* parse */
int	parse_args(t_table *table, int ac, char **av);
int	ft_atoi_positive(const char *str, long *result);

/* init */
int	init_table(t_table *table);
int	init_philos(t_table *table);

/* time */
long	get_time_ms(void);
long	timestamp_ms(long start_time);
void	precise_sleep(t_table *table, long duration_ms);

/* utils */
int		simulation_finished(t_table *table);
void	set_simulation_end(t_table *table);
void	print_status(t_philo *philo, char *msg);

/* routine */
void	*philo_routine(void *args);

/* actions */
int		take_forks(t_philo *philo);
void	eat_action(t_philo *philo);
void	sleep_action(t_philo *philo);
void	think_action(t_philo *philo);

/* monitor */
int	start_simulation(t_table *table);
int	monitor_loop(t_table *table);
int	all_ate_enough(t_table *table);

/* cleanup */
void	destroy_all(t_table *table);

# endif
