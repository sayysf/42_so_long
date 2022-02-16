/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:42:51 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 11:43:26 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	kill_an(t_an *an)
{
	int	i;

	i = 0;
	if (!an)
		return (0);
	while (i < an->imgs_s)
	{
		if (an->imgs[i])
			kill_images(an->imgs[i]);
		an->imgs[i] = 0;
		i++;
	}
	free(an);
	return (1);
}

t_an	*take_an(char ***path)
{
	int		i;
	t_an	*an;

	i = 0;
	while (path[i])
		i++;
	if (!i)
		return (NULL);
	an = ft_calloc(sizeof(t_an) + (sizeof(t_images *) * i), 1);
	if (!an)
		return (NULL);
	an->imgs_s = i;
	i = 0;
	while (i < an->imgs_s)
	{
		an->imgs[i] = take_images(path[i]);
		if (!an->imgs[i])
		{
			kill_an(an);
			return (NULL);
		}
		i++;
	}
	return (an);
}
