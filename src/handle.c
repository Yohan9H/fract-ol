/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:25:17 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/14 16:46:28 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keycode, t_data *fcl)
{
	if (keycode == 65307)
	{
		clean(fcl);
		exit(0);
	}
	return (0);
}

int	handle_close(t_data *fcl)
{
	clean(fcl);
	exit(0);
	return (0);
}

void	mouse_hook_put(t_data *fcl)
{
	if (ft_strncmp(fcl->name, "mandelbrot", 10) == 0)
		algo_mandelbrot(fcl);
	if (ft_strncmp(fcl->name, "julia", 5) == 0)
		algo_julia(fcl);
	if (ft_strncmp(fcl->name, "burning_ship", 12) == 0)
		algo_burning(fcl);
	mlx_put_image_to_window(fcl->mlx, fcl->mlx_win, fcl->img, 0, 0);
}

void	zoom_mouse(t_data *fcl, double zoom, int mse_x, int mse_y)
{
	double	mse_r;
	double	mse_i;
	double	new_width;
	double	new_height;

	mse_r = fcl->min_r + ((double)mse_x / WIDTH) * (fcl->max_r - fcl->min_r);
	mse_i = fcl->min_i + ((double)mse_y / HEIGHT)
		* (fcl->max_i - fcl->min_i);
	new_width = (fcl->max_r - fcl->min_r) * zoom;
	new_height = (fcl->max_i - fcl->min_i) * zoom;
	fcl->min_r = mse_r - new_width / 2;
	fcl->max_r = mse_r + new_width / 2;
	fcl->min_i = mse_i - new_height / 2;
	fcl->max_i = mse_i + new_height / 2;
}

int	mouse_hook(int button, int x, int y, t_data *fcl)
{
	if (button == 4)
	{
		zoom_mouse(fcl, 0.90, x, y);
		mouse_hook_put(fcl);
	}
	if (button == 5)
	{
		zoom_mouse(fcl, 1.10, x, y);
		mouse_hook_put(fcl);
	}
	return (0);
}
