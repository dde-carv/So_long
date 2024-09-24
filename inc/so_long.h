/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:00:02 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/24 16:26:04 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	void	*img_player;
	int		img_width;
	int		img_height;
	int		x_pos;
	int		y_pos;
}				t_win;

int	ft_close(t_win *game);
int	ft_keycode(int keycode, t_win *game);

#endif
