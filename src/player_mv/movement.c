/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:40:16 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/24 17:11:41 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_keycode(int keycode, t_win *game)
{
	if (keycode == XK_Escape)
	{
		ft_close(game);
	}
	if (keycode == XK_a || keycode == XK_Left)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->x_pos = game->x_pos - game->img_width, game->y_pos);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->x_pos = game->x_pos + game->img_width, game->y_pos);
	}
	if (keycode == XK_w || keycode == XK_Up)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->x_pos, game->y_pos = game->y_pos - game->img_height);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, game->x_pos, game->y_pos = game->y_pos + game->img_height);
	}
	return (0);
}
