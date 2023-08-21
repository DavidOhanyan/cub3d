/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohanyan <dohanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:11:07 by dohanyan          #+#    #+#             */
/*   Updated: 2023/08/21 19:42:30 by dohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	map_maze = creat_map_maze(argv, map);
	if (!map_maze || !*map_maze)
	{
		ft_putendl_fd("Error: incorect map", 2);
		exit(EXIT_FAILURE);
	}
	check_count_player(map_maze);
	check_map_simbols(map_maze);
	replac_player(map_maze);
	replace_first_tab(map_maze);
	check_empty(map_maze);
	return (0);
}
