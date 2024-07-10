/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:26:27 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/10 16:34:18 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	pixel_index(int x, int y, int line_bytes, int pixel_bits)
{
	int	pixel_index;

	pixel_index = y * line_bytes + x * (pixel_bits / 8);
	return (pixel_index);
}

void put_pixel(t_data *fcl, int x, int y, int color)
{
	char *dst;

	dst = fcl->addr + pixel_index(x, y, fcl->line_bytes, fcl->pixel_bits);
	*(unsigned int*)dst = color;
}
