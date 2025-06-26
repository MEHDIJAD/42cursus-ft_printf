/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:04 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/01 17:41:12 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_special_case(t_list flag, int total_len)
{
	return (ft_putnchar(' ', flag.width - total_len + 1));
}

static int	ft_put_width_padding_for_digit(int total_len, t_list flag, int nbr)
{
	int	count;

	count = 0;
	if (flag.zero_flag && flag.precision == -1)
	{
		count += ft_putsign(nbr, flag);
		count += ft_putnchar('0', flag.width - total_len);
		return (count);
	}
	else
	{
		count += ft_putnchar(' ', flag.width - total_len);
	}
	count += ft_putsign(nbr, flag);
	return (count);
}

int	ft_printdigit(int nbr, t_list flag)
{
	int	count;
	int	len_arg;
	int	effective_len;
	int	total_len;

	count = 0;
	len_arg = ft_countlen_number(nbr);
	effective_len = len_arg;
	if (flag.precision > len_arg)
		effective_len = flag.precision;
	if (nbr < 0 || flag.plus_flag || flag.space_flag)
		effective_len += 1;
	total_len = effective_len;
	if (flag.precision == 0 && nbr == 0)
		return (ft_special_case(flag, total_len));
	if (!flag.minus_flag && flag.width)
		count += ft_put_width_padding_for_digit(total_len, flag, nbr);
	if (!flag.width || flag.minus_flag)
		count += ft_putsign(nbr, flag);
	count += ft_put_precision_padding(len_arg, flag);
	count += ft_putdigit(nbr, 10, "0123456789");
	if (flag.minus_flag)
		count += ft_putnchar(' ', flag.width - total_len);
	return (count);
}
