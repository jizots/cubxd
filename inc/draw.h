/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:32:12 by hotph             #+#    #+#             */
/*   Updated: 2023/10/20 19:38:12 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"

void		draw_sky_and_ground(t_meta *meta);
void		draw_minimap(t_meta *meta);
void		init_ray(
				t_ray *verti, t_ray *horiz, t_meta *meta, double *add_radian);
void		next_vertical_intersec(
				t_point2df start, t_ray *verti, double vector, int tile_size);
void		next_horizontal_intersec(
				t_point2df start, t_ray *horiz, double vector, int tile_size);
void		update_current_point(t_point2df *current, t_point2df *next,
				int *flag_up, int *flag_down);
bool		is_wall(t_point2di point, t_mlx *mlx);
t_point2df	get_point2d_wall(
				t_ray *verti, t_ray *horiz, t_meta *meta, double vector_ray);
char		which_direction(const t_ray *verti, const double radian);
void		convert_collision_data(t_meta *meta, t_collision *colli,
				t_point2df *wall, const t_ray *verti);
double		get_tex_x(
				t_point2df *wall, const char dire, const int tile_size);
int			get_color_from_texture(t_tex tex, int x, int y);
int			cub3d_select_color(
				t_meta *meta, t_collision *colli, double row);
bool		is_map(size_t x, size_t y, t_meta *meta);
void		draw_raycast_to_human_vector(t_meta *meta);

#endif