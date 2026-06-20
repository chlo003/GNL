/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlminga <chlminga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:20:18 by chlminga          #+#    #+#             */
/*   Updated: 2026/06/20 23:14:20 by chlminga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *stock)
{
	char	*buffer;
	int		count;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buffer[count] = '\0';
		stock = ft_strjoin(stock, buffer);
		if (ft_check_new_line(buffer) >= 0)
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (stock);
}

char	*ft_copy_to_end_line(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	if (!stock || !ft_strlen(stock))
		return (NULL);
	line = malloc(sizeof(char) * count_to_endline(stock) + 2);
	if (!line)
		return (NULL);
	while (stock[i] != '\n' && stock[i])
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	next_line(char *stock)
{
	int	i;
	int	following;

	i = 0;
	if (!stock)
		return ;
	following = ft_check_new_line(stock) + 1;
	if (following <= 0)
	{
		stock[0] = 0;
		return ;
	}
	while (stock[following])
		stock[i++] = stock[following++];
	stock[i] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_check_new_line(stock) < 0)
		stock = ft_read_fd(fd, stock);
	line = ft_copy_to_end_line(stock);
	next_line(stock);
	if (line == NULL)
	{
		free (stock);
		stock = NULL;
	}
	return (line);
}

// int	main(void)
// {
// 	int			fd;
// 	static char	*line = NULL;

// 	fd = open("file.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free (line);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	free(line);
// 	return (0);
// }
