
#include "mlx.h"
#include "libft.h"
#include <SDL2/SDL_mouse.h>
#include <math.h>
typedef struct s_line_datas
{
	int x;
	int	y;
	int	d;
	int	s;
} t_line_datas;

typedef struct s_mlx
{
	void* mlx;
	void* win;
	t_line_datas* pt1;
	t_line_datas* pt2;
} t_mlx;



int	ft_abs(int	n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void ft_drawline(void *data)
{
	t_line_datas	pt1;
	t_line_datas	pt2;
	t_mlx *mlx;
	int	m;

	mlx = (t_mlx *)data;
	m = (pt2.y - pt1.y)/(pt2.x - pt1.x);
	while (1 == 1)
	{
		//mlx_pixel_put(mlx->mlx, mlx->win, pt1.x, pt1.y, 0xFFFF00FF);
		printf("x:%d y:%d\n", pt1.x, pt1.y);
		if (pt1.x == pt2.x && pt1.y == pt2.y)
			break;
		if (pt1.x > 400 || pt1.y > 400)
			break;
		pt1.y += m;
		pt1.x++;
	}
}
int window_hook(int event, void* param)
{
	if(event == 0)
		mlx_loop_end(((t_mlx*)param)->mlx);
	return 0;
}

int	key_hook(int key, void *param)
{
	t_mlx* mlx = (t_mlx *)param;
	if (key == 44)
	{
		if (mlx->pt1 && mlx->pt2)
		{
			ft_printf("%s\n", "Drawing line");
			ft_drawline(mlx);
		}
	}
	else if (key == 41)
		mlx_loop_end(mlx->mlx);
	return (0);
}
void set_pos(void *param, int value)
{
	t_line_datas	pt;
	t_mlx* mlx = (t_mlx *)param;
	mlx_mouse_get_pos(mlx->mlx, &pt.x, &pt.y);
	ft_printf("Pos set x1: %d y1: %d\n", pt.x, pt.x);
	if (value == 1)
		mlx->pt1 = &pt;
	else if (value == 2)
		mlx->pt2 = &pt;
}
int	mouse_hook(int btn, void *param)
{
	t_mlx* mlx = (t_mlx *)param;
	
	if (btn == 1)
	{
		set_pos(mlx, 1);
	}
	if (btn == 3)
	{
		set_pos(mlx, 2);
	}
	return (0);
}

void	ft_pt_init(t_line_datas *pt)
{
	pt->x = 0;
    pt->y = 0;
}

int	main(void)
{
	t_mlx	mlx;
	t_line_datas	pt1;
	t_line_datas	pt2;
	
	ft_pt_init(&pt1);
	ft_pt_init(&pt2);
	ft_printf("%d %d", pt1.x, pt2.x);
	mlx.pt1 = &pt1;
	mlx.pt2 = &pt2;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 400, 400, "fdf");
	mlx_on_event(mlx.mlx, mlx.win, MLX_WINDOW_EVENT, window_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_KEYDOWN, key_hook, &mlx);
	mlx_on_event(mlx.mlx, mlx.win, MLX_MOUSEDOWN, mouse_hook, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
}
