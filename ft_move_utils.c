/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:37:32 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/06 16:40:21 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_exit(void)
{
	exit(0);
}

int	ft_map_update(int x, int y, t_data *game)
{
	int	i;
	int	j;

	i = game->myplayer.v;
	j = game->myplayer.h;
	if (game->map.map[x][y] == 'E' || game->map.map[x][y] == 'K')
	{
		game->map.map[x][y] = 'E';
		game->map.map[i][j] = 'P';
	}
	else
	{
		game->map.map[x][y] = '0';
		if (game->map.map[i][j] == 'E')
			game->map.map[i][j] = 'K';
		else
			game->map.map[i][j] = 'P';
	}
	return (0);
}

void	ft_sync_map(int x, int y, t_data *game)
{
	int	i;
	int	j;

	i = game->myplayer.v;
	j = game->myplayer.h;
	if (game->map.map[x][y] == 'E' || game->map.map[x][y] == 'K')
	{
		ft_map_pla(i, j, game);
		ft_mapwall(x, y, game);
		ft_map_path(x, y, game);
		ft_mapexit(x, y, game);
	}
	else
	{
		ft_map_path(x, y, game);
		if (game->map.map[x][y] == 'E')
		{
			ft_map_path(x, y, game);
			ft_mapexit(x, y, game);
		}
		else
			ft_map_pla(i, j, game);
	}
}

void	ft_refresh_game(int i, int j, t_data *game)
{
	ft_map_update(i, j, game);
	ft_sync_map(i, j, game);
}

void	checkcollectable(t_data *game)
{
	if (game->collected == 0)
	{
		ft_printf("\033[0;32m   ( )\n");
		ft_printf("   _H_\n");
		ft_printf(".-'---'-.\n");
		ft_printf("\\-------/\n");
		ft_printf(" '._._.'\n");
		ft_printf("   ( )\n");
		ft_printf("    H\n");
		ft_printf("   _H_\n");
		printf("\nYou Win!\n");
		free(game->map.map);
		exit(0);
	}
}
