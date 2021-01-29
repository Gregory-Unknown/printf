/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:56:54 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 14:59:13 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_accuracy_exist(t_struct *new, const char *str)
{
	int len;

	len = ft_strlen(str);
	if (new->minus)
	{
		write(1, "0x", 2);
		new->count += 2;
		if (len < new->accuracy)
			ft_putaccuracy(str, new);
		ft_putstr(str, new);
		if (len < new->width)
			ft_putwidth(str, new);
	}
	else
	{
		if (len < new->width)
			ft_putwidth(str, new);
		write(1, "0x", 2);
		new->count += 2;
		if (len < new->accuracy)
			ft_putaccuracy(str, new);
		ft_putstr(str, new);
	}
}

static void	ft_accuracy_none(t_struct *new, const char *str)
{
	if (new->minus)
	{
		write(1, "0x", 2);
		new->count += 2;
		ft_putstr(str, new);
		if (ft_strlen(str) < new->width)
			ft_putwidth(str, new);
	}
	else if (new->zero)
	{
		write(1, "0x", 2);
		new->count += 2;
		if (ft_strlen(str) < new->width)
			ft_putwidth2(str, new);
		ft_putstr(str, new);
	}
	else
	{
		if (ft_strlen(str) < new->width)
			ft_putwidth(str, new);
		write(1, "0x", 2);
		new->count += 2;
		ft_putstr(str, new);
	}
}

void		ft_print_pointer(t_struct *new)
{
	char *str;

	new->hex_type = 'a';
	str = ft_itoa_base(va_arg(new->ap, unsigned long), new);
	if (new->width >= 2)
		new->width -= 2;
	if (new->accuracy > 0)
		ft_accuracy_exist(new, str);
	else
		ft_accuracy_none(new, str);
	free(str);
}
