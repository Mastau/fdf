
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
typedef struct
{
	void* mlx;
	void* win;
	void* logo_png;
	void* logo_jpg;
	void* logo_bmp;
	void* img;
} mlx_t;

int window_hook(int event, void* param)
{
	if(event == 0)
		mlx_loop_end(((mlx_t*)param)->mlx);
	return 0;
}

int	key_hook(int key, void *param)
{
	mlx_t* mlx = (mlx_t *)param;
	int	x;
	int	y;
	if (key == 44)
	{
		mlx_mouse_get_pos(mlx->mlx, &x, &y);
		ft_printf("Mouse pos x: %d y: %d\n", x, y);
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFF0000);
	}
	else if (key == 4)
	{
		mlx_mouse_get_pos(mlx->mlx, &x, &y);
		ft_printf("Mouse pos x: %d y: %d\n", x, y);
		mlx_pixel_put(mlx->mlx, mlx->win, x, y, 0xFFFF0000);

		mlx_pixel_put(mlx->mlx, mlx->win, x+1, y, 0xFFFF0000);
		mlx_pixel_put(mlx->mlx, mlx->win, x-1, y, 0xFFFF0000);
		
		mlx_pixel_put(mlx->mlx, mlx->win, x, y+1, 0xFFFF0000);
		mlx_pixel_put(mlx->mlx, mlx->win, x, y-1, 0xFFFF0000);
	}
	else if (key == 41)
		mlx_loop_end(mlx->mlx);
	return (0);
}

int	main(void)
{
	mlx_t	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 400, 400, "fdf");
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
}
