/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 12:24:06 by dde-carv          #+#    #+#             */
/*   Updated: 2024/10/21 11:25:02 by dde-carv         ###   ########.fr       */
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
	free_map(game->mapcopy);
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

void	print_error(char *str, t_win *game)
{
	if (game->map)
	{
		free_map(game->map);
		free_map(game->mapcopy);
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_printf("Error\n%s\n", str);
	exit(1);
}

void	print_win(t_win *game)
{
	ft_printf("\n========================================\n");
	ft_printf("   You finish the game with %d moves   ", game->moves);
	ft_printf("\n========================================\n");
	ft_close(game);
}
