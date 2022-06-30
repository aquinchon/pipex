/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquincho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:27:16 by aquincho          #+#    #+#             */
/*   Updated: 2022/05/05 12:27:18 by aquincho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_process_word(int *i, char *str, char c)
{
	int	j;

	j = 0;
	if (str[*i] == '\'')
	{
		(*i)++;
		while (!(str[*i + j] == '\'' || str[*i + j] == '\0'))
			j++;
	}
	else if (str[*i] == '\"')
	{
		(*i)++;
		while (!(str[*i + j] == '\"' || str[*i + j] == '\0'))
			j++;
	}
	else
	{
		while (!(str[*i + j] == c || str[*i + j] == '\0'))
			j++;
	}
	return (j);		
}

static int	ft_process_split(char **split, char *str, char c, int wrds_cnt)
{
	int	i;
	int	j;
	int	wrd_cnt;

	i = 0;
	wrd_cnt = 0;
	while (str[i] && wrd_cnt < wrds_cnt)
	{
		while (str[i] == c)
			i++;
		j = ft_process_word(&i, str, c);
		split[wrd_cnt] = malloc((j + 1) * sizeof(char));
		if (!split[wrd_cnt])
		{
			ft_free_split(split, wrd_cnt);
			return (0);
		}
		split[wrd_cnt] = ft_write_word(split[wrd_cnt], str + i, j);
		wrd_cnt++;
		i += j;
		if (str[i] == '\'' || str[i] == '\"')
			i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		wrds_cnt;
	char	**res;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	wrds_cnt = ft_word_count(str, c);
	res = malloc((wrds_cnt + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (wrds_cnt)
		if (!ft_process_split(res, str, c, wrds_cnt))
			return (NULL);
	res[wrds_cnt] = NULL;
	return (res);
}
