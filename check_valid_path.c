/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:43:03 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/13 17:10:27 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**map_dup(char **map, int len)
{
	char	**map2;
	int		i;

	i = 0;
	map2 = (char **)malloc((len + 1) * sizeof(char *));
	while (i < len)
	{
		map2[i] = ft_strdup(map[i]);
		i++;
	}
	map2[i] = NULL;
	return (map2);
}

int	can_reach_e(t_data *game, char **map, int i, int j)
{
	int	res;

	if (i < 0 || i >= game->img_height
		|| j < 0 || j >= game->img_width
		|| map[i][j] == '1' || map[i][j] == 'V')
	{
		return (0);
	}
	if (map[i][j] == 'E')
		return (1);
	map[i][j] = 'V';
	res = (can_reach_e(game, map, i - 1, j)
			|| can_reach_e(game, map, i + 1, j)
			|| can_reach_e(game, map, i, j - 1)
			|| can_reach_e(game, map, i, j + 1));
	if (res)
		return (1);
	return (0);
}

int	can_reach_to_all_c(t_data *game, char **map, int i, int j)
{
	int	res;

	if (i < 0 || i >= game->img_height || j < 0
		|| j >= game->img_width
		|| map[i][j] == '1'
		|| map[i][j] == 'V')
	{
		return (0);
	}
	if (map[i][j] == 'C')
	{
		game->c_count--;
		if (game->c_count == 0)
			return (1);
	}
	map[i][j] = 'V';
	res = (can_reach_to_all_c(game, map, i - 1, j)
			|| can_reach_to_all_c(game, map, i + 1, j)
			|| can_reach_to_all_c(game, map, i, j - 1)
			|| can_reach_to_all_c(game, map, i, j + 1));
	if (res)
		return (1);
	return (0);
}

void	have_access_e(t_data *game, char **map1, int k, int l)
{
	if (can_reach_e(game, map1, k, l) == 0)
	{
		ft_printf("Error\nthe way is closed to E\n");
		exit(1);
	}
}

void	have_access_c(t_data *game, char **map2, int a, int b)
{
	if (can_reach_to_all_c(game, map2, a, b) == 0)
	{
		ft_printf("Error\nthe way is closed to C\n");
		exit(1);
	}
}
