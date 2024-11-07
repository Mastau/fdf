/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:39:59 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/07 18:40:50 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_drawline(void *data)
{
	t_mlx *mlx;
	int	diffx;
	int	diffy;
	float	max;
	float	dx;
	float	dy;
	float	ix;
	float	iy;

	mlx = (t_mlx *)data;
	diffx = mlx->pt2->x - mlx->pt1->x;
	diffy = mlx->pt2->y - mlx->pt1->y;
	ix = (float) mlx->pt1->x;
	iy = (float) mlx->pt1->y;
	max = (float)ft_abs(ft_max(ft_abs(diffy), ft_abs(diffx)));
	dx = (float)diffx / max;
	dy = (float)diffy / max;
	ft_printf("First pt x:%d y:%d\n", mlx->pt1->x, mlx->pt1->y);
	ft_printf("End pt x:%d y:%d\n", mlx->pt1->x, mlx->pt1->y);
	while (ix != mlx->pt2->x && iy != mlx->pt2->y)
	{
		if (fabs(ix - mlx->pt2->x) < 1e-1f && fabsf(iy - mlx->pt2->y) < 1e-1f)
			break;
		ix += dx;
		iy += dy;	
		mlx_pixel_put(mlx->mlx, mlx->win, roundf(ix), roundf(iy), 0xFFFF00FF);
	}
}
