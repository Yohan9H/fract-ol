/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:34:58 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/08 17:18:53 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# define WIDTH 900
# define HEIGHT 900
# define ITERATION 150
# define ZOOM 1

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	char	*name;
	double	zoom;
	double	y;
	double	x;
	t_pos	offset;
	t_color	color;
}	t_data;

typedef struct s_pos {
	double x;
	double y;
}	t_pos;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

void	check_and_set(t_data *fcl, char **av);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *s);

#endif