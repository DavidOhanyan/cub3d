/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:41:49 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/21 20:05:35 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_last_line(char *line)
{
	char	*last;

	last = NULL;
	last = ft_strrchr(line, '\n');
	if (ft_strlen(last) == 1)
	{
		ft_putendl_fd("Error: new line", 2);
		exit(EXIT_FAILURE);
	}
}

char	**create_all_map(int fd)
{
	char	*line;
	char	*joined;
	char	*res;
	char	**splited;

	joined = NULL;
	line = NULL;
	res = NULL;
	splited = NULL;
	while (1)
	{
		joined = get_next_line(fd);
		if (!joined)
			break ;
		res = ft_strtrim(joined, "\t ");
		line = ft_strjoin(line, res);
		free(res);
		free(joined);
	}
	close(fd);
	if (!line)
	{
		ft_putendl_fd("Error: file is empty", 2);
		exit(EXIT_FAILURE);
	}
	check_last_line(line);
	splited = ft_split(line, '\n');
	free(line);
	return (splited);
}
