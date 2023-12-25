#include "so_long.h"

void	ft_mapwall(int i, int j, t_data *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
		j * 100, i * 100);
}

void	ft_map_pla(int i, int j, t_data *game)
{
	game->img_p = mlx_xpm_file_to_image(game->mlx,"textures/player1.xpm",&game->i,&game->j);
	mlx_put_image_to_window(game->mlx, game->win, game->img_p,
		j * 100, i * 100);
}

void	ft_mapcoll(int i, int j, t_data *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_c,
		j * 100, i * 100);
}

void	ft_mapexit(int i, int j, t_data *game)
{
	
	mlx_put_image_to_window(game->mlx, game ->win, game->img_e,
		j * 100, i * 100);
}

void	ft_map_path(int i, int j, t_data *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_empty, j * 100, i * 100);
}
