/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:40:55 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/10 15:14:19 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	make_mandelbrot(int x, int y, int max_iter)
{
	t_pos	c;
	t_pos	z;
	int		iter;
	double	temp;

	c.x = (x - WIDTH / 2.0) * 4.0 / WIDTH;
	c.y = (y - WIDTH / 2.0) * 4.0 / WIDTH;
	z.x = 0.0;
	z.y = 0.0;
	iter = 0;
	while (z.x * z.x + z.y * z.y < 4.0 && iter < max_iter)
	{
		temp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2.0 * z.x * z.y + c.y;
		z.x = temp;
		iter++;
	}
	return (iter);
}

void	algo_mandelbrot(t_data *fcl)
{
	t_pos	coor;
	int		i;
	int		pixel_idx;
	double	iter;

	coor.x = 0;
	coor.y = 0;
	i = 0;
	while (coor.y < HEIGHT)
	{
		while (coor.x < WIDTH)
		{
			iter = make_mandelbrot(coor.x, coor.y, fcl->max_iter);
			pixel_idx = pixel_index(coor.x, coor.y, fcl->line_bytes, fcl->pixel_bits);
			if (iter == fcl->max_iter)
				put_pixel(fcl, coor.x, coor.y, 0x0000FF);
			else
				put_pixel(fcl, coor.x, coor.y, 0x138ef2 * i);
			i++;
			coor.x++;
		}
		coor.x = 0;
		coor.y++;
	}
}
