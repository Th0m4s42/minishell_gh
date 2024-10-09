/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:11:01 by thbasse           #+#    #+#             */
/*   Updated: 2024/04/15 07:22:04 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*ft_save(char *line)
{
	char	*saved;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line [1] == '\0')
		return (NULL);
	saved = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (saved != NULL && *saved == '\0')
		return (saved);
	line[i + 1] = '\0';
	return (saved);
}

static char	*ft_line(int fd, char *buffer, char *save)
{
	int		byte_read;
	char	*temp;

	byte_read = 1;
	while (byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		else if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		if (!save)
			save = ft_strdup("");
		if (save == NULL)
			return (NULL);
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(save), save = NULL, NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	line = ft_line(fd, buffer, save);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	save = ft_save(line);
	if (save != NULL && *(save) == '\0')
	{
		free(save);
		save = NULL;
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd = open("test.txt", O_RDONLY);
// 	char	*line;

// 	printf("fd: %i\n", fd);

// 	for (int i = 0 ; i < 40 ; i ++)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line != NULL)
// 			free(line);
// 	}

// 	return (0);
// }
