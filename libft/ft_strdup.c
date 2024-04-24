/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:54:19 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/05 11:21:25 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstr;
	size_t	length;

	length = ft_strlen(s) + 1;
	newstr = (char *)malloc(length * sizeof(char));
	if (newstr == 0)
		return (0);
	ft_memcpy(newstr, s, length);
	return (newstr);
}
