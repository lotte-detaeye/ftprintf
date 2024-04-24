/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:48:44 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/05 11:20:34 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*ptr_d;
	char		*ptr_s;
	size_t		i;

	ptr_d = (char *)dest;
	ptr_s = (char *)src;
	if (!ptr_d && !ptr_s)
		return (0);
	i = 0;
	while (i < n)
	{
		*ptr_d = *ptr_s;
		ptr_d++;
		ptr_s++;
		i++;
	}
	return (dest);
}
