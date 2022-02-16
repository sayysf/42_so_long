/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:49:21 by ysay              #+#    #+#             */
/*   Updated: 2022/01/04 14:48:41 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ch;
	int		i;

	i = 0;
	ch = (char *)malloc(ft_strlen(s) + 1);
	if (!ch)
		return (NULL);
	while (s[i] != '\0')
	{
		ch[i] = s[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
