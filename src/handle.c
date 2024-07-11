/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:25:17 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/11 14:26:22 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	handle_key(int keycode, t_data *fcl)
{
	if (keycode == 65307)
		clean(fcl);
	return (0);
}

int	handle_close(t_data *fcl)
{
	clean(fcl);
	return (0);
}
