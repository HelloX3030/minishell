/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atocolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:25:46 by lseeger           #+#    #+#             */
/*   Updated: 2024/11/28 13:21:23 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	parse_c(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (c - 'A' + 10);
}

static bool	is_hex(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A'
			&& c <= 'F'));
}

uint32_t	ft_atocolor(const char *str)
{
	int			i;
	uint32_t	num;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (ft_strlen(str) >= 2 && *str == '0' && (*(str + 1) == 'x' || *(str
				+ 1) == 'X'))
		str += 2;
	num = 0;
	i = -1;
	while (++i < 8 && is_hex(str[i]))
	{
		num <<= 4;
		num += parse_c(str[i]);
	}
	num <<= (8 - i) * 4;
	if (i <= 6)
		num |= 0xFF;
	return (num);
}

// void	test_ft_atocolor(const char *input, uint32_t expected)
// {
// 	uint32_t	result;

// 	result = ft_atocolor(input);
// 	printf("Input: '%s' | Result: %#010x | Expected: %#010x | %s\n", input,
// 		result, expected, (result == expected) ? "PASS" : "FAIL");
// }

// int	main(void)
// {
// 	test_ft_atocolor("0x00FF00FF", 0x00FF00FF);
// 	test_ft_atocolor("0xff", 0xFF0000FF);
// 	test_ft_atocolor("0X12345678", 0x12345678);
// 	test_ft_atocolor("12345678", 0x12345678);
// 	test_ft_atocolor("  0xABCDEF  ", 0xABCDEFFF);
// 	test_ft_atocolor("  0x", 0x000000FF);
// 	test_ft_atocolor("0xGHIJKL", 0x000000FF);
// 	test_ft_atocolor("0x123ZZZ", 0x123000FF);
// 	test_ft_atocolor("", 0x000000FF);
// 	test_ft_atocolor("FFFFFFFF", 0xFFFFFFFF);
// 	test_ft_atocolor("00000000", 0x00000000);
// 	return (0);
// }
