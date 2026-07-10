/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:11:40 by moduwole          #+#    #+#             */
/*   Updated: 2022/05/02 11:11:40 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s != NULL)
	{
		if (start >= ft_strlen(s))
		{
			str = ft_calloc(1, sizeof(char));
			if (str == NULL)
				return (NULL);
			return (str);
		}
		if (len > ft_strlen(s + start))
			len = ft_strlen(s + start);
		str = ft_calloc(len + 1, sizeof(char));
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, &s[start], len + 1);
		return (str);
	}
	return (NULL);
}
