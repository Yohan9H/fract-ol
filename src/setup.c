/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:36:41 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/08 16:49:08 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_madelbrot(t_data *fractol, char *type)
{
	fractol->name = type;
	fractol->width = WIDTH;
	fractol->height = HEIGHT;
	fractol->iterations = ITERATION;
	fractol->x = 0;
	fractol->y = 0;
}

void	setup_julia(t_data *fractol, char *type)
{
	
}