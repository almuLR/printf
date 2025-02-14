/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almudenalopezrodriguez <almudenalopezro    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:29:26 by almudenalop       #+#    #+#             */
/*   Updated: 2025/02/14 18:30:07 by almudenalop      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	reverse(char *result, int size)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		aux = result[i];
		result[i] = result[j];
		result[j] = aux;
		i++;
		j--;
	}
}

static int	is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
		{
			return (0);
		}
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_putnbr_base_valid(char *base)
{
	int	size;

	size = 0;
	while (base[size] != '\0')
	{
		size++;
	}
	if (size < 2 || !is_base_valid(base))
	{
		return (0);
	}
	return (1);
}

static void	ft_convert_to_base(long naux, char *base, int size, char *result)
{
	int	n;

	n = 0;
	if (naux == 0)
	{
		result[n++] = base[0];
	}
	else
	{
		while (naux > 0)
		{
			result[n++] = base[naux % size];
			naux = naux / size;
		}
	}
	result[n] = '\0';
	reverse(result, n);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	int		n;
	long	naux;
	char	result[1000];

	size = 0;
	n = 0;
	while (base[size] != '\0')
	{
		size++;
	}
	if (!ft_putnbr_base_valid(base))
	{
		return ;
	}
	naux = nbr;
	if (naux < 0)
	{
		write(1, "-", 1);
		naux = -naux;
	}
	ft_convert_to_base(naux, base, size, result);
	while (result[n] != '\0')
		n++;
	write(1, result, n);
	return (n);
}
