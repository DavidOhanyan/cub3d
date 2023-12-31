/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_check_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:27:29 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/26 18:02:29 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	check_size_args(char **nubs)
{
	int	i;

	i = 0;
	while (nubs[i])
	{
		if (ft_atoi(nubs[i]) > 255)
		{
			ft_putendl_fd("Error: more then 255", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_color_nub(t_cub *cub, char *line, int side)
{
	char	**nubs;
	int		i;
	int		j;

	i = -1;
	nubs = ft_split(line, ',');
	err_msg (ft_matlen(nubs) != 3, "Incorrect number of color args");
	while (nubs[++i])
	{
		j = -1;
		while (nubs[i][++j])
			err_msg (nubs[i][j] < '0' || nubs[i][j] > '9' \
			|| len_ignore_zero(nubs[i]) > 3, "Bad color argument");
	}
	check_size_args(nubs);
	if (side == 'C')
		cub->ceil_color = trgb(0, ft_atoi(*nubs), \
		ft_atoi(*(nubs + 1)), ft_atoi(*(nubs + 2)));
	else
		cub->floor_color = trgb(0, ft_atoi(*nubs), \
		ft_atoi(*(nubs + 1)), ft_atoi(*(nubs + 2)));
	free_2d(nubs);
}

char	*make_color_line(char **splited, int *comma)
{
	char	*line;
	int		i;

	line = NULL;
	i = 1;
	while (splited[i])
	{
		line = strjoin_w_free(line, splited[i]);
		if (i != ft_matlen(splited) - 1)
		{
			line = strjoin_w_free(line, ",");
			(*comma)++;
		}
		i++;
	}
	return (line);
}

void	check_color_line(t_cub *cub, char **splited)
{
	int		i;
	int		comma;
	int		count;
	char	*line;

	i = 0;
	comma = 0;
	count = 0;
	line = make_color_line(splited, &comma);
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	err_msg (count - comma != 2, "Incorrect number of commas");
	check_color_nub(cub, line, **splited);
	free(line);
}
