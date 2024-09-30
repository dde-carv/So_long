/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:28:17 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/30 16:40:29 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	check_argv(char	*argv)
{
	int	len;

	if(!argv)
		return (0);
	len = ft_strlen(argv) - 1;
	if (argv[len] == 'r' && argv[len - 1] == 'e' && argv[len - 2] == 'b' && argv[len - 3] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	game;

	if (argc == 2)
	{
		game.map = map_read(argv[1]);
		if (check_argv(argv[1]) && check_map(&game))
		{
			init_game(&game);
			gameplay(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			if(game.map)
				free(game.map);
			ft_printf("Error\nInvalid map!\n");
			exit(1);
		}
	}
	else
	{
		ft_printf("Error\nBad syntax!\n");
		exit(1);
	}
	return (0);
}
