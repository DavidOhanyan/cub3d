/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:09:35 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/16 22:09:48 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

#define MAP_SIMBOLS "01NSWE "

typedef struct s_news
{
	struct s_news *next;
	char 	*line;
	struct s_news *prev;
	
}t_news;

char	*ft_strstr(char *str, char *to_find);
char	*ft_strrchr(const char	*str, int ch);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s);
void	ft_putendl_fd(char	*s, int fd);
int	ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const	*s, char c);
char	**ft_allocate_matrix(char const	*s, char c);
char	**ft_fill_matrix(char const	*s, char c, char	**res);
void	free_2d(char **s);
int	ft_atoi(const char *str);
char	*ft_strtrim(char *s1, char *set);
#endif