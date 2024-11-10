
#include "mlx.h"
#include "libft.h"
#include "parsing.h"
#include "render.h"
#include "maths.h"
#include "fdf.h"


int window_hook(int event, void* param)
{
	if(event == 0)
		mlx_loop_end(((t_mlx*)param)->con);
	return 0;
}

int	key_hook(int key, void *param)
{
	t_map *map;
	map = (t_map*)param;
	if (key == 41)
		mlx_loop_end(map->mlx.con);
	if (key == 81 || key == 82)
	{
		if (key == 81)
			map->zoom *= 1.1;
		if (key == 82)
			map->zoom /= 1.1;
		if (map->zoom < 0.1)
			map->zoom = 0.1;
		if (map->zoom > 10.0)
			map->zoom = 10.0;
		mlx_clear_window(map->mlx.con, map->mlx.win);
		draw_wireframe(map);
	}
	return (0);
}

void	debug(t_map *map)
{
	int	i;
	if (map == NULL) {
		ft_printf("Erreur : map est NULL\n");
		return;
    }
	if (map->y == NULL) {
		ft_printf("Erreur : map->y est NULL\n");
		return;
    }
	i = 0;
	ft_printf("DEBUG T_MAP\n Width: %d height: %d\n", map->width, map->height);
	while (i < (map->width * map->height))
	{	
		ft_printf("%d ", map->y[i]);
		if ((i + 1) % map->width == 0)
			ft_printf("%c", '\n');
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	t_mlx	mlx;
	t_map	*map;

	map = parsing(av[1]);
	mlx.con = mlx_init();
	mlx.img = NULL;
	mlx.win = mlx_new_window(mlx.con, 1280, 720, "fdf");
	map->mlx = mlx;
	map->zoom = 0.5;
	mlx_on_event(mlx.con, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	mlx_on_event(mlx.con, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	//debug(map);
	draw_wireframe(map);
	mlx_loop(mlx.con);
	mlx_destroy_window(mlx.con, mlx.win);
	mlx_destroy_display(mlx.con);
}
