/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:18:04 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/24 12:41:54 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_close(t_win *test)
{
	mlx_destroy_image(test->mlx, test->img);
	mlx_destroy_window(test->mlx, test->win);
	mlx_destroy_display(test->mlx);
	free(test->mlx);
	exit(0);
}

int	ft_keycode(int keycode, t_win *test)
{
	if (keycode == XK_Escape)
	{
		ft_close(test);
	}
	if (keycode == XK_a)
	{
		mlx_clear_window(test->mlx, test->win);
		mlx_put_image_to_window(test->mlx, test->win, test->img, test->x_pos = test->x_pos - test->img_width, test->y_pos);
	}
	if (keycode == XK_d)
	{
		mlx_clear_window(test->mlx, test->win);
		mlx_put_image_to_window(test->mlx, test->win, test->img, test->x_pos = test->x_pos + test->img_width, test->y_pos);
	}
	if (keycode == XK_w)
	{
		mlx_clear_window(test->mlx, test->win);
		mlx_put_image_to_window(test->mlx, test->win, test->img, test->x_pos, test->y_pos = test->y_pos - test->img_height);
	}
	if (keycode == XK_s)
	{
		mlx_clear_window(test->mlx, test->win);
		mlx_put_image_to_window(test->mlx, test->win, test->img, test->x_pos, test->y_pos = test->y_pos + test->img_height);
	}
	return (0);
}

