/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almudenalopezrodriguez <almudenalopezro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 19:40:52 by almlopez          #+#    #+#             */
/*   Updated: 2025/02/14 17:51:39 by almudenalop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	char	c;
	int		i;

	i = 0;
	while (*s != '\0')
	{
		c = *s;
		write(fd, &c, 1);
		i++;
		s++;
	}
	return (i);
}
