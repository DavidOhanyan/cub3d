/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:09:35 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/21 20:16:42 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_news
{
	struct s_news	*next;
	char			*line;
	struct s_news	*prev;
}t_news;

t_news	*fine_node(t_news **news, char *line);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		splited_len(char **splited);
int		lst_siz(t_news *news);
int		check_file_name(int argc, char **argv);
void	check_empty(char **map_maze);
void	ft_putendl_fd(char	*s, int fd);
void	free_2d(char **s);
void	replace_first_tab(char **map_maze);
void	check_map_simbols(char **map_maze);
void	make_news(t_news **news);
void	check_color_line(char **splited);
void	replac_player(char **map_maze);
void	lst_pop(t_news **news, t_news *remov);
void	check_before_map(char **map, t_news **news);
void	check_count_player(char **map_maze);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strrchr(const char	*str, int ch);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const	*s, char c);
char	**ft_allocate_matrix(char const	*s, char c);
char	**ft_fill_matrix(char const	*s, char c, char	**res);
char	*ft_strtrim(char *s1, char *set);
char	**creat_map_maze(char **argv, char **map);
char	**create_all_map(int fd);
#endif