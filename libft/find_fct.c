/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_fct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:58:05 by gjuste            #+#    #+#             */
/*   Updated: 2019/05/27 09:23:49 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	find_fct(t_ptf *stt, va_list ap)
{
	if (stt->c == 'c' || stt->c == 's' || stt->c == 'p' || stt->c == '%')
		find_alph(stt, ap);
	if (stt->c == 'd' || stt->c == 'i' || stt->c == 'o' || stt->c == 'u'
		|| stt->c == 'b')
		find_num1(stt, ap);
	if (stt->c == 'x' || stt->c == 'X' || stt->c == 'f')
		find_num2(stt, ap);
}
