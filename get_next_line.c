/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noaziki <noaziki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:58:55 by noaziki           #+#    #+#             */
/*   Updated: 2024/12/28 10:29:00 by noaziki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_line(int fd, char *rest, char *buffer)
{
	ssize_t		read_char;
	char		*tmp;

	while (!ft_strchr(rest, '\n'))
	{
		read_char = read(fd, buffer, BUFFER_SIZE);
		if (read_char < 0)
		{
			free(buffer);
			free(rest);
			return (NULL);
		}
		if (read_char == 0)
			break ;
		buffer[read_char] = '\0';
		tmp = rest;
		rest = ft_strjoin(tmp, buffer);
		free (tmp);
	}
	return (free (buffer), rest);
}

char	*fix_line(char *bufl)
{
	char	*rest;
	size_t	i;

	i = 0;
	while (bufl[i] != '\0' && bufl[i] != '\n')
		i++;
	rest = ft_substr(bufl, i + 1, ft_strlen(bufl) - i);
	if (!rest)
		return (NULL);
	if (bufl[i] != 0)
		bufl[i + 1] = '\0';
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free (rest), rest = NULL, NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (free (rest), rest = NULL, NULL);
	line = find_line(fd, rest, buffer);
	if (!line)
		return (rest = NULL, NULL);
	rest = fix_line(line);
	if (!rest)
		return (free(line), NULL);
	if (line[0] == 0)
		return (free (rest), free (line), rest = NULL);
	buffer = ft_strdup(line);
	free(line);
	if (!buffer)
		return (free(rest), rest = NULL, NULL);
	return (buffer);
}
