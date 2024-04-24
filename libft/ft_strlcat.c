/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:49:52 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/05 11:21:45 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	srcl;
	unsigned int	dstl;

	if (!src && !dst)
		return (0);
	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && (dstl + i + 1) < size)
		{
			dst[dstl + i] = src[i];
			i++;
		}
		dst[dstl + i] = '\0';
	}
	if (dstl <= size)
		srcl = srcl + dstl;
	else
		srcl = srcl + size;
	return (srcl);
}
