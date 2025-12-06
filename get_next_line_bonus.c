/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamrani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:22:25 by alamrani          #+#    #+#             */
/*   Updated: 2025/12/02 17:24:11 by alamrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*extract_line(char *stash)
{
	size_t	i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		return (ft_substr(stash, 0, i + 1));
	return (ft_substr(stash, 0, i));
}

static char	*update_stash(char *stash)
{
	size_t	i;
	char	*rest;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	rest = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
	free(stash);
	return (rest);
}

static char	*read_and_join(int fd, char *stash)
{
	char	*buf;
	ssize_t	readed;
	char	*temp;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	readed = 1;
	while (!ft_strchr(stash, '\n') && readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (free(buf), free(stash), NULL);
		if (readed == 0)
			return (free(buf), stash);
		buf[readed] = '\0';
		temp = ft_strjoin(stash, buf);
		if (!temp)
			return (free(buf), free(stash), NULL);
		free(stash);
		stash = temp;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_and_join(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}
