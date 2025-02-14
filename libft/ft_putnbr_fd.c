/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almudenalopezrodriguez <almudenalopezro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:29:26 by almudenalop       #+#    #+#             */
/*   Updated: 2025/02/14 17:51:04 by almudenalop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		j;
	char	src[11];

	i = 0;
	j = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return(11);
	}
	if (n == 0)
		write(fd, "0", 1);
		return (1);
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		j++;
	}
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
