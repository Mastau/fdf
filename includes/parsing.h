/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:11:16 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/07 18:47:32 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft.h"
# include "fdf.h"

void convert_str(char **str, int *y);
int set_point(t_map *map, t_list *node_h);
int	line_size(char **str);
t_map	*fill(t_list *node_h);
t_list	*get_map(int fd);
t_map	*parsing(char *file);

#endif

