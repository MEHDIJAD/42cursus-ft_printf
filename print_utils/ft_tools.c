/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:46 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/01 17:28:14 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countlen_number(long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	ft_put_precision_padding(int effective_len, t_list flag)
{
	if (flag.precision > effective_len)
		return (ft_putnchar('0', flag.precision - effective_len));
	return (0);
}

int	ft_putsign(int nbr, t_list flag)
{
	if (flag.plus_flag && nbr >= 0)
		return (ft_putchar('+'));
	if (nbr < 0)
		return (ft_putchar('-'));
	if (flag.space_flag && nbr >= 0)
		return (ft_putchar(' '));
	return (0);
}

int	ft_countlen_adress(unsigned long number, int base)
{
	int	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		len++;
		number /= base;
	}
	return (len);
}

int	ft_put_width_padding(int len, t_list flag)
{
	int	count;

	count = 0;
	if (flag.precision > 0)
	{
		count += ft_putnchar(' ', flag.width - len);
	}
	else if ((flag.precision == -1) && flag.zero_flag)
	{
		count += ft_putnchar('0', flag.width - len);
	}
	else
	{
		count += ft_putnchar(' ', flag.width - len);
	}
	return (count);
}
