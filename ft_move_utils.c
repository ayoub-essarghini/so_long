#include "so_long.h"

// void ft_open_door(t_data *game)
// {
//     if (game->collected == 0)
//             ft_
// }

void sync_map(int x, int y, t_data *game)
{
	int i;
	int j;

	i = game->myplayer.v;
	j = game->myplayer.h;
	if (game->map.map[x][y] == 'E')
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
	ft_printf("problem in sync");
}

int ft_map_update(int x, int y, t_data *game)
{
	int i;
	int j;

	i = game->myplayer.v;
	j = game->myplayer.h;
	if (game->map.map[x][y] == 'E')
	{
		game->map.map[x][y] = 'E';
		game->map.map[i][j] = 'P';
	}
	else
	{
		game->map.map[x][y] = '0';
		// if (game->map.map[i][j] == 'E')
		// 	game->map.map[i][j] = 'G';
		// else
		game->map.map[i][j] = 'P';
	}
	ft_printf("problem in update");
	return (0);
}

void ft_refresh_game(int x, int y, t_data *game)
{
	ft_map_update(x, y, game);
	sync_map(x, y, game);
	ft_printf("problem when refresh");
}

void checkcollectable(t_data *game)
{
	if (game->collected == 0)
	{
		printf(" _   _    __        __   ___    _   _ \n");
		printf("| | | |   \\ \\      / /  / _ \\  | \\ | |\n");
		printf("| | | |    \\ \\ /\\ / /  | | | | |  \\| |\n");
		printf("| |_| |     \\ V  V /   | |_| | | |\\  |\n");
		printf(" \\___/       \\_/\\_/     \\___/  |_| \\_|\n");
		free(game->map.map);
		exit(0);
	}
}

int ft_exit(void)
{
	exit(0);
}