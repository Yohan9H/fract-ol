/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:23:49 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/09 17:53:00 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_image(t_data *fcl)
{
	int	pixel_bits;
	int	line_bytes;
	int	endian;

	fcl->addr = mlx_get_data_addr(fcl->img, &pixel_bits,
			&line_bytes, &endian);
	fcl->line_bytes = line_bytes;

	set_window(fcl, line_bytes, pixel_bits);
	if (fcl->name == "mandelbrot")
		algo_mandelbrot();
}
void	init_struct(t_data *fcl)
{
	t_color color;

	fcl->addr = NULL;
	init_color(&color);
	fcl->mlx = mlx_init();
	if (!fcl->mlx)
		exit(1);
	fcl->color = create_color(color);
	fcl->max_iter = ITERATION;
	fcl->mlx_win = mlx_new_window(fcl->mlx, WIDTH, HEIGHT, fcl->name);
	fcl->img = mlx_new_image(fcl->mlx, WIDTH, HEIGHT);
}

int	main(int ac, char **av)
{
	t_data	fcl;

	if (ac >= 2 && ac <= 4)
	{
		check_and_set(&fcl, av);
		init_struct(&fcl);
		make_image(&fcl);
		// hooks
		// loop
	}
	else
		error_input();
}
