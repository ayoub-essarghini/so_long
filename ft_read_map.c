/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:41:06 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/06 16:48:48 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	count_ln(char **av)
{
	int		fd;
	int		nbr_lines;
	char	*str;

	fd = open(av[1], O_RDONLY);
	nbr_lines = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		free(str);
		nbr_lines++;
	}
	close(fd);
	return (nbr_lines);
}

int	read_map(t_data *game, char *av[])
{
	int		fd;
	int		nbr_lines;
	char	*str;

	nbr_lines = count_ln(av);
	if (!nbr_lines)
		return (nbr_lines);
	fd = open(av[1], O_RDONLY);
	game->map.map = (char **)malloc(nbr_lines * sizeof(char *));
	nbr_lines = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		game->map.map[nbr_lines] = str;
		nbr_lines++;
	}
	close(fd);
	game->img_height = nbr_lines;
	game->img_width = ft_strlen(game->map.map[0]);
	return (nbr_lines);
}

int	check_valid_rec(t_data *game)
{
	int		i;
	size_t	w_len;

	i = 0;
	w_len = ft_strlen(game->map.map[0]);
	while (i < game->img_height)
	{
		if (ft_strlen(game->map.map[i]) != w_len)
		{
			return (-1);
		}
		i++;
	}
	return (0);
}
