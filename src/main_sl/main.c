/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:28:17 by dde-carv          #+#    #+#             */
/*   Updated: 2024/10/18 17:03:01 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	check_argv(char	*argv)
{
	int	len;

	if (!argv)
		return (0);
	len = ft_strlen(argv) - 1;
	if (argv[len] == 'r' && argv[len - 1] == 'e' && argv[len - 2] == 'b' && \
		argv[len - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	game;

	ft_bzero(&game, sizeof(t_win));
	if (argc == 2)
	{
		game.mlx = mlx_init();
		game.map = map_read(argv[1], &game);
		game.mapcopy = map_read(argv[1], &game);
		mlx_get_screen_size(game.mlx, &game.win_width, &game.win_height);
		if (check_argv(argv[1]) && check_map(&game))
		{
			init_game(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
			print_error("Invalid map.", &game);
	}
	else
		ft_printf("Bad syntax:\n./so_long ./maps/<map>.ber.\n");
	return (0);
}
