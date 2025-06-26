/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:57:36 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/05 11:08:13 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_width_padding_for_adress(int effective_len, t_list flag)
{
	int	count;

	count = 0;
	if (flag.zero_flag && flag.precision == -1)
	{
		count += write(1, "0x", 2);
		count += ft_putnchar('0', flag.width - effective_len);
	}
	else
	{
		count += ft_putnchar(' ', flag.width - effective_len);
		count += write(1, "0x", 2);
	}
	return (count);
}

int	ft_printaddress(unsigned long ptr, t_list flag)
{
	int	count;
	int	len;
	int	effective_len;

	count = 0;
	len = ft_countlen_adress(ptr, 16);
	effective_len = len;
	if (flag.precision > len)
		effective_len = flag.precision;
	effective_len += 2;
	if (flag.width > len && !flag.minus_flag)
	{
		count += ft_put_width_padding_for_adress(effective_len, flag);
	}
	else
	{
		count += write(1, "0x", 2);
	}
	if (flag.precision > len)
		count += ft_putnchar('0', flag.precision - len);
	count += ft_putdigit(ptr, 16, "0123456789abcdef");
	if (flag.width > len && flag.minus_flag)
		count += ft_putnchar(' ', flag.width - effective_len);
	return (count);
}
