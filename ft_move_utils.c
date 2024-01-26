/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:37:32 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/21 23:50:25 by aes-sarg         ###   ########.fr       */
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
	game->map.map[x][y] = '0';
	game->map.map[i][j] = 'P';
	return (0);
}

void	ft_sync_map(int x, int y, t_data *game)
{
	int	i;
	int	j;

	i = game->myplayer.v;
	j = game->myplayer.h;
	ft_map_path(x, y, game);
	ft_map_pla(i, j, game);
}

void	ft_refresh_game(int i, int j, t_data *game)
{
	ft_map_update(i, j, game);
	ft_sync_map(i, j, game);
}

void	checkcollectable(t_data *game)
{
	int	i;

	i = 0;
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
		ft_printf("\nYou Win!\n");
		while (i < game->img_height)
		{
			free(game->map.map[i]);
			i++;
		}
		free(game->map.map);
		exit(0);
	}
}
