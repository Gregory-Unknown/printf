/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:15:24 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 15:27:06 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_init(t_struct *new)
{
	new->flag = 0;
	new->zero = 0;
	new->minus = 0;
	new->dot = 0;
	new->width = 0;
	new->accuracy = -1;
	new->format_type = 0;
	new->type = "cspdiuxX%";
	new->sign = 0;
	new->hex_type = 0;
}

static void	ft_parse_flag(const char *format, t_struct *new)
{
	new->i++;
	while (*(format + new->i) &&
			ft_strchr(*(format + new->i), new->type) == 0)
	{
		if (*(format + new->i) == '0' && *(format + (new->i - 1)) == '%')
			ft_check_zero(new);
		else if (*(format + new->i) == '-' && (*(format + (new->i - 1)) == '%'
					|| *(format + (new->i - 1)) == '.'
					|| *(format + (new->i - 1)) == '0'))
			ft_check_minus(new);
		else if (new->dot == 0 && (*(format + new->i) == '*'
					|| ft_isdigit(*(format + new->i))))
			ft_width(format, new);
		else if (*(format + new->i) == '.')
			ft_check_dot(new);
		else if (new->dot && (*(format + new->i) == '*'
					|| ft_isdigit(*(format + new->i))))
			ft_accuracy(format, new);
		else
			new->i++;
	}
}

static void	ft_print_type(const char *format, t_struct *new)
{
	if ((*(format + new->i) == 'c') || (*(format + new->i) == '%'))
		ft_print_char(format, new);
	else if (*(format + new->i) == 's')
		ft_print_string(new);
	else if ((*(format + new->i) == 'i') || (*(format + new->i) == 'd')
			|| (*(format + new->i) == 'u'))
		ft_print_int(format, new);
	else if ((*(format + new->i) == 'x') || (*(format + new->i) == 'X'))
		ft_print_hex(format, new);
	else if (*(format + new->i) == 'p')
		ft_print_pointer(new);
}

static void	ft_parse_format(const char *format, t_struct *new)
{
	while (*(format + new->i))
	{
		if (*(format + new->i) == '%' && new->flag == 0)
		{
			new->flag = 1;
			ft_parse_flag(format, new);
		}
		else if (new->flag == 1 && ft_strchr(*(format + new->i), new->type))
		{
			ft_print_type(format, new);
			new->flag = 0;
			ft_init(new);
			new->i++;
		}
		else
		{
			write(1, &(*(format + new->i)), 1);
			new->count++;
			ft_init(new);
			new->i++;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	t_struct	*new;
	size_t		count;

	if (!format || !(new = (t_struct *)malloc(sizeof(t_struct))))
		return (-1);
	va_start(new->ap, format);
	count = 0;
	new->i = 0;
	new->count = 0;
	ft_init(new);
	ft_parse_format(format, new);
	count = new->count;
	va_end(new->ap);
	free(new);
	return (count);
}
