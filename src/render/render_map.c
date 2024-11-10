/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:30:42 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/10 14:16:59 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

t_point project_iso(double x, double y, double z, double zoom) {
    t_point point;

	point.x = (x - y) * cos(0.523599);
    point.y = (x + y) * sin(0.523599) - z;
	point.x *= zoom;
	point.y *= zoom;
    return (point);
}



void draw_wireframe(t_map *map) {
    int x; 
	int	y;
    int matrix0[2]; 
	int	matrix1[2];  
    t_point p1;
	t_point p2;
	t_point p3;

	y = 0;
	while (y < map->height) {
		x = 0;
        while (x < map->width) {
            p1 = project_iso(x * 20, y * 20, map->y[y * map->width + x], map->zoom);
            matrix0[0] = roundf(p1.x + (float)WIDTH / 2);
            matrix1[0] = round(p1.y + (float)HEIGHT / 2);
            if (x + 1 < map->width) {
                p2 = project_iso((x + 1) * 20, y * 20, map->y[y * map->width + (x + 1)], map->zoom);
                matrix0[1] = round(p2.x + (float)WIDTH / 2);
                matrix1[1] = round(p2.y + (float)HEIGHT / 2);
                ft_drawline(&map->mlx, matrix0, matrix1);
            }
            if (y + 1 < map->height) {
                p3 = project_iso(x * 20, (y + 1) * 20, map->y[(y + 1) * map->width + x], map->zoom);
				matrix0[1] = round(p3.x + (float)WIDTH / 2);
                matrix1[1] = round(p3.y + (float)HEIGHT / 2);
                ft_drawline(&map->mlx, matrix0, matrix1);
            }
			x++;
        }
		y++;
    }
}


