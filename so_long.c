/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:58:42 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/06 17:02:16 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		ft_printf("please insert map");
		exit(0);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
		return (perror("Map path not valid"), 1);
	ft_memset(&data, 0, sizeof(t_data));
	read_map(&data, av);
	check_valid_map(&data);
	read_map(&data, av);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, (data.img_width - 1) * 100,
			(data.img_height) * 100, "SO_LONG");
	ft_init(&data);
	draw_path(&data);
	draw_map(&data);
	mlx_hook(data.win, 2, (1L << 0), ft_move, &data);
	mlx_hook(data.win, 17, (1L << 17), ft_exit, &data);
	mlx_loop(data.mlx);
	return (0);
}
