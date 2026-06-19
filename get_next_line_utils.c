/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlminga <chlminga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:21:15 by chlminga          #+#    #+#             */
/*   Updated: 2026/06/19 23:15:08 by chlminga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

size_t	count_to_endline(char *string)
{
	int	i;

	i = 0;
	while (string[i] && string[i] != '\n')
		i++;
	if (string[i] == '\n')
		return (i + 1);
	else
		return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (i != ft_strlen(s1))
		s3[i++] = s1[i++];
	j = 0;
	while (i != ft_strlen(s2))
		s3[i++] = s2[j++];
	s3[i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (s3);
}

int	ft_check_new_line(char *buffer)
{
	int	i;

	if (buffer == NULL)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_read_fd(int fd, char *stock)
{
	char	*buffer;
	int		count;

	write (1, "a", 1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	write (1, "b", 1);
	while (1)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		write (1, "c", 1);
		if (count <= 0)
			break ;
		write (1, "d", 1);
		buffer[count] = '\0';
		write (1, "e", 1);
		stock = ft_strjoin(stock, buffer);
		write (1, "f\n", 2);
		if (ft_check_new_line(buffer) != -1)
			break ;
		write (1, "g", 1);
	}
	free(buffer);
	return (stock);
}

char	*ft_copy_to_end_line(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * count_to_endline(stock) + 1);
	while (stock[i] != '\n' && stock[i])
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\n';
	i++;
	line[i] = '\0';
	return (line);
}

//char	*ft_clean_line(char *stock)

void	next_line(char *stock)
{
	int	i;
	int	va;

	i = 0;
	va = ft_check_new_line(stock) + 1;
	while (stock[va])
		stock[i++] = stock[va++];
	stock[i] = '\0';
}

char	*get_next_line(int fd)
{
	//char		*allread;
	char		*line;
	static char	*stock = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	stock = ft_read_fd(fd, stock);
	printf("stock------%s------stock\n", stock);
	line = ft_copy_to_end_line(stock);
	printf("line------%s------line\n", line);
	next_line(stock);
	printf("next------%s------next\n", stock);
	return (line);
}

int	main(void)
{
	int			fd;
	static char	*line = NULL;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	// while (1)
	// {
	// 	line = get_next_line(fd);
	// 	if (line == NULL)
	// 		break ;
	// 	printf("%s", line);
	// 	free(line);
	// }
	close(fd);
	return (0);
}