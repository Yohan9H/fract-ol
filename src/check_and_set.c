/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:14:56 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/08 15:35:29 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_and_set(t_data *fcl, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 0 && ft_strlen(av[1]) == 10)
		setup_mandelbrot(&fcl, av[1]);
	else if (ft_strncmp(av[1], "julia", 5) == 0 && ft_strlen(av[1]) == 5)
		setup_julia(&fcl, av[1]);
	else // faire un check pour les parametres des fractoles '2.03'
		error_input();
}
