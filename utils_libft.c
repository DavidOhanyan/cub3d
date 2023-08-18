/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:15:17 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/18 16:20:36 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
		{
			j++;
		}
		if (to_find[j] == '\0')
			return (str + i);
		i++;
		j = 0;
	}
	return (0);
}


void	*ft_memcpy(void	*dst, const void	*src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*strim;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (ft_strchr(set, s1[j - 1]) != NULL)
		j--;
	strim = (char *)malloc(sizeof(char) * ((j - i) + 1));
	if (!strim)
		return (NULL);
	ft_memcpy(strim, s1 + i, (j - i));
	strim[j - i] = '\0';
	return (strim);
}

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * neg);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = NULL;
	if (s)
	{
		dup = malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!dup)
			return (NULL);
		while (*(s + i))
		{
			*(dup + i) = *(s + i);
			i ++;
		}
		*(dup + i) = '\0';
	}
	return (dup);
}

void	ft_putendl_fd(char	*s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}

char	*ft_strrchr(const char	*str, int ch)
{
	char	*ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == (unsigned char)ch)
			ptr = (char *)str;
			str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

static	void	*ft_free(char	**matrix, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return (NULL);
}

static size_t	qanak(char const	*s, char c)
{
	size_t	i;
	size_t	word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word_count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word_count);
}

char	**ft_allocate_matrix(char const	*s, char c)
{
	int		count;
	char	**res;

	count = qanak(s, c);
	res = (char **)malloc(sizeof(char *) * (count + 1));
	return (res);
}

char	**ft_fill_matrix(char const	*s, char c, char	**res)
{
	int	i;
	int	j;
	int	start;
	int	end;

	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > start)
		{
			res[++j] = ft_substr(s, start, end - start);
			if (!res[j])
				return (ft_free(res, j - 1));
		}
	}
	res[++j] = NULL;
	return (res);
}

char	**ft_split(char const	*s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
		res = ft_allocate_matrix(s, c);
	if (!res)
		return (NULL);
	return (ft_fill_matrix(s, c, res));
}

void	free_2d(char **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (*(s + i))
		{
			free(*(s + i));
			i ++;
		}
		free (s);
	}
}