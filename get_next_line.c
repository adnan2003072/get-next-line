/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:31:26 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/25 17:33:54 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	find_newline(char *text)
{
	long	i;

	if (!text)
		return (-1);
	i = 0;
	while (text[i])
	{
		if (text[i] == '\n' || text[i] == EOF)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*leftover;
	char		*line;
	long		nl;

	if (fd == -1 || BUFFER_SIZE < 0)
		return (NULL);
	if (!leftover)
		leftover = ft_strdup("");
	while (find_newline(leftover) == -1)
	{
		if (read(fd, buf, BUFFER_SIZE) > 0)
			leftover = ft_strjoin(leftover, buf);
		else
			break ;
	}
	nl = find_newline(leftover);
	// printf("new line found at :%ld\n", nl);
	line = ft_substr(leftover, 0, nl + 1);
	ft_memmove(leftover, leftover + nl + 1, ft_strlen(leftover) - nl);
	if (nl == -1)
		return (NULL);
	return (line);
}
