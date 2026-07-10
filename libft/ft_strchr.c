/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moduwole <moduwole@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 13:14:17 by moduwole          #+#    #+#             */
/*   Updated: 2022/04/29 13:14:17 by moduwole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if ((unsigned char) str[i] == (unsigned char) c)
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (str[i] == (unsigned char) c)
		return ((char *)(str + i));
	return (NULL);
}
