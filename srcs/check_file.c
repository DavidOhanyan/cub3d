/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:32:17 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/21 20:04:56 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_file_name(char **argv)
{
	int	fd;

	fd = 0;
	err_msg (ft_strcmp(ft_strrchr(argv[1], '.'), ".cub"), "Bad file name!");
	fd = open(argv[1], O_RDONLY);
	err_msg (fd == -1, "Bad file discriptor");
	return (fd);
}
