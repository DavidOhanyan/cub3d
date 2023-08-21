/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:14:27 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/21 20:06:05 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_news	*make_new(char *line)
{
	t_news	*new;

	new = malloc(sizeof(t_news));
	new->next = NULL;
	new->line = line;
	new->prev = NULL;
	return (new);
}

void	push_back(t_news **news, char *line)
{
	t_news	*new;
	t_news	*tp;

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

void	make_news(t_news **news)
{
	push_back(news, ft_strdup("NO"));
	push_back(news, ft_strdup("SO"));
	push_back(news, ft_strdup("WE"));
	push_back(news, ft_strdup("EA"));
	push_back(news, ft_strdup("F"));
	push_back(news, ft_strdup("C"));
}
