/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arrow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:39:06 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/15 15:37:23 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_iterate(t_data *fcl, int choice)
{
	if (choice == KEY_PLUS)
	{
		fcl->max_iter += 50.0;
		hook_put(fcl);
	}
	else if (choice == KEY_MINUS)
	{
		fcl->max_iter -= 50.0;
		hook_put(fcl);
	}
}

void	move_up(t_data *fcl)
{
	double	move;

	move = (fcl->max_i - fcl->min_i) * 0.1;
	fcl->min_i -= move;
	fcl->max_i -= move;
}

void	move_down(t_data *fcl)
{
	double	move;

	move = (fcl->max_i - fcl->min_i) * 0.1;
	fcl->min_i += move;
	fcl->max_i += move;
}

void	move_left(t_data *fcl)
{
	double	move;

	move = (fcl->max_r - fcl->min_r) * 0.1;
	fcl->min_r -= move;
	fcl->max_r -= move;
}

void	move_right(t_data *fcl)
{
	double	move;

	move = (fcl->max_r - fcl->min_r) * 0.1;
	fcl->min_r += move;
	fcl->max_r += move;
}
