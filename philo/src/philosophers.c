/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers                                        :+:      :+:* :+:* * */
/*                                                    +:+ +:+         +:+     */
/*   By: hriser <hriser@21-school.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 19:00:00 by hriser            #+#    #+#             */
/*   Updated: 1970/01/01 19:00:00 by hriser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_vars *vars, int argc, char **argv)
{
	vars->number_of_philosophers = ft_atoi(argv[1]);
	vars->time_to_die = ft_atoi(argv[2]);
	vars->time_to_eat = ft_atoi(argv[3]);
	vars->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		vars->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		vars->number_of_times_each_philosopher_must_eat = -1;
}

void	*do_smth(void *vars)
{
	t_vars	*v;
	t_time	time;

	v = (t_vars *) vars;
	gettimeofday(&time, DST_NONE);
	printf("%ld%d X is eating\n", time.tv_sec, time.tv_usec);
	usleep(v->time_to_sleep * 1000);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;
	pthread_t	thread;
	t_time		tv;

	vars = malloc(sizeof(t_vars));
	init(vars, argc, argv);
	pthread_create(&thread, 0, &do_smth, (void *) vars);
	printf("%d\n", pthread_join(thread, 0));
	gettimeofday(&tv, DST_NONE);
	printf("%ld %d\n", tv.tv_sec, tv.tv_usec);
}
