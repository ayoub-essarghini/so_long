/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:06:04 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/13 17:11:31 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_lr_map(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (h < game->img_height)
	{
		if (game->map.map[h][w] != '1')
		{
			ft_printf("Error\nLeft line in map is invalid");
			return (-1);
		}
		h++;
	}
	h = 0;
	w = game->img_width - 1;
	while (++h < game->img_height)
	{
		if (game->map.map[h][w] != '1')
		{
			ft_printf("Error\nRight line in map is invalid");
			return (-1);
		}
	}
	return (0);
}

int	check_tb_map(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	while (w < game->img_width)
	{
		if (game->map.map[h][w] != '1')
		{
			ft_printf("Error\nTop line in map is invalid");
			return (-1);
		}
		w++;
	}
	w = 0;
	while (w < game->img_width)
	{
		if (game->map.map[game->img_height - 1][w] != '1')
		{
			ft_printf("Error\nBottom line in map is invalid");
			return (-1);
		}
		w++;
	}
	return (0);
}

int	check_full_map(t_data *game)
{
	int		h;
	int		w;
	char	c;

	h = 0;
	while (h < game->img_height)
	{
		w = 0;
		while (w < game->img_width)
		{
			c = game->map.map[h][w];
			if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E')
			{
				ft_printf("Error\ninvalid object");
				return (-1);
			}
			w++;
		}
		h++;
	}
	return (0);
}

int	check_objects(t_data *game)
{
	int	h;
	int	w;

	h = 0;
	while (++h < game->img_height)
	{
		w = 0;
		while (++w < game->img_width)
		{
			if (game->map.map[h][w] == 'P')
			{
				game->p_count++;
			}
			else if (game->map.map[h][w] == 'C')
				game->c_count++;
			else if (game->map.map[h][w] == 'E')
				game->e_count++;
		}
	}
	if (game->p_count != 1 || game->e_count != 1 || game->c_count < 1)
	{
		ft_printf("Error\ninvalid base object");
		return (-1);
	}
	return (0);
}

void	check_valid_map(t_data *game)
{
	char	**map2;
	char	**map1;
	int		k;
	int		l;

	map1 = map_dup(game->map.map, game->img_height);
	map2 = map_dup(game->map.map, game->img_height);
	get_p_position(game);
	if (check_full_map(game) == -1)
		exit(1);
	if (check_objects(game) == -1)
		exit(1);
	if (check_lr_map(game) == -1)
		exit(1);
	if (check_tb_map(game) == -1)
		exit(1);
	if (check_valid_rec(game) == -1)
		exit(1);
	k = game->myplayer.h;
	l = game->myplayer.v;
	have_access_e(game, map1, l, k);
	have_access_c(game, map2, l, k);
	free_maps(map1, map2);
}
