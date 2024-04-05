/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbaraka <elbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 06:13:04 by elbaraka          #+#    #+#             */
/*   Updated: 2024/04/02 23:22:14 by elbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	find_next_line_break(char *str)
{
	size_t	i;

	i = 0;
	printf("%s\n", str);
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (str[i]);
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
	if (!buff)
		return (NULL);
	while (find_next_line_break(str) == 0 && read_bytes)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		if (read_bytes == 0)
		{
			// free(str);
			 free(buff);
			return (str);
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
	// printf("STR = %s\n", str);
	int		i;
	char	*stock;

	i = 0;
	if (!str)
		return (NULL);
	stock = (char *)malloc(strlen_newline(str) + 2);
	if (!stock)
		return (NULL);
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
	static char		*r_buff;
	char			*before;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	r_buff = read_line(fd, r_buff);
	if (!r_buff)
	{
		return (NULL);
		free(r_buff);
	}
	before = new_line(r_buff);
	r_buff = after_new_line(r_buff);
	printf("before --> r_buff = %s\n", r_buff);
	return (before);
}




 int	main(void)
{
	// printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	int fd = open("aaaa.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while(line)
	{
		
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		//  if (get_next_line(fd) ==  NULL)
		//  	break ;
	}

 	close(fd);


	

	return (0);
}
