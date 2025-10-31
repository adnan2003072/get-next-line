/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouzkra <adnanbouzkraouoi037@gmail.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:10:24 by abouzkra          #+#    #+#             */
/*   Updated: 2025/10/31 13:53:48 by abouzkra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	fd = open("Makefile", O_RDONLY);
	if (fd == -1)
	{
		printf("File could not be opened !\n");
		return (-1);
	}
	i = 0;
	while ((line = get_next_line(fd)))
	{
		printf("%d: %s", i, line);
		line = get_next_line(fd);
		free(line);
		i++;
	}
	return (0);
}
