#include "so_long.h"

int canReachToE(t_data *game,int i, int j) {

    if (i < 0 || i >= game->img_height || j < 0 || j >= game->img_width - 1 
    || game->map.map[i][j] == '1' || game->map.map[i][j] == 'V') {
     return (0);
    }

    if (game->map.map[i][j] == 'E')
        return (1);

     game->map.map[i][j] = 'V';
  

    int res = (canReachToE(game,i - 1,j)||
              canReachToE(game,i + 1,j) ||
              canReachToE(game,i,j - 1) ||
              canReachToE(game,i,j + 1));

    if (res)
    {
    return (1);
    }
    return 0;

}

int canReachToAllC(t_data *game,int i, int j) {

    if (i < 0 || i >= game->img_height || j < 0 || j >= game->img_width - 1 
    || game->map.map[i][j] == '1' || game->map.map[i][j] == 'V') {
     return (0);
    }

    if (game->map.map[i][j] == 'C')
    {
        return (1);
    }
     game->map.map[i][j] = 'V';
  

    int res = (canReachToAllC(game,i - 1,j)||
              canReachToAllC(game,i + 1,j) ||
              canReachToAllC(game,i,j - 1) ||
              canReachToAllC(game,i,j + 1));

    if (res)
    {
    return (1);
    }
    return 0;

}

