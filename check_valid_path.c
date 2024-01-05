#include "so_long.h"

int canReachToE(t_data *game,char **map,int i, int j) {


    if (i < 0 || i >= game->img_height || j < 0 || j >= game->img_width - 1 
    || map[i][j] == '1' || map[i][j] == 'V') {
     return (0);
    }

    if (map[i][j] == 'E')
        return (1);

     map[i][j] = 'V';
    int res = (canReachToE(game,map,i - 1,j)||
              canReachToE(game,map,i + 1,j) ||
              canReachToE(game,map,i,j - 1) ||
              canReachToE(game,map,i,j + 1));
    if (res)
    {
    return (1);
    }
    return 0;

}

int canReachToAllC(t_data *game,char **map,int i, int j) {

    if (i < 0 || i >= game->img_height || j < 0 || j >= game->img_width - 1 
    || map[i][j] == '1' || map[i][j] == 'V') {
     return (0);
    }
    if (map[i][j] == 'C')
    {
        game->c_count--;
        if (game->c_count == 0)
            return (1);
        
    }
     map[i][j] = 'V';
    int res = (canReachToAllC(game,map,i - 1,j)||
              canReachToAllC(game,map,i + 1,j) ||
              canReachToAllC(game,map,i,j - 1) ||
              canReachToAllC(game,map,i,j + 1));

    if (res)
    {
    return (1);
    }
    return 0;
}

void haveAccess(t_data *game,char **map1,char **map2,int k,int l,int a,int b)
{
     if (canReachToE(game,map1,k,l) == 0)
    {
       ft_printf("the way is closed\n");
        exit(1);
    }
    else if (canReachToAllC(game,map2,a,b) == 0)
    {
       ft_printf("the way is closed to c ");      
        exit(1);
    } 
}

