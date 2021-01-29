/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:43:13 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 14:14:10 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_minus_char(t_struct *new, char c)
{
	int i;

	i = 1;
	write(1, &c, 1);
	while (i < new->width)
	{
		write(1, " ", 1);
		new->count++;
		i++;
	}
	new->count++;
}

static void		ft_zero_char(t_struct *new, char c)
{
	int i;

	i = 1;
	while (i < new->width)
	{
		write(1, "0", 1);
		new->count++;
		i++;
	}
	write(1, &c, 1);
	new->count++;
}

static void		ft_put_char(t_struct *new, char c)
{
	int i;

	i = 1;
	while (i < new->width)
	{
		write(1, " ", 1);
		new->count++;
		i++;
	}
	write(1, &c, 1);
	new->count++;
}

void			ft_print_char(const char *format, t_struct *new)
{
	char c;

	if (*(format + new->i) == '%')
		c = '%';
	else
		c = va_arg(new->ap, int);
	if (new->zero && !new->minus)
		ft_zero_char(new, c);
	else if (new->minus && !new->zero)
		ft_minus_char(new, c);
	else
		ft_put_char(new, c);
}
