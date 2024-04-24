/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:29:49 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/18 17:37:44 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *ipstring, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int i);
int	ft_putptr(void *ptr);
int	ft_putuni(unsigned int i);
int	ft_puthexax(unsigned int i);
int	ft_puthexaxl(unsigned int i);

#endif