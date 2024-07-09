/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:40:55 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/09 18:28:33 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_mandelbrot(int x, int y, int max_iter, t_data fcl)
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
	int		x;
	int		y;
	int		pixel_idx;
	double	iter;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			iter = calcul_iter(x, y, fcl->max_iter, fcl);
			pixel_idx = pixel_index(x, y, fcl->line_bytes, fcl->pixel_bits);
			//j 'ai mon iter et mon pixel_idx donc maintenant je peux faire le choix des couleurs
		}
	}
}