/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:25:17 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/10 14:48:17 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	handle_key(int keycode, t_data *fcl)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(fcl->mlx, fcl->mlx_win);
		exit(0);
	}
	return (0);
}

int	handle_close(t_data *fcl)
{
	mlx_destroy_window(fcl->mlx, fcl->mlx_win);
	exit(0);
	return (0);
}
