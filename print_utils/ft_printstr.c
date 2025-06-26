/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:26 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/01 17:17:45 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, t_list flag)
{
	int	count;
	int	len;

	if (!str)
		str = "(null)";
	count = 0;
	len = 0;
	while (str[len])
		len++;
	if (flag.precision < len && flag.precision != -1)
		len = flag.precision;
	if (flag.width > len && !flag.minus_flag && flag.zero_flag)
		count += ft_putnchar('0', flag.width - len);
	else if (flag.width > len && !flag.minus_flag && !flag.zero_flag)
		count += ft_putnchar(' ', flag.width - len);
	count += write(1, str, len);
	if (flag.width > len && flag.minus_flag)
		count += ft_putnchar(' ', flag.width - len);
	return (count);
}
