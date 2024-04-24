/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:32:17 by lde-taey          #+#    #+#             */
/*   Updated: 2023/12/08 18:58:10 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	strl;

	strl = ft_strlen(s);
	if (s == 0 || strl < start)
		return (ft_strdup(""));
	if (start + len < strl)
		newstr = (char *)malloc((len + 1) * sizeof(char));
	else
		newstr = (char *)malloc((strl - start + 1) * sizeof(char));
	if (newstr == 0)
		return (0);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
