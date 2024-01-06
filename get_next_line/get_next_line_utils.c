/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:12:33 by aes-sarg          #+#    #+#             */
/*   Updated: 2023/11/30 19:12:37 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *temp, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!temp)
	{
		temp = (char *)malloc(1 * sizeof(char));
		temp[0] = '\0';
	}
	if (!temp || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(temp) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (temp)
		while (temp[++i] != '\0')
			str[i] = temp[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(temp) + ft_strlen(buff)] = '\0';
	free(temp);
	return (str);
}

char	*ft_get_line(char *temp)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if (!temp[i])
		return (NULL);
	while (temp[i] && temp[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
	{
		str[i] = temp[i];
		i++;
	}
	if (temp[i] == '\n')
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_temp(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (temp[i])
		str[j++] = temp[i++];
	str[j] = '\0';
	free(temp);
	return (str);
}
