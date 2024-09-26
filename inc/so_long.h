/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:00:02 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/26 21:15:20 by dde-carv         ###   ########.fr       */
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
	char	**map;
	void	*img_floor;
	void	*img_wall;
	void	*img_player;
	void	*img_colect;
	void	*img_exit;
	int		n_c;
	int		n_e;
	int		n_p;
	int		map_width;
	int		map_height;
	int		img_width;
	int		img_height;
	int		x_pos;
	int		y_pos;
}				t_win;

int	ft_close(t_win *game);
int	ft_keycode(int keycode, t_win *game);

#endif
