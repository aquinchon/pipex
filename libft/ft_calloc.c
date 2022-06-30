/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:07:38 by aquincho          #+#    #+#             */
/*   Updated: 2022/05/04 14:07:40 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*mem;
	size_t	i;

	total = size * nmemb;
	if (size != 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	if (total == 0)
		mem = malloc(1);
	else
		mem = malloc(total);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < total)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
