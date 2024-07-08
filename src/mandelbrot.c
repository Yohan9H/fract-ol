/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:40:55 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/08 17:29:33 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_mandelbrot(t_data *fcl)
{
	int		i;
	double	tmp;
	t_pos	c;
	t_pos	z;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (fcl->x / fcl->zoom) + fcl->offset.x;
	c.y = (fcl->y / fcl->zoom) + fcl->offset.y;
	while (i < ITERATION)
	{
		tmp = z.x * z.x - z.y *z.y + c.x;
		z.y = 2. * z.x * z.y + c.y;
		z.x = tmp;
		if (z.x * z.x + z.y * z.y >= 4) // a voir si '>' ou '>='
		{
			
			break;
		}
	}
}