/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:22:26 by aes-sarg          #+#    #+#             */
/*   Updated: 2024/01/12 21:22:31 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**ft_free(char **s, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	cmp;
	int	vrf;

	i = 0;
	cmp = 0;
	vrf = 0;
	while (s[i])
	{
		if (s[i] != c && vrf == 0)
		{
			cmp++;
			vrf = 1;
		}
		else if (s[i] == c)
			vrf = 0;
		i++;
	}
	return (cmp);
}

char	*ft_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(end - start + 1);
	if (!word)
		return (0);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_sep_word(const char *str, char c, int l)
{
	int		i;
	char	**p;
	int		start;
	int		j;

	i = 0;
	j = 0;
	start = 0;
	p = (char **)malloc(sizeof(char *) * (l + 1));
	if (!p)
		return (NULL);
	while (str[i] && j < l)
	{
		while (str[i++] == c)
			start = i;
		while (str[i] != c && str[i])
			i++;
		p[j] = ft_word(str, start, i);
		if (!p[j])
			return (ft_free(p, j));
		j++;
	}
	p[j] = NULL;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**w;
	int		h;

	if (s == NULL)
		return (NULL);
	h = count_words(s, c);
	w = ft_sep_word(s, c, h);
	return (w);
}
