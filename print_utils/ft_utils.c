/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:52 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/01 17:32:32 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	ft_init(t_list flags)
{
	flags.plus_flag = false;
	flags.minus_flag = false;
	flags.space_flag = false;
	flags.hash_flag = false;
	flags.zero_flag = false;
	flags.width = 0;
	flags.precision = -1;
	return (flags);
}

int	ft_putnchar(char c, int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		count += write(1, &c, 1);
		n--;
	}
	return (count);
}

int	ft_count_width(const char *format, int i)
{
	int	width;

	width = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		width = (width * 10) + (format[i] - '0');
		i++;
	}
	return (width);
}

int	ft_count_precision(const char *format, int i)
{
	int	precision;
	int	j;

	precision = -1;
	j = i;
	while (format[j])
	{
		if (format[j] == 's' && format[j + 1] == '.')
			return (precision);
		j++;
	}
	while (format[i] && format[i] != '.')
		i++;
	if (format[i] == '.')
	{
		precision = 0;
		i++;
		while (format[i] >= '0' && format[i] <= '9')
		{
			precision = (precision * 10) + (format[i] - '0');
			i++;
		}
	}
	return (precision);
}

int	ft_putdigit(long number, int base, char *base_symbols)
{
	unsigned long	n;
	int				count;

	count = 0;
	if (number < 0 && base == 10)
	{
		n = -number;
	}
	else
	{
		n = (unsigned long)number;
	}
	if (n >= (unsigned long)base)
	{
		count += ft_putdigit((n / base), base, base_symbols);
	}
	count += ft_putchar(base_symbols[n % base]);
	return (count);
}
