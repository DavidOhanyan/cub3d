/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:37:28 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/21 19:39:41 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void check_count_player(char **map_maze)
{
	int i;
	int j;
	int count;

	i = (count = 0);
	while (map_maze[i])
	{
		j = 0;
		while (map_maze[i][j])
		{
			if (map_maze[i][j] == 'W' || map_maze[i][j] == 'S'
				|| map_maze[i][j] == 'E' || map_maze[i][j] == 'N')
					count++;
			j++;
		}
		i++;
	}
	if (count != 1)
	{
		ft_putendl_fd("Error: bad player simbol", 2);
		exit(EXIT_FAILURE);
	}
}

void check_empty(char **map_maze)
{
	size_t i;
	size_t j;

	i = 0;
	while (map_maze[i])
	{
		j = 0;
		while (map_maze[i][j])
		{
			if (map_maze[i][j] == '0' || map_maze[i][j] == 'P')
			{
				if (j > (ft_strlen(map_maze[i + 1]) - 1)
					|| j > (ft_strlen(map_maze[i - 1]) - 1))
				{
					ft_putendl_fd("Error: wrong map22", 2);
					exit(EXIT_FAILURE);
				}
				else
				{
					if (map_maze[i + 1][j] == ' ' || map_maze[i - 1][j] == ' '
						 || map_maze[i][j + 1] == ' ' || map_maze[i][j - 1] == ' '
						|| map_maze[i + 1][j] == '\t' || map_maze[i - 1][j] == '\t')
					{
						ft_putendl_fd("Error: wrong map42", 2);
						exit(EXIT_FAILURE);
					}
				}
			}	
			j++;
		}
		i++;
	}		
}