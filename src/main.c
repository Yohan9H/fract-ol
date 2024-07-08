/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:23:49 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/08 17:18:59 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_image(t_data *fcl)
{
	if (ft_strncmp(fcl->name, "mandelbrot", 10) == 0)
		make_mandelbrot();
	else if (ft_strncmp(fcl->name, "julia", 5) == 0)
		make_julia();
	mlx_put_image_to_window(fcl->mlx, fcl->mlx_win, fcl->img, fcl->x, fcl->y);
}

void	error_input()
{
	write(2, "---WRONG---\n'mandelbrot' or 'julia'", 35);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	fcl;

	if (ac >= 2 && ac <= 4)
	{
		check_and_set(&fcl, av);
		fcl.mlx = mlx_init();
		fcl.mlx_win = mlx_new_window(fcl.mlx_win, WIDTH, HEIGHT, fcl.name);
		fcl.img = mlx_new_image(fcl.mlx, WIDTH, HEIGHT);
		make_image(&fcl);
		// hooks
		// loop
	}
	else
		error_input();
}
