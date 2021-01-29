/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:58:30 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 15:32:47 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strchr(int c, char *s)
{
	size_t i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int		ft_atoi(const char *str, t_struct *new)
{
	int res;

	res = 0;
	while (*(str + new->i) > 47 && *(str + new->i) < 58)
	{
		res = 10 * res + (*(str + new->i) - 48);
		new->i++;
	}
	return (res);
}

void	ft_width(const char *format, t_struct *new)
{
	if (*(format + new->i) == '*')
	{
		new->width = va_arg(new->ap, int);
		if (new->width < 0)
		{
			new->width = -new->width;
			new->minus = 1;
			new->zero = 0;
		}
		new->i++;
	}
	else
		new->width = ft_atoi(format, new);
}

void	ft_accuracy(const char *format, t_struct *new)
{
	size_t i;

	i = new->i - 1;
	if (*(format + new->i) == '*')
	{
		new->accuracy = va_arg(new->ap, int);
		new->i++;
	}
	else
		new->accuracy = ft_atoi(format, new);
	if (new->minus && *(format + i) == '-')
	{
		new->width = new->accuracy;
		new->accuracy = 0;
	}
}
