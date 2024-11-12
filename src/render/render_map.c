/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:30:42 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/12 18:49:52 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_point	calcul_iso(double x, double y, double z, double zoom)
{
	t_point	point;

	point.x = (x - y);
	point.y = (x + y) * sin(0.523599) - z;
	point.x *= zoom;
	point.y *= zoom;
	return (point);
}

void	draw_wireframe(t_map *map)
{
	int		x;
	int		y;
	int		matrix0[2];
	int		matrix1[2];
	t_point	p1;
	t_point	p2;
	t_point	p3;

	y = 0;
	map->mlx.img = mlx_new_image(map->mlx.con, WIDTH, HEIGHT);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			p1 = calcul_iso(x * SCALE, y * SCALE, map->y[y * map->width + x],
					map->zoom);
			matrix0[0] = round(p1.x + (double)WIDTH / 2);
			matrix1[0] = round(p1.y + (double)HEIGHT / 16);
			if (x + 1 < map->width)
			{
				p2 = calcul_iso((x + 1) * SCALE, y * SCALE, map->y[y * map->width + (x
							+ 1)], map->zoom);
				matrix0[1] = round(p2.x + (double)WIDTH / 2);
				matrix1[1] = round(p2.y + (double)HEIGHT / 16);
				ft_drawline(&map->mlx, matrix0, matrix1);
			}
			if (y + 1 < map->height)
			{
				p3 = calcul_iso(x * SCALE, (y + 1) * SCALE, map->y[(y + 1)
						* map->width + x], map->zoom);
				matrix0[1] = round(p3.x + (double)WIDTH / 2);
				matrix1[1] = round(p3.y + (double)HEIGHT / 16);
				ft_drawline(&map->mlx, matrix0, matrix1);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx.con, map->mlx.win,map->mlx.img, 0, 0);
}

