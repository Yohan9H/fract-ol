/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:26:27 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/09 17:01:29 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color(t_color *color)
{
	color->r = 23;
	color->g = 205;
	color->b = 84;
}

int	create_color(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

int	color_set_win(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}