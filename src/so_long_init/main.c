/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:28:17 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/25 17:31:35 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	main(void)
{
	t_win	game;
	char	*img_path;

	game.x_pos = 300;
	game.y_pos = 300;
	img_path = "./textures/Steve_front.xpm";
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 1000, 1000, "lol");
	game.img_player = mlx_xpm_file_to_image(game.mlx, img_path, &game.img_width, &game.img_height);
	mlx_put_image_to_window(game.mlx, game.win, game.img_player, game.x_pos, game.y_pos);
	mlx_hook(game.win, DestroyNotify, NoEventMask, ft_close, &game);
	mlx_hook(game.win, KeyPress, KeyPressMask, ft_keycode, &game);
	mlx_loop(game.mlx);
	return (0);
}
