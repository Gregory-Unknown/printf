/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:15:37 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 16:03:17 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_accuracy_exist(t_struct *new, const char *str)
{
	int len;

	len = ft_strlen(str);
	if (new->minus)
	{
		if (new->sign)
			ft_putsign(new);
		if (len < new->accuracy)
			ft_putaccuracy(str, new);
		ft_putstr(str, new);
		if (len < new->width)
			ft_putwidth(str, new);
	}
	else
	{
		(new->sign) ? new->width-- : new->width;
		if (len < new->width)
			ft_putwidth(str, new);
		(new->sign) ? new->width-- : new->width;
		if (new->sign)
			ft_putsign(new);
		if (len < new->accuracy)
			ft_putaccuracy(str, new);
		ft_putstr(str, new);
	}
}

void		ft_minus_accuracy(t_struct *new, const char *str)
{
	if (new->sign)
		ft_putsign(new);
	ft_putstr(str, new);
	if (ft_strlen(str) < new->width)
		ft_putwidth(str, new);
}

static void	ft_accuracy_none(t_struct *new, const char *str)
{
	if (new->minus)
		ft_minus_accuracy(new, str);
	else if (new->zero)
	{
		if (new->sign)
			ft_putsign(new);
		if (ft_strlen(str) < new->width)
			ft_putwidth2(str, new);
		else
			ft_putwidth(str, new);
		ft_putstr(str, new);
	}
	else
	{
		(new->sign) ? new->width-- : new->width;
		if (ft_strlen(str) < new->width)
			ft_putwidth(str, new);
		(new->sign) ? new->width++ : new->width;
		if (new->sign)
			ft_putsign(new);
		ft_putstr(str, new);
	}
}

static void	ft_accuracy_zero(t_struct *new, const char *str)
{
	if (new->minus)
		ft_minus_accuracy(new, str);
	else if (new->zero)
	{
		(new->sign) ? new->width-- : new->width;
		ft_putwidth(str, new);
		if (new->sign)
			ft_putsign(new);
		ft_putstr(str, new);
	}
	else
	{
		(new->sign) ? new->width-- : new->width;
		if (ft_strlen(str) < new->width)
			ft_putwidth(str, new);
		(new->sign) ? new->width++ : new->width;
		if (new->sign)
			ft_putsign(new);
		ft_putstr(str, new);
	}
}

void		ft_print_hex(const char *format, t_struct *new)
{
	char *str;

	new->hex_type = (*(format + new->i) == 'x') ? 'a' : 'A';
	str = ft_itoa_base(va_arg(new->ap, unsigned int), new);
	if (new->accuracy > 0)
		ft_accuracy_exist(new, str);
	else if (new->accuracy < 0)
		ft_accuracy_none(new, str);
	else
		ft_accuracy_zero(new, str);
	free(str);
}
