/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:39:59 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/10 13:26:52 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	ft_abs(int	n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

void ft_drawline(t_mlx *mlx, int *matrix1, int *matrix2)
{
	t_line x;
	t_line y;
	float	max;

	x.pt1 = matrix1[0];
	x.pt2 = matrix1[1];
	y.pt1 = matrix2[0];
	y.pt2 = matrix2[1];
	x.diff = x.pt2 - x.pt1;
	y.diff = y.pt2 - y.pt1;
	x.i = (float) x.pt1;
	y.i = (float) y.pt1;
	max = (float)ft_abs(ft_max(ft_abs(y.diff), ft_abs(x.diff)));
	x.d = (float)x.diff / max;
	y.d = (float)y.diff / max;
	while (x.i != x.pt2 && y.i != y.pt2)
	{
		if (fabs(x.i - x.pt2) < 1e-1f && fabsf(y.i - y.pt2) < 1e-1f)
			break;
		x.i += x.d;
		y.i += y.d;	
		mlx_pixel_put(mlx->con, mlx->win, roundf(x.i), roundf(y.i), 0xFFFFFFFF);
	}
}
