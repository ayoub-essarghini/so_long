#include "so_long.h"


void ft_init(t_data *game)
{
    game->img_empty = mlx_xpm_file_to_image(game->mlx,"textures/empty.xpm",&game->x,&game->y);
    game->img_wall = mlx_xpm_file_to_image(game->mlx,"textures/wall.xpm",&game->x,&game->y);
    game->img_c = mlx_xpm_file_to_image(game->mlx,"textures/collect.xpm",&game->x,&game->y);
    game->img_e = mlx_xpm_file_to_image(game->mlx,"textures/exit.xpm",&game->x,&game->y);
  

}

void player_position(int i, int j, t_data *game)
{
    game->myplayer.v = i;
    game->myplayer.h = j;
    	  game->img_p = mlx_xpm_file_to_image(game->mlx,"textures/player1.xpm",&game->x,&game->y);
    ft_map_pla(i, j, game);
	mlx_destroy_image(game->mlx, game->img_p);
}

void	ft_collpos(int i, int j, t_data *game)
{
	game->coll_sum++;
	game->collected++;
	ft_mapcoll(i, j, game);
}