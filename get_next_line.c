/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:31:26 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/30 23:41:03 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static long long	find_newline(char *text)
{
	long long	i;

	if (!text || text[0] == '\0')
		return (-1);
	i = 0;
	while (text[i])
	{
		if (text[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	update_text(int fd, char buf[BUFFER_SIZE + 1], char **text)
{
	long long	bytes_read;
	char		*new_text;

	while (find_newline(*text) == -1)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(*text);
			text = NULL;
			return ;
		}
		if (bytes_read == 0)
			return ;
		buf[bytes_read] = '\0';
		new_text = ft_strjoin(*text, buf);
		free(*text);
		*text = new_text;
		if (!*text)
			return ;
	}
}

static char	*get_line(char **text)
{
	char		*line;
	char		*new_text;
	long long	nl;
	size_t		leftover_len;

	if (!*text || (*text)[0] == '\0')
		return (NULL);
	nl = find_newline(*text);
	if (nl == -1)
	{
		line = ft_strdup(*text);
		free(*text);
		*text = NULL;
		return (line);
	}
	line = ft_substr(*text, 0, nl + 1);
	leftover_len = ft_strlen(*text + nl + 1);
	new_text = ft_substr(*text, nl + 1, leftover_len);
	free(*text);
	*text = new_text;
	return (line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*text;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	update_text(fd, buf, &text);
	line = get_line(&text);
	return (line);
}
