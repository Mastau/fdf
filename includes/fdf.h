/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:04:43 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/10 14:16:32 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <SDL2/SDL_mouse.h>

# ifndef WIDTH
#  define WIDTH 1080
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

typedef struct s_mlx
{
	void	*con;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_map
{
	t_mlx	mlx;
	int	width;
	int	height;
	int	*y;
	double zoom;
}	t_map;

#endif
