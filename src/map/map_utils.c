/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:41:19 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/26 17:07:23 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static int	map_rectangle(char **map)
{
	int	len;

	len = 1;
	if(!map)
		return (0);
	while (map[len] != '\0')
	{
		if (ft_strlen(map[len]) != ft_strlen(map[0]))
			return (0);
		len++;
	}
	return(1);
}


