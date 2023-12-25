#include "so_long.h"

void ft_init(t_data *game)
{
    game->img_empty_path = "textures/empty.xpm";
    game->img_empty = mlx_xpm_file_to_image(game->mlx, game->img_empty_path, &game->i, &game->j);
    game->img_wall_path = "textures/wall.xpm";
    game->img_wall = mlx_xpm_file_to_image(game->mlx, game->img_wall_path, &game->i, &game->j);
    game->img_c_path = "textures/collect.xpm";
    game->img_c = mlx_xpm_file_to_image(game->mlx, game->img_c_path, &game->i, &game->j);
    game->img_exit_path = "textures/exit.xpm";
    game->img_e = mlx_xpm_file_to_image(game->mlx, game->img_exit_path, &game->i, &game->j);
    // game->img_p = mlx_xpm_file_to_image(game->mlx,"textures/player1.xpm",&game->x,&game->y);
}

void player_position(int i, int j, t_data *game)
{
    char *player;

    player = "textures/player1.xpm";
    game->myplayer.v = i;
    game->myplayer.h = j;
    game->img_p = mlx_xpm_file_to_image(game->mlx, player,
                                         &game->i, &game->j);
    ft_map_pla(i, j, game);
    mlx_destroy_image(game->mlx, game->img_p);
}

void ft_collpos(int i, int j, t_data *game)
{
    game->coll_sum++;
    game->collected++;
    ft_mapcoll(i, j, game);
}