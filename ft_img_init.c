/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:32:05 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/12 21:13:58 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_init(t_data *game)
{
	game->img_p_path = "textures/player1.xpm";
	game->img_exit_path = "textures/exit.xpm";
	game->img_empty = mlx_xpm_file_to_image(game->mlx,
			"textures/empty.xpm", &game->i, &game->j);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->i, &game->j);
	game->img_c = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm", &game->i, &game->j);
	game->img_e = mlx_xpm_file_to_image(game->mlx,
			game->img_exit_path, &game->i, &game->j);
	if (!game->img_c || !game->img_wall || !game->img_e || !game->img_empty)
	{
		ft_printf("Error\ninvalid image\n");
		exit(1);
	}
}

void	player_position(int i, int j, t_data *game)
{
	game->myplayer.v = i;
	game->myplayer.h = j;
	game->img_p = mlx_xpm_file_to_image(game->mlx,
			game->img_p_path, &game->i, &game->j);
	ft_map_pla(i, j, game);
	mlx_destroy_image(game->mlx, game->img_p);
}

void	ft_collpos(int i, int j, t_data *game)
{
	game->collected++;
	ft_mapcoll(i, j, game);
}
