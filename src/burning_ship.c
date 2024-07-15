/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:12:31 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/15 10:56:26 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	make_burning(int x, int y, int max_iter, t_data *fcl)
{
	t_pos	c;
	t_pos	z;
	int		iter;
	double	temp;

	c.x = fcl->min_r + x * (fcl->max_r - fcl->min_r) / WIDTH;
	c.y = fcl->min_i + y * (fcl->max_i - fcl->min_i) / HEIGHT;
	z.x = 0.0;
	z.y = 0.0;
	iter = 0;
	while (z.x * z.x + z.y * z.y < 4.0 && iter < max_iter)
	{
		temp = z.x * z.x - z.y * z.y + c.x;
		z.y = fabs(2.0 * z.x * z.y + c.y);
		z.x = fabs(temp);
		iter++;
	}
	return (iter);
}

void	algo_burning(t_data *fcl)
{
	t_pos	coor;
	double	iter;
	int		color;

	coor.y = 0;
	while (coor.y < HEIGHT)
	{
		coor.x = 0;
		while (coor.x < WIDTH)
		{
			iter = make_burning(coor.x, coor.y, fcl->max_iter, fcl);
			if (iter == fcl->max_iter)
				put_pxl(fcl, coor.x, coor.y, 0x000000);
			else
			{
				color = ft_color(fcl, iter);
				put_pxl(fcl, coor.x, coor.y, color);
			}
			coor.x++;
		}
		coor.y++;
	}
}
