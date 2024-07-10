/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:44:48 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/10 16:57:50 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	make_julia(int x, int y, int max_iter, t_data *fcl)
{
	t_pos	z;
	int		iter;
	double	temp;
	
	z.x = fcl->min_r + x * (fcl->max_r - fcl->min_r) / WIDTH;
	z.y = fcl->min_i + y * (fcl->max_i - fcl->min_i) / HEIGHT;
	iter = 0;
	while (z.x * z.x + z.y * z.y < 4.0 && iter < max_iter)
	{
		temp = z.x * z.x - z.y * z.y + fcl->c_julia.x;
		z.y = 2.0 * z.x * z.y + fcl->c_julia.y;
		z.x = temp;
		iter++;
	}
	return (iter);
}

void	algo_julia(t_data *fcl)
{
	t_pos	coor;
	double	iter;

	coor.y = 0;
	while (coor.y < HEIGHT)
	{
		coor.x = 0;
		while (coor.x < WIDTH)
		{
			iter = make_julia(coor.x, coor.y, fcl->max_iter, fcl);
			if (iter == fcl->max_iter)
				put_pixel(fcl, coor.x, coor.y, 0x000000);
			else
				put_pixel(fcl, coor.x, coor.y, 0xFFFFFF * (iter / fcl->max_iter));
			coor.x++;
		}
		coor.y++;
	}
}
