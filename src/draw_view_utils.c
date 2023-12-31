/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:10:01 by hotph             #+#    #+#             */
/*   Updated: 2023/10/20 19:35:28 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

bool	is_map(size_t x, size_t y, t_meta *meta)
{
	size_t	xi;
	size_t	yi;

	xi = x / meta->tile_size;
	yi = y / meta->tile_size;
	if (yi < meta->height_map && xi < ft_strlen(meta->map[yi])
		&& x < (meta->tile_size * ft_strlen(meta->map[yi]))
		&& y < (meta->tile_size * meta->height_map))
		return (true);
	return (false);
}

double	get_tex_x(
	t_point2df *wall, const char dire, const int tile_size)
{
	double	integer;

	if (dire == 'N' || dire == 'S')
		return (modf((wall->x / tile_size), &integer));
	else
		return (modf((wall->y / tile_size), &integer));
}

int	get_color_from_texture(t_tex tex, int x, int y)
{
	int		color;

	color = *(int *)(tex.addr + (y * tex.line_length
				+ x * (tex.bpp / 8)));
	return (color);
}

int	cub3d_select_color(
	t_meta *meta, t_collision *colli, double row)
{
	int		color;

	if (1.0000 < row)
		row = 1.0;
	if (colli->dire == 'N')
		color = get_color_from_texture(meta->north_tex,
				round((meta->north_tex.img_width - 1) * colli->tex_x),
				round((meta->north_tex.img_height - 1) * row));
	else if (colli->dire == 'S')
		color = get_color_from_texture(meta->south_tex,
				(meta->south_tex.img_width - 1)
				- round((meta->south_tex.img_width - 1) * colli->tex_x),
				round((meta->south_tex.img_height - 1) * row));
	else if (colli->dire == 'W')
		color = get_color_from_texture(meta->west_tex,
				(meta->west_tex.img_width - 1)
				- round((meta->west_tex.img_width - 1) * colli->tex_x),
				round((meta->west_tex.img_height - 1) * row));
	else if (colli->dire == 'E')
		color = get_color_from_texture(meta->east_tex,
				round((meta->east_tex.img_width - 1) * colli->tex_x),
				round((meta->east_tex.img_height - 1) * row));
	else
		color = 0x00FFFFFF;
	return (color);
}

void	convert_collision_data(t_meta *meta, t_collision *colli,
	t_point2df *wall, const t_ray *verti)
{
	colli->dis = distance_of_point(meta->human.point, *wall);
	colli->dire = which_direction(verti, verti->vector);
	colli->dis *= cos(meta->human.vector - verti->vector);
	colli->tex_x = get_tex_x(wall, colli->dire, meta->tile_size);
}
