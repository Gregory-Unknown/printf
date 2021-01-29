/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:49:22 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 14:44:47 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putwidth(const char *str, t_struct *new)
{
	int i;
	int len;

	i = 0;
	len = ((ft_strlen(str) > new->accuracy) ? ft_strlen(str) : new->accuracy);
	new->width = (new->width > len) ? new->width : len;
	while (i < (new->width - len))
	{
		write(1, " ", 1);
		new->count++;
		i++;
	}
}

void	ft_putwidth2(const char *str, t_struct *new)
{
	size_t i;
	size_t len;

	i = 0;
	len = ((ft_strlen(str) > new->accuracy) ? ft_strlen(str) : new->accuracy);
	while (i < (new->width - len))
	{
		write(1, "0", 1);
		new->count++;
		i++;
	}
}

void	ft_putsign(t_struct *new)
{
	write(1, "-", 1);
	new->count++;
	new->width--;
}
