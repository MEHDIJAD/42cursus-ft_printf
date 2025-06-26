/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-garo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:53:36 by eel-garo          #+#    #+#             */
/*   Updated: 2025/01/01 16:07:23 by eel-garo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
	bool	plus_flag;
	bool	minus_flag;
	bool	space_flag;
	bool	hash_flag;
	bool	zero_flag;
	int		width;
	int		precision;
}	t_list;

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_printchar(char c, t_list flag);
int		ft_printstr(char *str, t_list flag);
int		ft_printdigit(int nbr, t_list flag);
int		ft_printaddress(unsigned long ptr, t_list flag);
int		ft_printunsigned(unsigned int n, t_list flag);
int		ft_printhex(unsigned int n, t_list flag, char format_specifier);
int		ft_print_percentage(t_list flag);
int		ft_putnchar(char c, int n);
t_list	ft_init(t_list flags);
int		ft_count_width(const char *format, int i);
int		ft_count_precision(const char *format, int i);
int		ft_putdigit(long number, int base, char *base_symbols);
int		ft_countlen_number(long nbr);
int		ft_put_precision_padding(int effective_len, t_list flag);
int		ft_putsign(int nbr, t_list flag);
int		ft_countlen_adress(unsigned long number, int base);
int		ft_put_width_padding(int len, t_list flag);

#endif
