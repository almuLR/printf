/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almlopez <almlopez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:51:02 by almlopez          #+#    #+#             */
/*   Updated: 2025/02/05 16:57:13 by almlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
# define H_LOW "0123456789abcdef"
# define H_UP "0123456789ABCDEF"

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
		else if (str[i + 1] == '%')
			return (ft_putchar_fd('%', 1));
		else if (str[i + 1] == 'x')
			return (ft_putnbr_base(va_arg(args, int), H_LOW));
		else if (str[i + 1] == 'X')
			return (ft_putnbr_base(va_arg(args, int), H_UP));
		else if (str[i + 1] == 'd')
			return (ft_putnbr_fd(va_arg(args, int), 1));
		else if (str[i + 1] == 'u')
			return (ft_putnbr_unsigned(va_arg(args, unsigned int), 1));
		/*else if (str[i + 1] == 'p')
			El puntero void * dado como argumento se imprime en formato hexadecimal*/
	}
	return (0);
}

int	ft_printf(char const *str, ...)
{
	int	i;
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