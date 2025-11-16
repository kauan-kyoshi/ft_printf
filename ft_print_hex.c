/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoshi <kyoshi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:34:51 by kyoshi            #+#    #+#             */
/*   Updated: 2025/11/15 21:35:53 by kyoshi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_len(unsigned int n, const char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex_len(n / 16, base);
	len += ft_print_char(base[n % 16]);
	return (len);
}

int	ft_print_hex(unsigned int n, char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	if (format == 'x')
		return (ft_puthex_len(n, "0123456789abcdef"));
}
