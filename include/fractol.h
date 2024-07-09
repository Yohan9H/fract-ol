/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:34:58 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/09 17:54:03 by yohurteb         ###   ########.fr       */
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
	int		line_bytes;
	int		pixel_bits;
	int		color;
	double	max_r;
	double	min_r;
	double	max_i;
	double	min_i;
	double	max_iter;
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

int		create_color(t_color color);

int		color_set_win(int r, int g, int b);

void	init_color(t_color *color);

void	check_and_set(t_data *fcl, char **av);

int		pixel_index(int x, int y, int line_bytes, int pixel_bits);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *s);

#endif