/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:29:35 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/12 18:41:37 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "maths.h"
#include "mlx.h"
#include "parsing.h"
#include "render.h"

int	window_hook(int event, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (event == 0)
	{
		mlx_destroy_image(map->mlx.con, map->mlx.img);
		mlx_loop_end(map->mlx.con);
	}
	return (0);
}

int	key_hook(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (key == 41)
	{
		mlx_destroy_image(map->mlx.con, map->mlx.img);
		mlx_loop_end(map->mlx.con);
	}
	if (key == 81 || key == 82)
	{
		if (key == 82)
			map->zoom *= 1.10;
		if (key == 81)
			map->zoom /= 1.10;
		if (map->zoom < 0.1)
			map->zoom = 0.1;
		if (map->zoom > 10.0)
			map->zoom = 10.0;
		mlx_destroy_image(map->mlx.con, map->mlx.img);
		draw_wireframe(map);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	t_map	*map;

	if (ac != 2)
		return (0);
	map = parsing(av[1]);
	if (map == NULL)
		return (0);
	mlx.con = mlx_init();
	mlx.win = mlx_new_window(mlx.con, WIDTH, HEIGHT, "fdf");
	map->mlx = mlx;
	map->zoom = 1.0;
	mlx_set_fps_goal(mlx.con, 10);
	mlx_on_event(mlx.con, mlx.win, MLX_WINDOW_EVENT, window_hook, map);
	mlx_on_event(mlx.con, mlx.win, MLX_KEYDOWN, key_hook, map);
	draw_wireframe(map);
	mlx_loop(mlx.con);
	mlx_destroy_window(mlx.con, mlx.win);
	mlx_destroy_display(mlx.con);
	free(map->y);
	free(map);
}
