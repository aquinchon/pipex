/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:40:43 by aquincho          #+#    #+#             */
/*   Updated: 2022/06/28 10:40:46 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **split, int wrd_cnt)
{
	int	i;

	i = 0;
	while (i < wrd_cnt)
	{
		free(split[wrd_cnt]);
		i++;
	}
	free(split);
}

static int	ft_count_quote(char *s, int i, char quote, int *res)
{
	if (s[i] == quote)
	{
		i++;
		while (s[i] && s[i] != quote)
			i++;
		(*res)++;
	}
	return (i);
}

int	ft_word_count(char *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		i = ft_count_quote(s, i, '\'', &res);
		i = ft_count_quote(s, i, '\"', &res);
		if (s[i] == '\'' || s[i] == '\"')
			i++;
		if (s[i] && ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c)))
			res++;
		i++;
	}
	return (res);
}

char	*ft_write_word(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
