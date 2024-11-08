/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:04:08 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/08 15:23:14 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

void rotation_matrix_x(float theta, float matrix[3][3]) {
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = cos(theta);
    matrix[1][2] = -sin(theta);
    matrix[2][0] = 0;
    matrix[2][1] = sin(theta);
    matrix[2][2] = cos(theta);
}

void rotation_matrix_y(float theta, float matrix[3][3]) {
    matrix[0][0] = cos(theta);
    matrix[0][1] = 0;
    matrix[0][2] = sin(theta);
    matrix[1][0] = 0;
    matrix[1][1] = 1;
    matrix[1][2] = 0;
    matrix[2][0] = -sin(theta);
    matrix[2][1] = 0;
    matrix[2][2] = cos(theta);
}

void rotation_matrix_z(float theta, float matrix[3][3]) {
    matrix[0][0] = cos(theta);
    matrix[0][1] = -sin(theta);
    matrix[0][2] = 0;
    matrix[1][0] = sin(theta);
    matrix[1][1] = cos(theta);
    matrix[1][2] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
}
