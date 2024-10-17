/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:12:10 by dde-carv          #+#    #+#             */
/*   Updated: 2024/10/17 16:09:44 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	flood_fill(t_win *game, int y, int x, char visit)
{
	get_win_size(game);
	if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width \
		|| game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == visit)
		return ;
	if (game->mapcopy[y][x] == 'C')
		game->mapcopy[y][x] = '0';
	if ((game->mapcopy[y][x] == 'E' && (game->mapcopy[y + 1][x] == '0' || \
		game->mapcopy[y - 1][x] == '0' || game->mapcopy[y][x + 1] == '0' || \
		game->mapcopy[y][x - 1] == '0' || game->mapcopy[y + 1][x] == 'C' || \
		game->mapcopy[y - 1][x] == 'C' || game->mapcopy[y][x + 1] == 'C' || \
		game->mapcopy[y][x - 1] == 'C')))
		return ;
	game->mapcopy[y][x] = visit;
	flood_fill(game, y + 1, x, visit);
	flood_fill(game, y - 1, x, visit);
	flood_fill(game, y, x + 1, visit);
	flood_fill(game, y, x - 1, visit);
}

static void	ft_pl_pos(t_win *game, int *pl_y, int *pl_x)
{
	int	y;
	int	x;

	y = 0;
	while (game->mapcopy[y])
	{
		x = 0;
		while (game->mapcopy[y][x])
		{
			if (game->mapcopy[y][x] == 'P')
			{
				*pl_y = y;
				*pl_x = x;
				break ;
			}
			x++;
		}
		y++;
	}
}

static int	verify_win(t_win *game)
{
	int	can_row;
	int	can_col;
	can_row = 0;

	while (game->mapcopy[can_row])
	{
		can_col = 0;
		while (game->mapcopy[can_row][can_col])
		{
			if (game->mapcopy[can_row][can_col] == 'C' || \
				game->mapcopy[can_row][can_col] == 'E')
				return (0);
			can_col++;
		}
		can_row++;
	}
	return (1);
}

static void	put_exit_wall(t_win *game, int *y, int *x)
{
	int col;
	int row;

	row = 0;
	while (game->mapcopy[row])
	{
		col = 0;
		while (game->mapcopy[row][col])
		{
			if (game->mapcopy[row][col] == 'E')
			{
				game->mapcopy[row][col] = '1';
				*y = row;
				*x = col;
				break ;
			}
			col++;
		}
		row++;
	}
}

int	check_win(t_win *game)
{
	int	pl_x;
	int	pl_y;
	int	x;
	int	y;

	pl_x = 0;
	pl_y = 0;
	ft_pl_pos(game, &pl_y, &pl_x);
	x = 0;
	y = 0;
	put_exit_wall(game, &y, &x);
	flood_fill(game, pl_y, pl_x, 'X');
	game->mapcopy[y][x] = 'E';
	flood_fill(game, pl_y, pl_x, 'V');
	if (!verify_win(game))
		return (0);
	return (1);
}
