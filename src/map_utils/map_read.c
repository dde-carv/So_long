/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:29:06 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/26 14:25:30 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	**map_read(char *path)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*map_temp;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
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
