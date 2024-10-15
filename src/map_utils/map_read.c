/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:29:06 by dde-carv          #+#    #+#             */
/*   Updated: 2024/10/15 17:53:29 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	verify_nl(char *line, char *map_temp, t_win *game)
{

	if (line && *line == '\n')
	{
		free(line);
		free(map_temp);
		print_error("Invalid new line in map.", game);
	}
	return ;
}

char	**map_read(char *path, t_win *game)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*map_temp;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map_temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		verify_nl(line, map_temp, game);
		if (!line)
			break ;
		tmp = map_temp;
		map_temp = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	map = ft_split(map_temp, '\n');
	free(map_temp);
	close(fd);
	return (map);
}
