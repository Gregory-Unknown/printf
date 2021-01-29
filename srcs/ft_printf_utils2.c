/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 13:18:58 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 15:35:21 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_zero(t_struct *new)
{
	new->zero = 1;
	new->i++;
}

void	ft_check_minus(t_struct *new)
{
	new->minus = 1;
	new->i++;
}

void	ft_check_dot(t_struct *new)
{
	new->dot = 1;
	new->accuracy = 0;
	new->i++;
}
