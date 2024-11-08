/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:41:03 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/08 17:47:07 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

#include "fdf.h"
#include "mlx.h"

typedef struct s_line
{
	int	pt1;
	int	pt2;
	int	diff;
	float	d;
	float	i;
}	t_line;

void	ft_drawline(t_mlx *mlx, int *matrix1, int *matrix2);
void	generate_map(t_map *map);
#endif
