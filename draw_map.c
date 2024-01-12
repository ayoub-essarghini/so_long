/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:48:03 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/06 15:48:58 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	draw_map(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->img_height)
	{
		while (j < game->img_width)
		{
			if (game->map.map[i][j] == '1')
				ft_mapwall(i, j, game);
			else if (game->map.map[i][j] == 'P')
				player_position(i, j, game);
			else if (game->map.map[i][j] == 'C')
				ft_collpos(i, j, game);
			else if (game->map.map[i][j] == 'E')
				ft_mapexit(i, j, game);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void	draw_path(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->img_height)
	{
		while (j < game->img_width)
		{
			ft_map_path(i, j, game);
			j++;
		}
		i++;
		j = 0;
	}
}
