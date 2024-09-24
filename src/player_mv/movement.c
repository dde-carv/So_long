/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:40:16 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/24 16:18:34 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_keycode(int keycode, t_win *game)
{
	if (keycode == XK_Escape)
	{
		ft_close(game);
	}
	if (keycode == XK_a)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->img, game->x_pos = game->x_pos - game->img_width, game->y_pos);
	}
	if (keycode == XK_d)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->img, game->x_pos = game->x_pos + game->img_width, game->y_pos);
	}
	if (keycode == XK_w)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->img, game->x_pos, game->y_pos = game->y_pos - game->img_height);
	}
	if (keycode == XK_s)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->img, game->x_pos, game->y_pos = game->y_pos + game->img_height);
	}
	return (0);
}
