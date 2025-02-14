/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almudenalopezrodriguez <almudenalopezro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:29:26 by almudenalop       #+#    #+#             */
/*   Updated: 2025/02/14 18:21:51 by almudenalop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	int		i;
	int		j;
	char	src[11];

	i = 0;
	j = 0;
	if (n == 0)
		write(fd, "0", 1);
		return (1);
	while (n > 0)
	{
		src[i++] = (n % 10) + '0';
		n = n / 10;
		j++;
	}
	while (--i >= 0)
		write(fd, &src[i], 1);
	return (j);
}
