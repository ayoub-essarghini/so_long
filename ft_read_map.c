/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:41:06 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/22 15:01:51 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	is_valid_map(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\n')
	{
		ft_printf("Error\ninvalid map");
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			ft_printf("Error\ninvalid map");
			return (0);
		}
		i++;
	}
	if (i > 0 && str[i - 1] == '\n')
	{
		ft_printf("Error\ninvalid map");
		return (0);
	}
	return (1);
}

void	allocate_and_free_temp(t_data *game, int nbr_lines, char *temp)
{
	char	**temp_map;
	int		i;

	i = 0;
	game->map.map = (char **)malloc((nbr_lines + 1) * sizeof(char *));
	if (is_valid_map(temp) == 0)
	{
		free(temp);
		exit(0);
	}
	temp_map = ft_split(temp, '\n');
	while (i < nbr_lines)
	{
		game->map.map[i] = ft_strdup(temp_map[i]);
		i++;
	}
	game->map.map[i] = NULL;
	i = 0;
	while (i < nbr_lines)
	{
		free(temp_map[i]);
		i++;
	}
	free(temp_map);
}

int	read_map(t_data *game, char *av[])
{
	int		fd;
	int		nbr_lines;
	char	*str;
	char	*temp;

	fd = open(av[1], O_RDONLY);
	nbr_lines = 0;
	temp = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
		{
			break ;
		}
		nbr_lines++;
		temp = ft_strjoin(temp, str);
		free(str);
	}
	close(fd);
	allocate_and_free_temp(game, nbr_lines, temp);
	game->img_height = nbr_lines;
	game->img_width = ft_strlen(game->map.map[0]);
	free(temp);
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
			ft_printf("Error\ninvalid map");
			return (-1);
		}
		i++;
	}
	return (0);
}
