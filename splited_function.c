/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splited_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:30:55 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/21 20:09:44 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_path_line(char **splited)
{
	if (splited_len(splited) == 2
		&& ft_strcmp(ft_strrchr(splited[1], '.'), ".xpm") == 0
		&& splited[2] == NULL)
		printf("");
	else
	{
		ft_putendl_fd("Error: incorect name1", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_splited(char **splited, t_news **news)
{
	t_news	*tp;

	tp = *news;
	while (tp)
	{
		if (splited && ft_strcmp(splited[0], tp->line) == 0)
		{
			if (ft_strlen(tp->line) == 2)
				check_path_line(splited);
			if (ft_strlen(tp->line) == 1)
				check_color_line(splited);
			lst_pop(news, fine_node(news, tp->line));
			return ;
		}
		tp = tp->next;
	}
	if (!tp)
	{
		ft_putendl_fd("Error: incorect name2", 2);
		exit(EXIT_FAILURE);
	}
}

void	make_splited(char *line, t_news **news)
{
	char	**splited;
	char	*res;
	int		j;

	splited = NULL;
	res = NULL;
	j = 0;
	splited = ft_split(line, ' ');
	while (splited[j])
	{
		res = ft_strjoin(res, splited[j]);
		res = ft_strjoin(res, "\t");
		j++;
	}
	free_2d(splited);
	splited = ft_split(res, '\t');
	free(res);
	res = NULL;
	check_splited(splited, news);
	free_2d(splited);
}

void	check_before_map(char **map, t_news **news)
{
	char	**splited;
	char	*res;
	int		i;
	int		j;

	splited = NULL;
	res = NULL;
	i = 0;
	while (i < 6)
	{
		j = 0;
		if (map[i])
			make_splited(map[i], news);
		else
			break ;
		i++;
	}
	if (i != 6)
	{
		ft_putendl_fd("Error: new line", 2);
		exit(EXIT_FAILURE);
	}
}
