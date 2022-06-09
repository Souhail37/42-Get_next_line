/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:04:37 by sismaili          #+#    #+#             */
/*   Updated: 2021/12/14 21:01:10 by sismaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_fd(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buffer);
			return (0);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer, 0, -1);
	}
	free (buffer);
	return (str);
}

char	*ft_first_line(char *str)
{
	char	*first;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	first = (char *)malloc(sizeof(char) * i + 1 + (str[i] == '\n'));
	if (!first)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		first[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		first[i] = str[i];
		i++;
	}
	first[i] = '\0';
	return (first);
}

char	*ft_next(char *str)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free (str);
		return (0);
	}
	next = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!next)
		return (0);
	i++;
	while (str[i])
		next[j++] = str[i++];
	next[j] = '\0';
	free (str);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer[fd] = ft_read_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = ft_first_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main()
// {
//     int fd1 = open("test", O_RDONLY);
//     int fd2 = open("hello", O_RDONLY);
//     char *str;
// 	char *s;

//     str = get_next_line(fd1);
//     s = get_next_line(fd2);
//     while (str || s)
//     {
//         printf("%s", str);
//         printf("%s", s);
//         free (str);
// 		free (s);
//         str = get_next_line(fd1);
//         s = get_next_line(fd2);
//     }
// }
