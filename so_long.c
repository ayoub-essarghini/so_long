
#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}

int main(int ac, char **av)
{
    t_data data;

    if (ac != 2)
    {
        ft_printf("please insert map");
        exit(0);
    }
    ft_memset(&data, 0, sizeof(t_data));
    read_map(&data, av);
    check_valid_map(&data);
    read_map(&data, av);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, (data.img_width - 1) * 100, (data.img_height) * 100, "SO_LONG");
    ft_init(&data);
    draw_path(&data);
    draw_map(&data);
    mlx_hook(data.win, 2, (1L << 0),ft_move, &data);
    mlx_hook(data.win, 17, (1L << 17),ft_exit, &data);
    mlx_loop(data.mlx);
    return 0;
}
