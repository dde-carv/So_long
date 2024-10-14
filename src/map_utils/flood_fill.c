/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:12:10 by dde-carv          #+#    #+#             */
/*   Updated: 2024/10/14 17:24:57 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	flood_fill(t_win *game, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width
		|| game->mapcopy[y][x] == '1' || game->mapcopy[y][x] == 'X')
		{
			//ft_printf("map_height:%d\nmap_width:%d\ny:%d\nx:%d.\n", game->map_height, game->map_width, y, x);
			return ;
		}
		//return ;
	if (((game->mapcopy[y + 1][x] == 'E')|| (game->mapcopy[y - 1][x] == 'E'))
		&& ((game->mapcopy[y][x + 1] == '1') || (game->mapcopy[y][x - 1] == '1')))
		{
			//ft_printf("map_height:%d\nmap_width:%d\ny:%d\nx:%d!\n", game->map_height, game->map_width, y, x);
			return ;
		}
		//return ;
	if (((game->mapcopy[y][x + 1] == 'E') || (game->mapcopy[y][x - 1] == 'E'))
		&& ((game->mapcopy[y + 1][x] == '1') || (game->mapcopy[y - 1][x] == '1')))
		{
			//ft_printf("map_height:%d\nmap_width:%d\ny:%d\nx:%d?\n", game->map_height, game->map_width, y, x);
			return ;
		}
		//return ;
	if (game->mapcopy[y][x] == 'E' || game->mapcopy[y][x] == 'C')
		game->mapcopy[y][x] = '0';
	game->mapcopy[y][x] = 'X';
	flood_fill(game, y + 1, x);
	flood_fill(game, y - 1, x);
	flood_fill(game, y, x + 1);
	flood_fill(game, y, x - 1);
}

static void	ft_to_fill(t_win *game, int y, int x)
{
	get_win_size(game);
	flood_fill(game, y, x);
}

static void	ft_pl_pos(t_win *game, int *pl_y, int *pl_x)
{
	int y;
	int x;

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
				break;
			}
			x++;
		}
		y++;
	}
}

int	check_win(t_win *game)
{
	int	pl_x;
	int	pl_y;
	int	can_row;
	int	can_col;

	pl_x = 0;
	pl_y = 0;
	can_row = 0;
	ft_pl_pos(game, &pl_y, &pl_x);
	ft_to_fill(game, pl_y, pl_x);
	while (game->mapcopy[can_row])
	{
		can_col = 0;
		while (game->mapcopy[can_row][can_col])
		{
			if (game->mapcopy[can_row][can_col] == 'C' ||
			 game->mapcopy[can_row][can_col] == 'E')
				return (0);
			can_col++;
		}
		can_row++;
	}
	return (1);
}
