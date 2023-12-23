#include "so_long.h"

void ft_move_up(t_data *game)
{
    int x;
    int y;
    x = game->myplayer.h;
    y = game->myplayer.v;
    if(game->map.map[x - 1][y] == '0' || game->map.map[x - 1][y] == 'C')
    {
        game->myplayer.v--;
        if (game->map.map[x - 1][y] == 'C')
            game->collected--;
        ft_refresh_game(x,y,game);
        game->move++;
        ft_printf("%d",game->move);   
    }
    else
    {
        if (game->map.map[x - 1][y] == 'E')
        {
        game->myplayer.v--;
        ft_refresh_game(x,y,game);
        checkcollectable(game);
        game->move++;
        ft_printf("%d",game->move);
        }

    }
}
void ft_move_down(t_data *game)
{
    int x;
    int y;
    x = game->myplayer.h;
    y = game->myplayer.v;
    if(game->map.map[x + 1][y] == '0' || game->map.map[x + 1][y] == 'C')
    {
        game->myplayer.v++;
        if (game->map.map[x + 1][y] == 'C')
            game->collected--;
        ft_refresh_game(x,y,game);
        game->move++;
        ft_printf("%d",game->move);   
    }
    else
    {
        if (game->map.map[x + 1][y] == 'E')
        {
        game->myplayer.v++;
        // ft_refresh_game(x,y,game);
        checkcollectable(game);
        game->move++;
        ft_printf("%d",game->move);
        }

    }
}

void ft_move_left(t_data *game)
{
    int x;
    int y;
    x = game->myplayer.h;
    y = game->myplayer.v;
    if(game->map.map[x ][y - 1] == '0' || game->map.map[x][y - 1] == 'C')
    {
        game->myplayer.h--;
        if (game->map.map[x][y - 1] == 'C')
            game->collected--;
        ft_refresh_game(x,y,game);
        game->move++;
        ft_printf("%d",game->move);   
    }
    else
    {
        if (game->map.map[x][y - 1] == 'E')
        {
        game->myplayer.h--;
        //ft_refresh_game(x,y,game);
        checkcollectable(game);
        game->move++;
        ft_printf("%d",game->move);
        }

    }
}

void ft_move_right(t_data *game)
{
    int x;
    int y;
    x = game->myplayer.h;
    y = game->myplayer.v;
    if(game->map.map[x][y + 1] == '0' || game->map.map[x][y + 1] == 'C')
    {
        game->myplayer.h++;
        if (game->map.map[x][y + 1] == 'C')
            game->collected--;
        ft_refresh_game(x,y,game);
        game->move++;
        ft_printf("%d",game->move);   
    }
    else
    {
        if (game->map.map[x][y + 1] == 'E')
        {
        game->myplayer.h++;
        ft_refresh_game(x,y,game);
        checkcollectable(game);
        game->move++;
        ft_printf("%d",game->move);
        }

    }
}
int ft_move(int keycode, t_data *game)
{
    // The keycode for the 'ESC' key is 53
    //  printf("Key pressed: %d\n", keycode);
    if (keycode == ESC_KEY)
        exit(0);
    if (keycode == W_KEY)
        ft_move_up(game);
    if (keycode == A_KEY)
        ft_move_left(game);
    if (keycode == S_KEY)
        ft_move_down(game);
    if (keycode == D_KEY)
        ft_move_right(game);

    return (0);
}