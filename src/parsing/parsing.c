/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomarna <thomarna@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:00:02 by thomarna          #+#    #+#             */
/*   Updated: 2024/11/07 18:58:54 by thomarna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"
# include <fcntl.h>

void free_str(void *val)
{
	clear_str(val);
}

void convert_str(char **str, int *y)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		*y = ft_atoi(str[i]);
		i++;
		y++;
	}
}

int set_point(t_map *map, t_list *node_h)
{
	int	position;

	position = 0;
	map->y = malloc(map->width * map->width * sizeof(int));
	if (map->y == NULL)
		return (-1);
	while (node_h)
	{
		convert_str(node_h->content, &map->y[position]);
		position += map->width;
		node_h = node_h->next;
	}
	return (1);
}

int	line_size(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

t_map	*fill(t_list *node_h)
{
	t_map	*map;
	map = malloc(sizeof(t_map *));
	if (map == NULL)
		return (NULL);
	map->height = ft_lstsize(node_h);
	map->width = line_size(node_h->content);
	return (map);
}

t_list	*get_map(int fd)
{
	char *line;
	char **split;
	t_list	*node_h;

	node_h = NULL;
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		free(line);
		ft_lstadd_back(&node_h, ft_lstnew(split));
		line = get_next_line(fd);
	}
	free(line);
	return (node_h);
}

t_map	*parsing(char *file)
{
	t_map *map;
	int	fd;
	t_list *node_h;
	if (!file)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	node_h = get_map(fd);
	close(fd);
	if (!node_h)
		return (NULL);
	map = fill(node_h);
	ft_lstclear(&node_h, free_str);
	return (map);
}
