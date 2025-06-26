/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:31:55 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/01 18:36:41 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percentage(t_list flag)
{
	int	count;

	count = 0;
	if (!flag.minus_flag && flag.width > 1)
	{
		count += ft_putnchar(' ', flag.width - 1);
	}
	count += ft_putchar('%');
	if (flag.minus_flag && flag.width > 1)
	{
		count += ft_putnchar(' ', flag.width - 1);
	}
	return (count);
}
