/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:48:54 by esobchak          #+#    #+#             */
/*   Updated: 2021/01/04 13:43:54 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putaccuracy(const char *str, t_struct *new)
{
	int i;

	i = 0;
	while (i < new->accuracy - ft_strlen(str))
	{
		write(1, "0", 1);
		new->count++;
		i++;
	}
}

void		ft_putstr(const char *str, t_struct *new)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		write(1, &(*(str + i)), 1);
		new->count++;
		i++;
	}
}

int			ft_length(unsigned int num)
{
	int length;

	length = 0;
	while (num >= 10)
	{
		num /= 10;
		length++;
	}
	return (length + 1);
}

static char	*ft_str_itoa(int length, long long int nbr, char *s)
{
	int	i;

	i = length - 1;
	while (nbr)
	{
		*(s + i) = nbr % 10 + 48;
		i--;
		nbr /= 10;
	}
	*(s + length) = '\0';
	return (s);
}

char		*ft_itoa2(long long int n, t_struct *new)
{
	char			*s;
	int				length;
	long long int	nbr;

	nbr = n;
	nbr = n < 0 ? -nbr : nbr;
	length = ft_length(nbr);
	if (!(s = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	if (n == 0 && (new->accuracy == 0))
	{
		*(s + 0) = '\0';
		return (s);
	}
	if (n < 0)
	{
		new->sign = 1;
		n = -n;
	}
	s = ft_str_itoa(length, nbr, s);
	if ((ft_strlen(s) == 0 && new->format_type) || (n == 0 && new->accuracy))
		*(s + 0) = '0';
	return (s);
}
