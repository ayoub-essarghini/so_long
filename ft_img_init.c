#include "so_long.h"


void ft_init(t_data *game)
{
    game->img_empty = mlx_xpm_file_to_image(game->mlx,"textures/grass.xpm",&game->x,&game->y);
    game->img_wall = mlx_xpm_file_to_image(game->mlx,"textures/wall.xpm",&game->x,&game->y);
    game->img_c = mlx_xpm_file_to_image(game->mlx,"textures/grass.xpm",&game->x,&game->y);
    game->img_e = mlx_xpm_file_to_image(game->mlx,"textures/grass.xpm",&game->x,&game->y);

}

void player_position(int i, int j, t_data *game)
{
    game->myplayer.v = i;
    game->myplayer.h = j;
    game->img_p = mlx_xpm_file_to_image(game->mlx,"textures/grass.xpm",&game->x,&game->y);
    mlx_put_image_to_window(game->mlx,game->win,game->img_p,i * 100, j * 100);
}