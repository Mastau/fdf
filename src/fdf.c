
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
	t_mlx* mlx = (t_mlx *)param;
	if (key == 41)
		mlx_loop_end(mlx->con);
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
	mlx_on_event(mlx.con, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	mlx_on_event(mlx.con, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	//debug(map);
	generate_map(map);
	mlx_loop(mlx.con);
	mlx_destroy_window(mlx.con, mlx.win);
	mlx_destroy_display(mlx.con);
}
