/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 09:46:17 by aquincho          #+#    #+#             */
/*   Updated: 2022/05/13 09:46:26 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_conv
{
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		dot;
	int		prec;
	int		width;
	int		len_print;
}	t_conv;

int		ft_printf(const char *format, ...);
/* Fonctions de recherche des flags et convertisseur */
int		ft_process_conv(t_conv *conv, va_list args, char *format, int i);
int		ft_process_flags(t_conv *conv, char *format, int i);
/* Fonctions d'impression des arguments */
int		ft_printchar(t_conv *conv, int c);
int		ft_printstr(t_conv *conv, char *s);
int		ft_printnbr(t_conv *conv, int n);
int		ft_printunbr(t_conv *conv, unsigned int un);
int		ft_printxnbr(t_conv *conv, int n, char x);
int		ft_printptr(t_conv *conv, unsigned long int p);
/* Fonctions utilitaires */
void	ft_printblank(char c, int size);
int		ft_max(int a, int b);
int		ft_nbrlen(unsigned int n, unsigned int base);

#endif
