/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:41:03 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/12 18:36:54 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "fdf.h"
#include "libft.h"
#include "mlx.h"

# ifndef SCALE
#  define SCALE 2
# endif

typedef struct s_line
{
	int	pt1;
	int	pt2;
	int	diff;
	double	d;
	double	i;
}	t_line;

typedef struct s_point
{
	int	x;
	int	y;
} t_point;

void	ft_drawline(t_mlx *mlx, int *matrix1, int *matrix2);
void	generate_map(t_map *map);
void	draw_wireframe(t_map *map);
#endif
