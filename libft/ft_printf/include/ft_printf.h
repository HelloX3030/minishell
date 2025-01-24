/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:42:09 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/12 14:49:41 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *s, ...);
int	print_l(const char *s, int l);
int	ft_print_c(va_list args);
int	ft_print_s(va_list args);
int	ft_print_p(va_list args);
int	ft_print_i(va_list args);
int	ft_print_u(va_list args);
int	ft_print_x(va_list args);
int	ft_print_xx(va_list args);
int	ft_print_per(void);

#endif
