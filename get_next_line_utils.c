/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlminga <chlminga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:21:15 by chlminga          #+#    #+#             */
/*   Updated: 2026/06/19 13:47:28 by chlminga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// ft_strlen : rend la longeur de ma string.
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
// ft_strjoin : rend une nouvelle string qui
// contient deux chaines mis l'une apres l'autre.

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	unsigned int	i;
	unsigned int	j;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}
// ft_substr :
// Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;
	size_t		size;

	size = ft_strlen(s);
	if (start >= size)
		len = 0;
	else if (len > size - start)
		len = size - start;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
// ft_strdup :
// La fonction strdup() renvoie un pointeur sur
// une nouvelle chaîne de caractères qui est dupliquée depuis s.
// La mémoire occupée par cette nouvelle chaîne est obtenue en
// appelant malloc(3), et peut (doit) donc être libérée avec free(3).

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*copy;

	len = 0;
	while (s1[len])
		len++;
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// ft_check_end_line : verifie s'il y a un "\n" dans ma string.
int	ft_check_end_line(char *buffer)
{
	int	i;

	if (buffer == NULL)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == "\n")
			return (1);
		i++;
	}
	return (-1);
}
//char	*ft_copy_to_end_line(char *stock)
//char	*ft_next_line(char *stock)

char	*ft_read_fd(int fd, char *stock)
{
	char	*buffer;
	int		count;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_check_end_line(buff))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == 0)
			break ;
		buffer[count] = '\0';
	}
//	printf("%s\n", buffer);
	return (NULL);
}
// get_next_line : 
char	*get_next_line(int fd)
{
	int			i;
	char		*allread;
	stati char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	i = 0;
	while (stock[i] != '\n')
	{
		allread = ft_read_fd(fd, buffer);
		stock = buffer;
		i++;
	}
	return (allread);
}

int	main(void)
{
	int			fd;
	static char	*line = NULL;

	fd = open("file.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}