/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:49:44 by ysay              #+#    #+#             */
/*   Updated: 2022/02/09 09:10:53 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	movright(t_map *map, t_obj *d)
{
	int		x;
	int		y;
	char	*c;
	int		i;

	i = 1;
	y = 0;
	while (y < map->row)
		i &= !ft_strchr(map->data[y++], d->s_env.look);
	x = d->posx;
	y = d->posy;
	c = &map->data[y][x + 1];
	if (x < map->len - 1 && (ft_strchr(d->s_env.mov,
				*c) || ((*c == d->s_env.wait) && i)))
	{
		d->tpx = d->an->imgs[0]->img[0]->width * (x + 1);
		d->tpy = d->an->imgs[0]->img[0]->height * y;
		map->data[y][x] = '0';
		d->posx = x + 1;
		d->posy = y;
		d->busy = 1;
		return (1);
	}
	return (0);
}

int	movdown(t_map *map, t_obj *d)
{
	int		x;
	int		y;
	char	*c;
	int		i;

	i = 1;
	y = 0;
	while (y < map->row)
		i &= !ft_strchr(map->data[y++], d->s_env.look);
	x = d->posx;
	y = d->posy;
	c = &map->data[y + 1][x];
	if (y < map->row - 1 && (ft_strchr(d->s_env.mov,
				*c) || ((*c == d->s_env.wait) && i)))
	{
		d->tpx = d->an->imgs[0]->img[0]->width * x;
		d->tpy = d->an->imgs[0]->img[0]->height * (y + 1);
		map->data[y][x] = '0';
		d->posx = x;
		d->posy = y + 1;
		d->busy = 1;
		return (1);
	}
	return (0);
}

int	movleft(t_map *map, t_obj *d)
{
	int		x;
	int		y;
	char	*c;
	int		i;

	i = 1;
	y = 0;
	while (y < map->row)
		i &= !ft_strchr(map->data[y++], d->s_env.look);
	x = d->posx;
	y = d->posy;
	c = &map->data[y][x - 1];
	if (x && (ft_strchr(d->s_env.mov, *c) || ((*c == d->s_env.wait) && i)))
	{
		d->tpx = d->an->imgs[0]->img[0]->width * (x - 1);
		d->tpy = d->an->imgs[0]->img[0]->height * y;
		map->data[y][x] = '0';
		d->posx = x - 1;
		d->posy = y;
		d->busy = 1;
		return (1);
	}
	return (0);
}

int	movup(t_map *map, t_obj *d)
{
	int		x;
	int		y;
	char	*c;
	int		i;

	i = 1;
	y = 0;
	while (y < map->row)
		i &= !ft_strchr(map->data[y++], d->s_env.look);
	x = d->posx;
	y = d->posy;
	c = &map->data[y - 1][x];
	if (y && (ft_strchr(d->s_env.mov, *c) || ((*c == d->s_env.wait) && i)))
	{
		d->tpx = d->an->imgs[0]->img[0]->width * x ;
		d->tpy = d->an->imgs[0]->img[0]->height * (y - 1);
		map->data[y][x] = '0';
		d->posx = x;
		d->posy = y - 1;
		d->busy = 1;
		return (1);
	}
	return (0);
}

int	mov(t_map *map, t_obj *d, int cmd)
{
	if (d->busy)
		return (-1);
	if (cmd == 13)
		return (movup(map, d));
	if (cmd == 0)
		return (movleft(map, d));
	if (cmd == 1)
		return (movdown(map, d));
	if (cmd == 2)
		return (movright(map, d));
	return (0);
}
