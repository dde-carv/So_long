/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playtime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:24:30 by dde-carv          #+#    #+#             */
/*   Updated: 2024/10/10 22:47:47 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	free_map(char **map)
{
	int	len;

	len = 0;
	while (map[len])
	{
		free(map[len]);
		len++;
	}
	free(map);
}

int	ft_close(t_win *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->img_colect);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

static void	events(int keycode, t_win *game)
{
	if (keycode == XK_a || keycode == XK_Left)
	{
		game->x_pos -= 1;
		a_key(game);
	}
	if (keycode == XK_d || keycode == XK_Right)
	{
		game->x_pos += 1;
		d_key(game);
	}
	if (keycode == XK_w || keycode == XK_Up)
	{
		game->y_pos -= 1;
		w_key(game);
	}
	if (keycode == XK_s || keycode == XK_Down)
	{
		game->y_pos += 1;
		s_key(game);
	}
}

static int	ft_keycode(int keycode, t_win *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf("You din't finish the game :(\n");
		ft_close(game);
	}
	else if(!game->finish)
		events(keycode, game);
	return (0);
}

void	gameplay(t_win *game)
{
	mlx_hook(game->win, 2, 1L<<0, ft_keycode, game);
	mlx_hook(game->win, 17, 1L<<17, ft_close, game);
}
