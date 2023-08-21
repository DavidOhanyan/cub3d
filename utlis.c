/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:24:24 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/21 19:15:54 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int splited_len(char **splited)
{
	int i;
	
	i = 0;
	if (!splited)
		return (i);
	while (splited[i])
		i++;
	return (i);
}

void replac_player(char **map_maze)
{
	int i;
	int j;

	i = 0;
	while (map_maze[i])
	{
		j = 0;
		while (map_maze[i][j])
		{
			if (map_maze[i][j] == 'N' || map_maze[i][j] == 'S'
				|| map_maze[i][j] == 'E' || map_maze[i][j] == 'W')
				map_maze[i][j] = 'P';
			j++;
		}
		i++;
	}
}

void replace_first_tab(char **map_maze)
{
	int i;
	char *line;

	i = 0;
	line = NULL;
	while (map_maze[i])
	{
		if (map_maze[i][0] == '\t')
		{
			line = ft_strjoin(ft_strdup("    "), map_maze[i]);
			free(map_maze[i]);
			map_maze[i] = ft_strdup(line);
			free(line);
		}
		i++;
	}
	
}