/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:41:19 by dde-carv          #+#    #+#             */
/*   Updated: 2024/10/14 16:34:12 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	check_rectangle(char **map)
{
	int	len;

	len = 1;
	if(!map)
		return (0);
	while (map[len])
	{
		if (ft_strlen(map[len]) != ft_strlen(map[0]))
			return (0);
		len++;
	}
	return (1);
}

static int	check_close(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
		y++;
	while (map[0][x] != '\0' || map[y - 1][x] != '\0')
	{
		if (map[0][x] != '1' || map[y - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	x = ft_strlen(map[y]);
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	check_pce(t_win *game)
{
	int	y;
	int	x;

	game->n_c = 0;
	game->n_e = 0;
	game->n_p = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == 'P')
				game->n_p++;
			else if (game->map[y][x] == 'C')
				game->n_c++;
			else if (game->map[y][x] == 'E')
				game->n_e++;
			x++;
		}
		y++;
	}
	if (game->n_p != 1 || game->n_e != 1 || game->n_c == 0)
		return (0);
	return (1);
}

static int	check_valid(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'C' && map[y][x] != '0' && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map(t_win *game)
{
	if (check_rectangle(game->map) && check_close(game->map) && check_pce(game) && check_valid(game->map) && check_win(game))
		return (1);
	return (0);
}
