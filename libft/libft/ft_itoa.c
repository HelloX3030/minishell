/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseeger <lseeger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:45:08 by hello_x           #+#    #+#             */
/*   Updated: 2024/10/14 17:41:40 by lseeger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(int n)
{
	int	len;

	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	const int	int_len = get_int_len(n);
	char		*str;
	int			i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (int_len + 1));
	if (str == NULL)
		return (NULL);
	i = int_len;
	if (n < 0)
	{
		n *= (-1);
		str[0] = '-';
	}
	else if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--i] = '0' + (n % 10);
		n /= 10;
	}
	str[int_len] = 0;
	return (str);
}

// int main(void)
// {
// 	const int	n = -3561;
// 	char		*numb;

// 	numb = ft_itoa(n);
// 	if (numb == NULL)
// 		return (1);
// 	printf("%s\n", numb);
// 	free(numb);
// 	return (0);
// }
