/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 08:43:35 by aquincho          #+#    #+#             */
/*   Updated: 2022/05/04 08:43:39 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)s;
	if (c < 0)
		return (NULL);
	if (c > 255)
		return (NULL);
	while (*(tmp + i))
	{
		if (*(tmp + i) == c)
			return (tmp + i);
		i++;
	}
	if (*(tmp + i) == c)
		return (tmp + i);
	return (NULL);
}
