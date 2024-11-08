/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:32:43 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/08 15:07:30 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

#include "fdf.h"
#include <math.h>

void rotation_matrix_x(float theta, float matrix[3][3]);
void rotation_matrix_y(float theta, float matrix[3][3]);
void rotation_matrix_z(float theta, float matrix[3][3]);
void print_matrix_3d(float matrix[3][3]);


#endif
