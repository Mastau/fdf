
#include "mlx.h"
#include "libft.h"
#include "fdf.h"
#include <SDL2/SDL_mouse.h>

int	ft_abs(int	n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

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



int	main(void)
{
	t_mlx	mlx;
	
	mlx.con = mlx_init();
	mlx.win = mlx_new_window(mlx.con, 1280, 720, "fdf");
	mlx_on_event(mlx.con, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	mlx_on_event(mlx.con, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_loop(mlx.con);
	mlx_destroy_window(mlx.con, mlx.win);
	mlx_destroy_display(mlx.con);
}
