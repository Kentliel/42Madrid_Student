/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrero <kcarrero@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:59:47 by kcarrero          #+#    #+#             */
/*   Updated: 2025/05/05 18:32:36 by kcarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	return (ft_isalpha(n) || ft_isdigit(n));
}
/*
#include <stdio.h>
int	main(void)
{
	printf("ft_isalnum ('A') = %d\n", ft_isalnum('A'));
	printf("ft_isalnum (3) = %d\n", ft_isalnum(3));
	printf("ft_isalnum ('$') = %d\n", ft_isalnum('$'));
	return (0);
}*/
