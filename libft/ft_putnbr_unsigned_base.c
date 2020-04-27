/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_base.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:44:16 by jpelleti          #+#    #+#             */
/*   Updated: 2019/05/17 09:55:48 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_putnbr_unsigned_base(unsigned long long int n,
		unsigned int base, int opt)
{
	char c;

	c = (opt == 0 ? 'a' : 'A');
	if (n >= base)
	{
		ft_putnbr_unsigned_base(n / base, base, opt);
		ft_putchar(n % base <= 9 ? n % base + '0' : n % base + c - 10);
	}
	if (n < base)
		ft_putchar(n % base <= 9 ? n % base + '0' : n % base + c - 10);
}
