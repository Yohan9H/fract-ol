/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:21:01 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/14 14:46:01 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean(t_data *fcl)
{
	if (fcl->img)
		mlx_destroy_image(fcl->mlx, fcl->img);
	if (fcl->mlx_win)
		mlx_destroy_window(fcl->mlx, fcl->mlx_win);
	if (fcl->mlx)
	{
		mlx_destroy_display(fcl->mlx);
		free(fcl->mlx);
	}
}
