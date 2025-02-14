/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almudenalopezrodriguez <almudenalopezro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:26:34 by almlopez          #+#    #+#             */
/*   Updated: 2025/02/14 17:49:34 by almudenalop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	char	c;
	char	d;
	int		i;

	i = 0;
	while (*s != '\0')
	{
		c = *s;
		write(fd, &c, 1);
		i++;
		s++;
	}
	d = '\n';
	write(fd, &d, 1);
	return (i);
}
