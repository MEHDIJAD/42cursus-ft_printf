/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:57:55 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/01 17:11:44 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c, t_list flag)
{
	int	count;

	count = 0;
	if (flag.width > 1 && !flag.minus_flag && flag.zero_flag)
		count += ft_putnchar('0', flag.width - 1);
	if (flag.width > 1 && !flag.minus_flag && !flag.zero_flag)
		count += ft_putnchar(' ', flag.width - 1);
	count += write(1, &c, 1);
	if (flag.width > 1 && flag.minus_flag)
		count += ft_putnchar(' ', flag.width - 1);
	return (count);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
