/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:30:42 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/08 17:46:52 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	generate_map(t_map *map)
{
	int x_offset;
    int y_offset;
	int	i;
	int	j;

	i = 0;
	j = 0;
	x_offset = WIDTH / (map->width + 1);
	y_offset = HEIGHT / (map->height + 1);
    while (i < map->height) {
        while (j < map->width) {
			mlx_pixel_put(map->mlx.con, map->mlx.win, (j * x_offset), (i * y_offset), 0xFF223344);
			j++;
        }
		i++;
		j = 0;
    }
}
