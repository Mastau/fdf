/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:04:43 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/07 18:21:41 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
}	t_map;

#endif
