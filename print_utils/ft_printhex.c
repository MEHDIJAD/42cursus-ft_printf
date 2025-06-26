/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:16 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/04 11:28:27 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthash(t_list flag, char format_specifier)
{
	int	count;

	count = 0;
	if (flag.hash_flag && format_specifier == 'x')
		count += write(1, "0x", 2);
	else if (flag.hash_flag && format_specifier == 'X')
		count += write(1, "0X", 2);
	return (count);
}

static int	ft_smcheck(unsigned int n, t_list flag)
{
	int	len_with_zero;

	len_with_zero = 0;
	if (n == 0 && (flag.precision == 0 || !flag.precision))
		len_with_zero -= 1;
	return (len_with_zero);
}

int	ft_printhex(unsigned int n, t_list flag, char format_specifier)
{
	int	count;
	int	len_arg;
	int	total_len;
	int	effective_len;

	count = 0;
	len_arg = ft_countlen_adress(n, 16);
	effective_len = len_arg;
	if (flag.precision > len_arg)
		effective_len = flag.precision;
	if (flag.hash_flag && n != 0)
		effective_len += 2;
	total_len = effective_len + ft_smcheck(n, flag);
	if (!flag.minus_flag)
		count += ft_put_width_padding(total_len, flag);
	if (n != 0)
		count += ft_puthash(flag, format_specifier);
	count += ft_put_precision_padding(len_arg, flag);
	if (format_specifier == 'x' && (!(n == 0 && flag.precision == 0)))
		count += ft_putdigit(n, 16, "0123456789abcdef");
	else if (format_specifier == 'X' && (!(n == 0 && flag.precision == 0)))
		count += ft_putdigit(n, 16, "0123456789ABCDEF");
	if (flag.minus_flag)
		count += ft_put_width_padding(total_len, flag);
	return (count);
}
