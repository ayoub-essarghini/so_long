#include "so_long.h"

void ft_init(t_data *game)
{
      game->img_p_path = "textures/player1.xpm";
    game->img_empty = mlx_xpm_file_to_image(game->mlx,"textures/empty.xpm", &game->i, &game->j);
    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->i, &game->j);
    game->img_c = mlx_xpm_file_to_image(game->mlx,"textures/collect.xpm", &game->i, &game->j);
    game->img_e = mlx_xpm_file_to_image(game->mlx,"textures/exit.xpm", &game->i, &game->j);
}

void player_position(int i, int j, t_data *game)
{
    game->myplayer.v = i;
    game->myplayer.h = j;
    game->img_p = mlx_xpm_file_to_image(game->mlx,game->img_p_path, &game->i, &game->j);
    ft_map_pla(i, j, game);
    mlx_destroy_image(game->mlx, game->img_p);
}

void ft_collpos(int i, int j, t_data *game)
{
    game->collected++;
    ft_mapcoll(i, j, game);
}