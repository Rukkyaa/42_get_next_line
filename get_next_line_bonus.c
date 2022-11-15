/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axlamber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:19:33 by axlamber          #+#    #+#             */
/*   Updated: 2022/11/14 08:17:45 by axlamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*before(char *buffer)
{
	char			*split;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(*buffer))
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i ++;
	if (buffer[i] == '\n')
		i ++;
	split = malloc((i + 1) * sizeof(char));
	if (!split)
		return (NULL);
	while (j < i)
	{
		split[j] = buffer[j];
		j ++;
	}
	split[j] = '\0';
	return (split);
}

static char	*after(char *buffer)
{
	char			*split;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i ++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i ++;
	split = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!split)
		return (NULL);
	while (buffer[i])
		split[j++] = buffer[i++];
	split[j] = '\0';
	free(buffer);
	return (split);
}

char	*get_line(int fd, char *save)
{
	char	*buffer;
	int		readed;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(save, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		if (!save)
			save = ft_strdup(buffer);
		else
			save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = get_line(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = before(save[fd]);
	save[fd] = after(save[fd]);
	return (line);
}

/*
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("Line : %s", line);
		free(line);
	}
	return (0);
}
*/
