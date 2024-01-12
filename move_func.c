/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:50:45 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/12 21:25:09 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_move_up(t_data *game)
{
	int	i;
	int	j;

	i = game->myplayer.v;
	j = game->myplayer.h;
	if (game->map.map[i - 1][j] == '0' || game->map.map[i - 1][j] == 'C')
	{
		game->myplayer.v--;
		if (game->map.map[i - 1][j] == 'C')
			game->collected--;
		ft_refresh_game(i, j, game);
		game->move++;
		ft_printf("%d\n", game->move);
	}
	else if (game->map.map[i - 1][j] == 'E')
	{
		game->myplayer.v--;
		ft_refresh_game(i, j, game);
		checkcollectable(game);
		game->move++;
		ft_printf("%d\n", game->move);
	}
}

void	ft_move_down(t_data *game)
{
	int	i;
	int	j;

	i = game->myplayer.v;
	j = game->myplayer.h;
	if (game->map.map[i + 1][j] == '0' || game->map.map[i + 1][j] == 'C')
	{
		game->myplayer.v++;
		if (game->map.map[i + 1][j] == 'C')
			game->collected--;
		ft_refresh_game(i, j, game);
		game->move++;
		ft_printf("%d\n", game->move);
	}
	else if (game->map.map[i + 1][j] == 'E')
	{
		game->myplayer.v++;
		ft_refresh_game(i, j, game);
		checkcollectable(game);
		game->move++;
		ft_printf("%d\n", game->move);
	}
}

void	ft_move_left(t_data *game)
{
	int	i;
	int	j;

	i = game->myplayer.v;
	j = game->myplayer.h;
	if (game->map.map[i][j - 1] == '0' || game->map.map[i][j - 1] == 'C')
	{
		game->img_p_path = "textures/player_left.xpm";
		game->myplayer.h--;
		if (game->map.map[i][j - 1] == 'C')
			game->collected--;
		ft_refresh_game(i, j, game);
		game->move++;
		ft_printf("%d\n", game->move);
	}
	else if (game->map.map[i][j - 1] == 'E')
	{
		game->myplayer.h--;
		ft_refresh_game(i, j, game);
		checkcollectable(game);
		game->move++;
		ft_printf("%d\n", game->move);
	}
}

void	ft_move_right(t_data *game)
{
	int	i;
	int	j;

	i = game->myplayer.v;
	j = game->myplayer.h;
	if (game->map.map[i][j + 1] == '0' || game->map.map[i][j + 1] == 'C')
	{
		game->img_p_path = "textures/player1.xpm";
		game->myplayer.h++;
		if (game->map.map[i][j + 1] == 'C')
			game->collected--;
		ft_refresh_game(i, j, game);
		game->move++;
		ft_printf("%d\n", game->move);
	}
	else if (game->map.map[i][j + 1] == 'E')
	{
		game->myplayer.h++;
		ft_refresh_game(i, j, game);
		checkcollectable(game);
		game->move++;
		ft_printf("%d\n", game->move);
	}
}

int	ft_move(int keycode, t_data *game)
{
	if (keycode == ESC_KEY)
		exit(0);
	if (keycode == W_KEY)
		ft_move_up(game);
	if (keycode == S_KEY)
		ft_move_down(game);
	if (keycode == A_KEY)
		ft_move_left(game);
	if (keycode == D_KEY)
		ft_move_right(game);
	return (0);
}
