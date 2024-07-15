/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:34:58 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/15 15:36:45 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# define WIDTH 900
# define HEIGHT 900
# define ITERATION 150
# define ZOOM 1
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define KEY_A 97
# define KEY_S 115
# define KEY_PLUS 1
# define KEY_MINUS 0

typedef struct s_pos {
	double	x;
	double	y;
}	t_pos;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	char	*name;
	int		line_bytes;
	int		pixel_bits;
	double	max_r;
	double	min_r;
	double	max_i;
	double	min_i;
	double	max_iter;
	int		ac;
	t_pos	c_julia;
}	t_data;

void	check_and_set(t_data *fcl, char **av, int ac);

void	put_pxl(t_data *data, int x, int y, int color);

int		ft_color(t_data *fcl, double iter);

void	algo_julia(t_data *fcl);

void	algo_mandelbrot(t_data *fcl);

void	algo_burning(t_data *fcl);

int		pixel_index(int x, int y, int line_bytes, int pixel_bits);

int		handle_key(int keycode, t_data *data);

int		handle_close(t_data *data);

int		mouse_hook(int button, int x, int y, t_data *fcl);

void	error_input(void);

double	ft_atof(char *str);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

size_t	ft_strlen(const char *s);

void	clean(t_data *fcl);

void	move_up(t_data *fcl);

void	move_down(t_data *fcl);

void	move_left(t_data *fcl);

void	move_right(t_data *fcl);

void	key_iterate(t_data *fcl, int choice);

void	hook_put(t_data *fcl);

#endif