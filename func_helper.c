/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:23:16 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/06 16:50:14 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

void	get_p_position(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->img_height)
	{
		j = 0;
		while (j < game->img_width)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->myplayer.h = j;
				game->myplayer.v = i;
			}
			j++;
		}
		i++;
	}
}

char	*ft_strdup(char *s)
{
	char	*d;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_strlen(s);
	d = (char *) malloc((str_len * sizeof(char)) + 1);
	if (!d)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
	return (d);
}
