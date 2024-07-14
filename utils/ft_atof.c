/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:09:00 by yohurteb          #+#    #+#             */
/*   Updated: 2024/07/14 16:02:24 by yohurteb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	verif_param(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
		{
			write(2, "Bad parameter\n", 14);
			exit(1);
		}
		i++;
	}
}

int	verif_sign(char *str, int *i)
{
	if (str[*i] == '-')
	{
		*i = *i + 1;
		return (-1);
	}
	return (1);
}

double	ft_atof(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	decimal = 0.1;
	i = 0;
	while (str[i] >= 9 && str[i] <= 13 && str[i] == ' ')
		i++;
	sign = verif_sign(str, &i);
	verif_param(&str[i]);
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result + (str[i++] - '0') * decimal;
		decimal /= 10;
	}
	return (result * sign);
}
