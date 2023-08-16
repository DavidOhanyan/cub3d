/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:11:07 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/16 17:30:22 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int check_file_name(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc > 2 || argc <= 1)
	{
		ft_putendl_fd("Error: less or more argc", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".cub") != 0 || ft_strlen(argv[1]) == 4)
	{
		ft_putendl_fd("Error: bad file name!", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error: bad file discriptor", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void check_last_line(char *line)
{
	char *last;

	last = NULL;
	
	last = ft_strrchr(line, '\n');
	if (ft_strlen(last) == 1)
	{
		ft_putendl_fd("Error: new line", 2);
		exit(EXIT_FAILURE);
	}
}

char **create_all_map(int fd)
{
	char *line;
	char *joined;
	char **splited;

	joined = NULL;
	line = NULL;
	splited = NULL;
	while (1)
	{
		joined = get_next_line(fd);
		if (!joined)
			break;
		line = ft_strjoin(line, joined);
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

void check_path_line(char **splited)
{
	if (splited_len(splited) == 2 && ft_strcmp(ft_strrchr(splited[1], '.'), ".xpm") == 0
			&& splited[2] == NULL)
		printf("");
	else
	{
		ft_putendl_fd("Error: incorect name", 2);
		exit(EXIT_FAILURE);
	}
}

t_news *fine_node(t_news **news, char *line)
{
	t_news *tp;

	tp = *news;
	while (tp)
	{
		if (ft_strcmp(tp->line, line) == 0)
			return(tp);
		tp = tp->next;
	}
		return (NULL);
}

int lst_siz(t_news *news)
{
	int i;
	t_news *tp;

	tp = news;
	i = 0;
	while (tp)
	{
		tp = tp->next;
		i++;
	}
	return (i);
}

void	lst_del(t_news *del)
{
	free(del->line);
	free(del);
}

void lst_pop(t_news **news, t_news *remov)
{
	t_news	*next;
	t_news	*prev;

	if (remov)
	{
		next = remov->next;
		prev = remov->prev;
		lst_del(remov);
		if (news && *news)
		{
			if (prev)
				prev->next = next;
			if (next)
				next->prev = prev;
			if (*news == remov)
				*news = next;
		}
	}
}

void check_size_args(char **nubs)
{
	int i = 0;

	while (nubs[i])
	{
		if (ft_atoi(nubs[i]) > 255)
		{
			ft_putendl_fd("Error: more then 255", 2); 
			exit(EXIT_FAILURE);
		}
		i++;
	}
	// printf("OK\n");
}

void check_color_nub(char *line)
{
	char **nubs;
	int i;
	int j;

	i = 0;
	nubs = ft_split(line, ',');
	if (splited_len(nubs) != 3)
	{
		ft_putendl_fd("Error: more color args", 2); 
		exit(EXIT_FAILURE);
	}
	while (nubs[i])
	{
		j = 0;
		while (nubs[i][j])
		{
			if(nubs[i][j] < '0' || nubs[i][j] > '9' || ft_strlen(nubs[i]) > 3)
			{
				ft_putendl_fd("Error: bad color argument", 2); 
				exit(EXIT_FAILURE);
			}	
			j++;
		}
		i++;
	}
	check_size_args(nubs);
	free_2d(nubs);
}

void check_color_line(char **splited)
{
	char *line;
	int count_comma;
	int i;

	line = NULL;
	count_comma = 0;
	i = 1;
	while (splited[i])
	{
		line = ft_strjoin(line, splited[i]);
		i++;
	}
	i = 0;
	while (line[i])
	{
		if(line[i] == ',')
			count_comma++;
		i++;
	}
	if (count_comma != 2)
	{
		ft_putendl_fd("Error: more or less comma", 2); 
		exit(EXIT_FAILURE);
	}
	check_color_nub(line);
	free(line);
}

void check_splited(char **splited, t_news **news)
{
	t_news *tp;

	tp = *news;
	while (tp)
	{
		if (ft_strcmp(splited[0], tp->line) == 0)
		{
			if (ft_strlen(tp->line) == 2)
				check_path_line(splited);
			if(ft_strlen(tp->line) == 1)
				check_color_line(splited);
			lst_pop(news, fine_node(news, tp->line));
			return ;
		}
		tp = tp->next;
	}
	if (!tp)
	{
		ft_putendl_fd("Error: incorect name", 2); 
		exit(EXIT_FAILURE);
	}
}

void check_before_map(char **map, t_news **news)
{
	char **splited;
	int i;
	
	i = 0;
	splited = NULL;
	while (i < 6)
	{
		if (map[i])
			splited = ft_split(map[i], ' ');
		else
			break;
		check_splited(splited, news);
		free_2d(splited);
		i++;
	}
	if (i != 6)
	{
		ft_putendl_fd("Error: new line", 2);
		exit(EXIT_FAILURE);
	}
}

t_news *make_new(char *line)
{
	t_news *new;
	
	new = malloc(sizeof(t_news));
	new->next = NULL;
	new->line = line;
	new->prev = NULL;
	return (new);
}

void push_back(t_news **news, char *line)
{
	t_news *new;
	t_news *tp;

	tp = NULL;
	new = NULL;
	if (!*news)
		*news = make_new(line);
	else
	{
		tp = *news;
		new = make_new(line);
		while (tp->next != NULL)
			tp = tp->next;
		tp->next = new;
		new->prev = tp;	
	}
}

void make_news(t_news **news)
{
	push_back(news, ft_strdup("NO"));
	push_back(news, ft_strdup("SO"));
	push_back(news, ft_strdup("WE"));
	push_back(news, ft_strdup("EA"));
	push_back(news, ft_strdup("F"));
	push_back(news, ft_strdup("C"));
}

void check_new_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if(line[i] == '\n' && line[i + 1] == '\n')
		{
			ft_putendl_fd("Error: new line", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

char **create_only_map(char **argv, char **map)
{
	char *line;
	char *joined;
	char **map_maze;
	char *res;
	char *last;
	int fd;

	joined = NULL;
	line = NULL;
	map_maze = NULL;
	res = NULL;
	fd = open(argv[1], O_RDONLY);
	last = ft_strdup(map[5]);
	while (1)
	{
		joined = get_next_line(fd);
		if (!joined)
			break;
		line = ft_strjoin(line, joined);
		free(joined);
	}
	close(fd);
	res = ft_strdup((ft_strstr(line, last) + ft_strlen(last)));
	free(line);
	free(last);
	line = ft_strtrim(res, "\n");
	free(res);
	check_new_line(line);
	map_maze = ft_split(line, '\n');
	free(line);
	return (map_maze);
}

int main(int argc, char **argv)
{
	t_news *news;	
	char **map;
	char **map_maze;
	int fd;
	
	news = NULL;
	map_maze = NULL;
	fd = check_file_name(argc, argv);	
	make_news(&news);
	map = create_all_map(fd);
	check_before_map(map, &news);
	map_maze = create_only_map(argv, map);
	return (0);
}
