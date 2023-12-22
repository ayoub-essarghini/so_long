

#include "so_long.h"

int	ft_mapt(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->img_height)
	{
		while (j < game->img_width)
		{
			if (game->map.map[i][j] == '1')
				ft_mapwall(i, j, game);
			else if (game->map.map[i][j] == 'P')
				player_position(i, j, game);
			else if (game->map.map[i][j] == 'C' && game->z)
				ft_collpos(i, j, game);
			else if (game->map.map[i][j] == 'E')
				ft_mapexit(i, j, game);
			j++;
		}
		i++;
		j = 0;
	}
	return (game->z = 0, 0);
}

void	ft_map(t_data *game)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (i < game->img_height)
	{
		while (j < game->img_width - 1)
		{
			ft_map_path(i, j, game);
			j++;
		}
		i++;
		j = 0;
	}
}
