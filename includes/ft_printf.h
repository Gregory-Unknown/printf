/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:16:58 by esobchak          #+#    #+#             */
/*   Updated: 2021/01/04 13:44:19 by esobchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_struct
{
	va_list		ap;
	size_t		i;
	size_t		flag;
	size_t		count;
	size_t		zero;
	size_t		minus;
	size_t		dot;
	size_t		sign;
	int			width;
	int			accuracy;
	char		*type;
	char		format_type;
	char		hex_type;
}				t_struct;

int				ft_printf(const char *format, ...);
void			ft_print_char(const char *format, t_struct *new);
void			ft_print_string(t_struct *new);
int				ft_strchr(int c, char *s);
int				ft_isdigit(int c);
int				ft_atoi(const char *str, t_struct *new);
void			ft_width(const char *format, t_struct *new);
void			ft_accuracy(const char *format, t_struct *new);
void			ft_minus_str(t_struct *new, const char *str);
void			ft_zero_str(t_struct *new, const char *str);
int				ft_strlen(const char *s);
void			ft_accur_str(t_struct *new, const char *str);
void			ft_sp_str(t_struct *new, const char *str);
void			ft_print_int(const char *format, t_struct *new);
void			ft_putstr(const char *str, t_struct *new);
void			ft_putwidth(const char *str, t_struct *new);
void			ft_putwidth2(const char *str, t_struct *new);
void			ft_putaccuracy(const char *str, t_struct *new);
char			*ft_itoa2(long long int n, t_struct *new);
int				ft_length(unsigned int num);
void			ft_putsign(t_struct *new);
void			ft_print_pointer(t_struct *new);
void			ft_check_zero(t_struct *new);
void			ft_check_minus(t_struct *new);
void			ft_check_dot(t_struct *new);
void			ft_print_hex(const char *format, t_struct *new);
char			*ft_itoa_base(unsigned long nbr, t_struct *new);
void			ft_minus_accuracy(t_struct *new, const char *str);

#endif
