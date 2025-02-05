/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almlopez <almlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:51:02 by almlopez          #+#    #+#             */
/*   Updated: 2025/02/05 15:38:37 by almlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	what_letter(char *str, int i, va_list args)
{
	if (str[i] == '%')
	{
		if (str[i + 1] == 'c')
			return (ft_putchar_fd(va_arg(args, int), 1));
		else if (str[i + 1] == 's')
			return (ft_putstr_fd(va_arg(args, char *), 1));
		else if (str[i + 1] == 'i')
			return (ft_putnbr_fd(va_arg(args, int), 1));
		/*else if (str[i + 1] == 'p')
			printf_hexa();
		else if (str[i + 1] == 'd')
			printf_base_ten();
		else if (str[i + 1] == 'u')
			printf_base_ten_unsigned();
		else if (str[i + 1] == 'x')
			printf_base_sixteen_min();
		else if (str[i + 1] == 'X')
			printf_base_sixteen_may();
		else if (str[i + 1] == '%')
			printf_porcentaje();*/
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		return (what_letter((char *)str, i, args));
		i++;
	}
	va_end(args);
	return (0);
}
/*#include <stdio.h>
int main ()
{
	ft_printf("%c", 'a');
	ft_printf("%s", "holaholahola");
	ft_printf("%i", 12345);
	printf("%c", 'a');
	printf("%s", "holaholahola");
	printf("%i", 12345);
	return (0);
}*/