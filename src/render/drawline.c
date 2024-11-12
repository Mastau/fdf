/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:39:59 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/12 16:57:24 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	ft_abs(int n)
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

void	ft_drawline(t_mlx *mlx, int *matrix1, int *matrix2)
{
	t_line	x;
	t_line	y;
	double	max;

	x.pt1 = matrix1[0];
	x.pt2 = matrix1[1];
	y.pt1 = matrix2[0];
	y.pt2 = matrix2[1];
	x.diff = x.pt2 - x.pt1;
	y.diff = y.pt2 - y.pt1;
	x.i = (double)x.pt1;
	y.i = (double)y.pt1;
	max = (double)ft_abs(ft_max(ft_abs(y.diff), ft_abs(x.diff)));
	x.d = (double)x.diff / max;
	y.d = (double)y.diff / max;
	while (x.i != x.pt2 && y.i != y.pt2)
	{
		if (fabs(x.i - x.pt2) < 1e-1f && fabs(y.i - y.pt2) < 1e-1f)
			break ;
		x.i += x.d;
		y.i += y.d;
		if ((x.i >= 0 && x.i < WIDTH) && (y.i >= 0 && y.i < HEIGHT))
			mlx_set_image_pixel(mlx->con, mlx->img, (int)x.i, (int)y.i,
				0xFFFFFFFF);
	}
}
