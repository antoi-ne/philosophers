#ifndef ACTION_H
# define ACTION_H

# include "philosophers/philo.h"
# include "philosophers/game.h"

typedef enum e_action
{
	ACTION_FORK = 0,
	ACTION_EATING = 1,
	ACTION_THINKING = 2,
	ACTION_SLEEPING = 3,
	ACTION_DIED = 4
}	t_action;

char	*action_to_string(t_action action);

void	action_log(t_action action, t_philo *target, t_game *game);

void	action_run(t_action action, t_philo *target, t_game *game);

void	action_fork(t_game *philo, t_philo * target);

#endif