/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlminga <chlminga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:21:32 by chlminga          #+#    #+#             */
/*   Updated: 2026/06/20 22:04:00 by chlminga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_new_line(char *buffer);
char	*ft_read_fd(int fd, char *stock);
int	count_to_endline(char *string);
char	*ft_copy_to_end_line(char *stock);
void	next_line(char *stock);
char	*get_next_line(int fd);

#endif
