/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlminga <chlminga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:21:15 by chlminga          #+#    #+#             */
/*   Updated: 2026/06/20 13:22:46 by chlminga         ###   ########.fr       */
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
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (i != ft_strlen(s2))
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
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
		if (ft_check_new_line(buffer) != -1)
			break ;
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
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
		write(1, "\n\n", 2);
	}
	close(fd);
	return (0);
}


// I'd like to add a simple explanation for both: Segmentation fault means 
// that you are trying to access memory that you are not allowed to 
// (e. g. it's not part of your program). However, on a bus error it 
// usually means that you are trying to access memory that does not exist 
// (e. g. you try to access an address at 12G but you only have 8G memory) 
// or if you exceed the limit of usable memory. 