/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:55:11 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/15 15:42:46 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_parc_buf(char *buf)
{
	int		j;
	int		i;
	char	*rem;

	i = ((j = 0));
	if (buf == NULL)
		return (NULL);
	if (ft_strchr(buf, '\n') != NULL)
	{
		while (buf[i] != '\n')
			i++;
		if (buf[i] == '\n')
			i++;
		rem = (char *)malloc(sizeof(char) * ft_strlen(ft_strchr(buf, '\n')));
		if (!rem)
			return (NULL);
		while (buf[i] != '\0')
			rem[j++] = buf[i++];
		rem[j] = '\0';
		free(buf);
		return (rem);
	}
	else
		free(buf);
	return (0);
}

char	*ft_check(char *buf, char *result, int i)
{
	if (buf[i] == '\n')
	{
		result[i] = '\n';
		result[i + 1] = '\0';
	}
	else if (buf[i] == '\0')
		result[i] = '\0';
	return (result);
}

char	*ft_parc1(char *buf)
{
	int		i;
	char	*result;

	i = 0;
	if (buf == NULL || *buf == '\0')
		return (NULL);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	if (buf[i] == '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		result[i] = buf[i];
		i++;
	}
	return (ft_check(buf, result, i));
}

char	*get_next_line(int fd)
{
	int			val;
	char		*result;
	char		mas[BUFFER_SIZE + 1];
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		val = read(fd, mas, BUFFER_SIZE);
		if (val <= 0)
			break ;
		mas[val] = '\0';
		buf = ft_strjoin(buf, mas);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (val < 0)
		return (0);
	result = (ft_parc1(buf));
	if (result)
		buf = ft_parc_buf(buf);
	return (result);
}
