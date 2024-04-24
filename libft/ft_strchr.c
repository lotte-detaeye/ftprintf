/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:50:48 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/05 11:21:21 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)s + i);
	return (0);
}
