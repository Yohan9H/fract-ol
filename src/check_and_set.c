/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:14:56 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/14 17:04:28 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_input(void)
{
	write(2, "---WRONG---\n\n", 13);
	write(2, "'mandelbrot'\n --OR--\n", 21);
	write(2, "'julia (double, double)'\n --OR--\n", 33);
	write(2, "'burning_ship'\n", 15);
	exit(1);
}

void	param_user(t_data *fcl, char **av)
{
	if (fcl->ac > 2)
	{
		fcl->c_julia.x = ft_atof(av[2]);
		fcl->c_julia.y = ft_atof(av[3]);
	}
	else
	{
		fcl->c_julia.x = -0.8;
		fcl->c_julia.y = 0.156;
	}
}

void	setup_struct(t_data *fcl, char *type, int choice, char **av)
{
	if (choice == 1)
	{
		fcl->name = type;
		fcl->max_r = 1.0;
		fcl->min_r = -2.0;
		fcl->max_i = -1.5;
		fcl->min_i = fcl->max_i + (fcl->max_r - fcl->min_r) * HEIGHT / WIDTH;
	}
	else if (choice == 2)
	{
		fcl->name = type;
		fcl->max_r = 2.0;
		fcl->min_r = -2.0;
		fcl->max_i = -2.0;
		param_user(fcl, av);
		fcl->min_i = fcl->max_i + (fcl->max_r - fcl->min_r) * HEIGHT / WIDTH;
	}
	else if (choice == 3)
	{
		fcl->name = type;
		fcl->max_r = 2.0;
		fcl->min_r = -2.0;
		fcl->max_i = 2.0;
		fcl->min_i = -2.0;
	}
}

void	check_and_set(t_data *fcl, char **av, int ac)
{
	fcl->ac = ac;
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0 && ft_strlen(av[1]) == 10)
		setup_struct(fcl, av[1], 1, av);
	else if (ft_strncmp(av[1], "julia", 5) == 0 && ft_strlen(av[1]) == 5)
		setup_struct(fcl, av[1], 2, av);
	else if (ft_strncmp(av[1], "burning_ship", 12) == 0
		&& ft_strlen(av[1]) == 12)
		setup_struct(fcl, av[1], 3, av);
	else
		error_input();
}
