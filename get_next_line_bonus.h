/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elbaraka <elbaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:08:27 by elbaraka          #+#    #+#             */
/*   Updated: 2024/04/04 23:33:32 by elbaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*new_line(char *str);
char	*after_new_line(char *str);
size_t  strlen_newline(char *str);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	find_next_line_break(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 904659
# endif

#endif