/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 14:15:57 by esobchak          #+#    #+#             */
/*   Updated: 2020/12/29 15:55:45 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_len_base(unsigned long n)
{
	size_t	count;

	count = 0;
	while (n >= 16)
	{
		n /= 16;
		count++;
	}
	return (count + 1);
}

static char	*ft_str_res(unsigned long nbr, int length, t_struct *new, char *str)
{
	int i;
	int res;

	i = length - 1;
	while (nbr)
	{
		res = nbr % 16;
		*(str + i--) = (res > 9) ? (res - 10) + new->hex_type : res + '0';
		nbr /= 16;
	}
	*(str + length) = '\0';
	return (str);
}

char		*ft_itoa_base(unsigned long nbr, t_struct *new)
{
	char	*str;
	int		length;

	length = ft_len_base(nbr);
	if (!(str = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	if (nbr == 0 && (new->accuracy == 0))
	{
		*(str + 0) = '\0';
		return (str);
	}
	if (nbr == 0)
	{
		if (new->accuracy)
			*(str + 0) = '0';
		*(str + 1) = '\0';
		return (str);
	}
	str = ft_str_res(nbr, length, new, str);
	return (str);
}
