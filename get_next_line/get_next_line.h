/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aes-sarg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:13:31 by aes-sarg          #+#    #+#             */
/*   Updated: 2023/11/30 19:13:36 by aes-sarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_read_to_temp(int fd, char *temp);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *temp, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *temp);
char	*ft_new_temp(char *temp);

#endif
