/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:45:44 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/05 11:20:48 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			i;

	string = s;
	i = 0;
	while (i < n)
	{
		string[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
