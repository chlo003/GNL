/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlminga <chlminga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:20:18 by chlminga          #+#    #+#             */
/*   Updated: 2026/06/18 14:40:18 by chlminga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			i;

	i = 0;
	while (stock[i] != '\n')
	{
		ft_read(fd, buffer, i);
		stock = buffer;
		i++;
	}
}
