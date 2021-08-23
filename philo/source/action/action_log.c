#include "philosophers/action.h"
#include "philosophers/time.h"
#include "philosophers/philo.h"
#include "philosophers/game.h"
#include "philosophers/utils.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	action_log(t_action action, t_philo *target, t_game *game)
{
	t_msecs	elapsed;
	char	*action_string;

	if (game->status == GS_OVER)
		return ;
	elapsed = time_now() - game->start_time;
	action_string = action_to_string(action);
	if (action == ACTION_DIED)
	{
		game->status = GS_OVER;
	}
	pthread_mutex_lock(&game->logging);
	utils_printnbr(elapsed);
	write(1, " ", 1);
	utils_printnbr(target->id);
	utils_print(action_string);
	pthread_mutex_unlock(&game->logging);
}
