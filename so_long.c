
#include "so_long.h"

int main(int ac, char **av)
{
    t_data data;

    if (ac != 2)
    {
        ft_printf("please insert map");
        exit(0);
    }
    mapread(&data, av);
    check_map(&data);
    data.mlx = mlx_init();
    if (!data.mlx)
        return 1;
    data.win = mlx_new_window(data.mlx, (data.img_width - 1) * 100, (data.img_height) * 100, "SO_LONG");
    if (!data.win)
        return 1;
    ft_init(&data);
    ft_map(&data);
    ft_mapt(&data);
    // draw_map(&data);
    mlx_loop(data.mlx);

    return 0;
}
