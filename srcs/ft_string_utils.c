/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:59:00 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 15:43:51 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

void	ft_minus_str(t_struct *new, const char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		write(1, &(*(str + i)), 1);
		new->count++;
		i++;
	}
	i = 0;
	if (new->width > ft_strlen(str))
	{
		while (i < new->width - ft_strlen(str))
		{
			write(1, " ", 1);
			new->count++;
			i++;
		}
	}
}

void	ft_zero_str(t_struct *new, const char *str)
{
	int i;

	i = 0;
	if (new->width > ft_strlen(str))
	{
		while (i < new->width - ft_strlen(str))
		{
			write(1, "0", 1);
			new->count++;
			i++;
		}
	}
	i = 0;
	while (*(str + i))
	{
		write(1, &(*(str + i)), 1);
		new->count++;
		i++;
	}
}

void	ft_sp_str(t_struct *new, const char *str)
{
	int i;

	i = 0;
	if (new->width > ft_strlen(str))
	{
		while (i < new->width - ft_strlen(str))
		{
			write(1, " ", 1);
			new->count++;
			i++;
		}
	}
	i = 0;
	while (*(str + i))
	{
		write(1, &(*(str + i)), 1);
		new->count++;
		i++;
	}
}

void	ft_accur_str(t_struct *new, const char *str)
{
	int i;
	int len;

	len = (new->accuracy < ft_strlen(str) ? new->accuracy : ft_strlen(str));
	if (new->width >= len)
	{
		i = 0;
		while (i < (new->width - len))
		{
			write(1, " ", 1);
			new->count++;
			i++;
		}
	}
	i = 0;
	while (*(str + i) && i < new->accuracy)
	{
		write(1, &(*(str + i)), 1);
		new->count++;
		i++;
	}
}
