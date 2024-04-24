/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:48:58 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/08 18:55:51 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*temp;
	size_t			i;

	if (!dest && !src)
		return (0);
	ptr_d = (unsigned char *)dest;
	temp = (unsigned char *)src;
	i = 0;
	if (temp > ptr_d)
	{
		while (i < n)
		{
			ptr_d[i] = temp[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			ptr_d[i] = temp[i];
	}
	return (dest);
}
