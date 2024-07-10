/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:14:56 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/10 15:01:43 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_input()
{
	write(2, "---WRONG---\n'mandelbrot' or 'julia'", 35);
	exit(1);
}

void	setup_struct(t_data *fcl, char *type, int choice)
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
		fcl->min_i = fcl->max_i + (fcl->max_r - fcl->min_r) * HEIGHT / WIDTH;
	}
}

void	check_and_set(t_data *fcl, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0 && ft_strlen(av[1]) == 10)
		setup_struct(fcl, av[1], 1);
	else if (ft_strncmp(av[1], "julia", 5) == 0 && ft_strlen(av[1]) == 5)
		setup_struct(fcl, av[1], 2);
	else // faire un check pour les parametres des fractoles '2.03'
		error_input();
}
