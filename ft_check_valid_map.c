#include "so_long.h"

int check_lr_map(t_data *game)
{
    int h;
    int w;

    h = 0;
    w = 0;
    while (h < game->img_height)
    {
        if (game->map.map[h][w] != '1')
            return (-1);
        h++;
    }
    h = 0;
    w = 0;
    while (w < game->img_width - 1)
    {
        if (game->map.map[h][w] != '1')
            return (-1);
        w++;
    }
    return (0);
}

int check_tb_map(t_data *game)
{
    int h;
    int w;

    h = 0;
    w = game->img_width - 2;
    while (h < game->img_height)
    {
        if (game->map.map[h][w] != '1')
        {
            return -1;
        }
        h++;
    }
    h = 0;
    w = 0;
    while (w < game->img_width - 1)
    {
        if (game->map.map[h][w] != '1')
        {
            return -1;
        }
        w++;
    }
    return 0;
}

int check_full_map(t_data *game)
{
    int h;
    int w;

    h = 0;
    while (h < game->img_height)
    {
        w = 0;
        while (w < game->img_width - 1)
        {
            char x = game->map.map[h][w];
            if (x != '0' && x != '1' && x != 'C' && x != 'P' && x != 'E')
            {
                return -1;
            }
            w++;
        }
        h++;
    }
    return 0;
}

int check_objects(t_data *game)
{
    int h = 0;
    int w;

    game->p_count = 0;
    game->c_count = 0;
    game->e_count = 0;
    while (h < game->img_height)
    {
        w = 0;
        while (w < game->img_width)
        {
            if (game->map.map[h][w] == 'P')
                game->p_count++;
            else if (game->map.map[h][w] == 'C')
                game->c_count++;
            else if (game->map.map[h][w] == 'E')
                game->e_count++;
            w++;
        }
        h++;
    }

    if (game->p_count != 1 || game->e_count < 1 || game->c_count < 1)
        return -1;
    else
        return 0;
}

void check_valid_map(t_data *game)
{
    if (check_full_map(game) == -1)
        exit(1);
    if (check_objects(game) == -1)
        exit(1);
    if (check_lr_map(game) == -1)
        exit(1);
    if (check_tb_map(game) == -1)
        exit(1);
    if (check_valid_rec(game) == -1)
        exit(1);
}