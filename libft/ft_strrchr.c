/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:51:09 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/08 18:57:55 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	unsigned char	ch;
	int				i;

	ch = c;
	i = 0;
	while (s[i] != '\0')
		i++;
	if (ch == '\0')
		return (s + i);
	while (i--)
	{
		if (s[i] == ch)
			return (s + i);
	}
	return (0);
}
