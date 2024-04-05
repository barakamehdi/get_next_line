/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbaraka <elbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:09:04 by elbaraka          #+#    #+#             */
/*   Updated: 2024/04/04 05:12:01 by elbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	find_next_line_break(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static char	*read_line(int fd, char *str)
{
	char	*buff;
	int		read_bytes;

	read_bytes = 1;
	buff = (char *)malloc(BUFFER_SIZE + 1);
	while (find_next_line_break(str) == 0 && read_bytes)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

// static char	*free_and_null(char *buff1, char *buff2)
// {
// 	free (buff1);
// 	free (buff2);
// 	return (NULL);
// }

char	*new_line(char *str)
{
	int		i;
	char	*stock;

	i = 0;
	if (!str)
		return (NULL);
	stock = (char *)malloc(strlen_newline(str + 1));
	while (str[i] && str[i] != '\n')
	{
		stock[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		stock[i] = str[i];
		i++;
	}
	stock[i] = '\0';
	return (stock);
}

char	*get_next_line(int fd)
{
	static char		*r_buff[OPEN_MAX];
	char			*before;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	r_buff[fd] = read_line(fd, r_buff[fd]);
	if (!r_buff[fd])
	{
		return (NULL);
		free(r_buff[fd]);
	}
	before = new_line(r_buff[fd]);
	r_buff[fd] = after_new_line(r_buff[fd]);
	return (before);
}
// int	main(void)
// {
// 	// printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);

// 	int fd = open("aaaa.txt", O_RDONLY);
	

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));

// 	close(fd);

// 	return (0);
// }
