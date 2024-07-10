/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:34:14 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/10 11:25:09 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

unsigned int	color_to_int(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8)); // see more
	*(unsigned int*)dst = color;
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == 112)
	{
		data->color = (2125 + data->color) % 0xFFFFFF;
		draw_image(data);
	}
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}
void	draw_image(t_data *data)
{
	int	x;
	int	y;
	
    int x1 = 100, y1 = 100;
    int x2 = 400, y2 = 400;


    if (x1 > x2) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }

    for (x = x1; x <= x2; x++) {
        for (y = y1; y <= y2; y++) {
            my_mlx_pixel_put(data, x, y, data->color);
        }
    }
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	main()
{
	t_data	data;
	t_color	color;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 900, 900, "fractol");
	data.img = mlx_new_image(data.mlx, 900, 900);
	color.r = 228;
	color.g = 15;
	color.b = 13;
	data.color = color_to_int(color);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	draw_image(&data);
	mlx_hook(data.mlx_win, 2, 1L<<0, handle_key, &data);
	mlx_hook(data.mlx_win, 17, 0, handle_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
