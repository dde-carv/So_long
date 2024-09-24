/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:28:17 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/24 12:41:31 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	main(void)
{
	t_win	test;
	char	*img_path;

	test.x_pos = 300;
	test.y_pos = 300;
	img_path = "./textures/male-deer.xpm";
	test.mlx = mlx_init();
	test.win = mlx_new_window(test.mlx, 1000, 1000, "lol");
	test.img = mlx_xpm_file_to_image(test.mlx, img_path, &test.img_width, &test.img_height);
	mlx_put_image_to_window(test.mlx, test.win, test.img, test.x_pos, test.y_pos);
	mlx_hook(test.win, DestroyNotify, NoEventMask, ft_close, &test);
	mlx_hook(test.win, KeyPress, KeyPressMask, ft_keycode, &test);
	mlx_loop(test.mlx);
	return (0);
}
