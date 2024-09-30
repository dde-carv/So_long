/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:40:16 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/30 17:42:43 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	player_img_update(char key , t_win *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/Steve_b.xpm", &game->img_width, &game->img_height);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/Steve_f.xpm", &game->img_width, &game->img_height);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/Steve_L.xpm", &game->img_width, &game->img_height);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/Steve_R.xpm", &game->img_width, &game->img_height);
}

void	w_key(t_win *game)
{
	player_img_update('w', game);
	if (game->map[game->y_pos][game->x_pos] == 'E' && game->n_c == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_pos + 1][game->x_pos] = '0';
		game->finish = 1;
		draw_game(game);
	}
	else if (game->map[game->y_pos][game->x_pos] == '1' || game->map[game->y_pos][game->x_pos] == 'E')
		game->y_pos += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_pos][game->x_pos] == 'C')
			game->n_c -= 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		game->map[game->y_pos + 1][game->x_pos] = '0';
		draw_game(game);
	}
}

void	s_key(t_win *game)
{
	player_img_update('s', game);
	if (game->map[game->y_pos][game->x_pos] == 'E' && game->n_c == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_pos - 1][game->x_pos] = '0';
		game->finish = 1;
		draw_game(game);
	}
	else if (game->map[game->y_pos][game->x_pos] == '1' || game->map[game->y_pos][game->x_pos] == 'E')
		game->y_pos -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_pos][game->x_pos] == 'C')
			game->n_c -= 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		game->map[game->y_pos - 1][game->x_pos] = '0';
		draw_game(game);
	}
}

void	a_key(t_win *game)
{
	player_img_update('a', game);
	if (game->map[game->y_pos][game->x_pos] == 'E' && game->n_c == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_pos][game->x_pos + 1] = '0';
		game->finish = 1;
		draw_game(game);
	}
	else if (game->map[game->y_pos][game->x_pos] == '1' || game->map[game->y_pos][game->x_pos] == 'E')
		game->x_pos += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_pos][game->x_pos] == 'C')
			game->n_c -= 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		game->map[game->y_pos][game->x_pos + 1] = '0';
		draw_game(game);
	}
}

void	d_key(t_win *game)
{
	player_img_update('d', game);
	if (game->map[game->y_pos][game->x_pos] == 'E' && game->n_c == 0)
	{
		mlx_clear_window(game->mlx, game->win);
		game->map[game->y_pos][game->x_pos - 1] = '0';
		game->finish = 1;
		draw_game(game);
	}
	else if (game->map[game->y_pos][game->x_pos] == '1' || game->map[game->y_pos][game->x_pos] == 'E')
		game->x_pos -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_pos][game->x_pos] == 'C')
			game->n_c -= 1;
		game->map[game->y_pos][game->x_pos] = 'P';
		game->map[game->y_pos][game->x_pos - 1] = '0';
		draw_game(game);
	}
}
