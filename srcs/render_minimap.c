/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raghonya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:42:08 by raghonya          #+#    #+#             */
/*   Updated: 2023/09/11 14:42:09 by raghonya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_sq(t_img *img, int x, int y, int color)
{
	int	oldx;
	int	i;
	int	j;

	i = -1;
	oldx = x;
	while (++i < MMAP_ICON)
	{
		j = -1;
		x = oldx;
		while (++j < MMAP_ICON)
			my_mlx_pixel_put(img, x++, y, color);
		y++;
	}
}

int	draw_space(t_cub *cub, int *x, int y, int space)
{
	if (cub->map[y][*x] == ' ')
	{
		*x += 1;
		return (1);
	}
	draw_sq(&cub->img, *x * MMAP_ICON, y * MMAP_ICON, space);
	return (0);
}

void	calc_icon_pos(t_cub *cub, int wall, int space, int player)
{
	int	map_w;
	int	map_h;
	int	y;
	int	x;

	y = 0;
	map_h = ft_matlen(cub->map);
	while (y < map_h)
	{
		x = 0;
		map_w = ft_strlen(cub->map[y]);
		while (x < map_w)
		{
			if (draw_space(cub, &x, y, space))
				continue ;
			draw_sq(&cub->img, x * MMAP_ICON, y * MMAP_ICON, space);
			if (cub->map[y][x] == '1')
				draw_sq(&cub->img, x * MMAP_ICON, y * MMAP_ICON, wall);
			x += 1;
		}
		y += 1;
	}
	draw_sq(&cub->img, (int)cub->player.pos_y * MMAP_ICON, \
	(int)cub->player.pos_x * MMAP_ICON, player);
}

void	draw_minimap(t_cub *cub)
{
	int	player_color;
	int	space_color;
	int	wall_color;

	wall_color = 0x000000;
	space_color = 0xFFFFFF;
	player_color = 0xFF0000;
	calc_icon_pos(cub, wall_color, space_color, player_color);
}
