/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlminga <chlminga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:21:15 by chlminga          #+#    #+#             */
/*   Updated: 2026/06/18 15:45:13 by chlminga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

int	ft_check_end_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == "\n")
			return (0);
		i++;
	}
	return (-1);
}

char	*ft_copy_to_end_line(char *stock)
{
	
}

char	*ft_next(char *stock)
{
	
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
		if (count == 0)
			break ;
		buffer[count] = '\0';
	}
//	printf("%s\n", buffer);
	return (NULL);
}

int	main(void)
{
	int			fd;
	static char	*stock = NULL;

	fd = open("file.txt", O_RDONLY);
	ft_read_fd(fd, stock);
	close(fd);
	return (0);
}