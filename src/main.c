/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:23:49 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/14 16:52:24 by yohurteb         ###   ########.fr       */
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
	fcl->pixel_bits = pixel_bits;
	if (ft_strncmp(fcl->name, "mandelbrot", 10) == 0)
		algo_mandelbrot(fcl);
	else if (ft_strncmp(fcl->name, "julia", 5) == 0)
		algo_julia(fcl);
	else if (ft_strncmp(fcl->name, "burning_ship", 12) == 0)
		algo_burning(fcl);
}

void	init_struct(t_data *fcl)
{
	fcl->addr = NULL;
	fcl->mlx = mlx_init();
	if (!fcl->mlx)
	{
		clean(fcl);
		exit(1);
	}
	fcl->max_iter = ITERATION;
	fcl->mlx_win = mlx_new_window(fcl->mlx, WIDTH, HEIGHT, fcl->name);
	if (!fcl->mlx_win)
	{
		clean(fcl);
		exit(1);
	}
	fcl->img = mlx_new_image(fcl->mlx, WIDTH, HEIGHT);
	if (!fcl->img)
	{
		clean(fcl);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data	fcl;

	if (ac == 2 || ac == 4)
	{
		check_and_set(&fcl, av, ac);
		init_struct(&fcl);
		make_image(&fcl);
		mlx_put_image_to_window(fcl.mlx, fcl.mlx_win, fcl.img, 0, 0);
		mlx_hook(fcl.mlx_win, 2, 1L << 0, handle_key, &fcl);
		mlx_hook(fcl.mlx_win, 17, 0, handle_close, &fcl);
		mlx_mouse_hook(fcl.mlx_win, mouse_hook, &fcl);
		mlx_loop(fcl.mlx);
		clean(&fcl);
		exit(0);
	}
	else
		error_input();
	return (0);
}
