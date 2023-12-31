/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hotph <hotph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:52:27 by sotanaka          #+#    #+#             */
/*   Updated: 2023/10/11 15:29:39 by hotph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"
#include "error3d.h"

int	my_mlx_create_win(t_mlx *mlx)
{
	mlx->win
		= mlx_new_window(mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3DDD");
	if (mlx->win == NULL)
		return (perror_wrap("at mlx_new_win", 1));
	return (0);
}

int	my_mlx_close_win(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}
