/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:03:41 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 15:06:00 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_minus_string(t_struct *new, const char *str)
{
	int i;
	int len;

	i = 0;
	len = (new->accuracy < ft_strlen(str) ? new->accuracy : ft_strlen(str));
	while (*(str + i) && (i < len))
	{
		write(1, &(*(str + i)), 1);
		new->count++;
		i++;
	}
	if ((new->width) && (i >= new->width))
		new->width = i;
	i = 0;
	if (new->width >= len)
	{
		while (i < (new->width - len))
		{
			write(1, " ", 1);
			new->count++;
			i++;
		}
	}
}

static void	ft_zero_string(t_struct *new, const char *str)
{
	int i;

	i = 0;
	if (new->accuracy < new->width)
	{
		while (i < (new->width - new->accuracy))
		{
			write(1, "0", 1);
			new->count++;
			i++;
		}
		i = 0;
	}
	while (i < new->accuracy && *(str + i))
	{
		write(1, &(*(str + i)), 1);
		new->count++;
		i++;
	}
}

static void	ft_accuracy_exist(t_struct *new, const char *str)
{
	if (new->minus)
		ft_minus_string(new, str);
	else if (new->zero)
		ft_zero_string(new, str);
	else
		ft_accur_str(new, str);
}

static void	ft_accuracy_none(t_struct *new, const char *str)
{
	if (new->minus)
		ft_minus_str(new, str);
	else if (new->zero)
		ft_zero_str(new, str);
	else
		ft_sp_str(new, str);
}

void		ft_print_string(t_struct *new)
{
	const char	*str;
	int			i;

	i = 0;
	str = va_arg(new->ap, char *);
	if (str == NULL)
		str = "(null)";
	if (new->accuracy > 0)
		ft_accuracy_exist(new, str);
	else if (new->accuracy < 0)
		ft_accuracy_none(new, str);
	else
	{
		while (i < new->width)
		{
			if (new->zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			new->count++;
			i++;
		}
	}
}
