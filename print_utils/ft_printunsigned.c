/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:37 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/01 17:23:17 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_special_case(t_list flag, int total_len)
{
	return (ft_putnchar(' ', flag.width - total_len + 1));
}

int	ft_printunsigned(unsigned int n, t_list flag)
{
	int	count;
	int	len_arg;
	int	effective_len;
	int	total_len;
	int	ps;

	count = 0;
	ps = 0;
	len_arg = ft_countlen_number(n);
	effective_len = len_arg;
	if (flag.precision > len_arg)
		effective_len = flag.precision;
	total_len = effective_len;
	if (flag.precision == 0 && n == 0)
		return (ft_special_case(flag, total_len));
	if (!flag.minus_flag)
		count += ft_put_width_padding(total_len, flag);
	if (flag.space_flag)
		count += ft_putchar(' ');
	count += ft_put_precision_padding(len_arg, flag);
	count += ft_putdigit(n, 10, "0123456789");
	if (flag.minus_flag)
		count += ft_put_width_padding(total_len, flag);
	return (count);
}
