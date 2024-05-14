/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:34:17 by jwozniak          #+#    #+#             */
/*   Updated: 2024/03/05 20:34:18 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_print_x(unsigned int num, const char format);
int	ft_print_id(int n);
int	ft_print_p(void *ptr);
int	ft_print_s(char *str);
int	ft_print_u(unsigned int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif
