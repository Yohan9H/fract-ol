/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:26:27 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/14 17:27:38 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(t_data *fcl, double iter)
{
	double	frac_i;
	double	color;

	frac_i = (double)iter / fcl->max_iter;
	color = (int)(9 * (1 - frac_i) * frac_i * frac_i * frac_i * 255) << 16
		| (int)(15 * (1 - frac_i)
			* (1 - frac_i) * frac_i * frac_i * 255) << 8
		| (int)(8.5 * (1 - frac_i)
			* (1 - frac_i) * (1 - frac_i) * frac_i * 255);
	return (color);
}

int	pixel_index(int x, int y, int line_bytes, int pixel_bits)
{
	int	pixel_index;

	pixel_index = y * line_bytes + x * (pixel_bits / 8);
	return (pixel_index);
}

void	put_pxl(t_data *fcl, int x, int y, int color)
{
	char	*dst;

	dst = fcl->addr + pixel_index(x, y, fcl->line_bytes, fcl->pixel_bits);
	*(unsigned int *)dst = color;
}
