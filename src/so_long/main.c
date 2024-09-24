/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:28:17 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/24 11:47:15 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	int		x_pos;
	int		y_pos;
}				t_win;

int	main(void)
{
	t_win	test;
	char	*img_path;

	test.x_pos = 300;
	test.y_pos = 0;
	img_path = "../../texture/male-deer.xpm";
	test.mlx = mlx_init();
	ft_printf("Ola\n");
	test.win = mlx_new_window(test.mlx, 1000, 1000, "lol");
	test.img = mlx_xpm_file_to_image(test.mlx, img_path, &test.img_width, &test.img_height);
	ft_printf("Ola1\n");
	mlx_hook(test.win, DestroyNotify, NoEventMask, ft_close, &test);
	ft_printf("Ola2\n");
	mlx_hook(test.win, KeyPress, KeyPressMask, ft_keycode, &test);
	ft_printf("Ola3\n");
	mlx_loop(test.mlx);
	return (0);
}
