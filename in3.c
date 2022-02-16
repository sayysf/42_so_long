/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:52:26 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 12:34:50 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

static int	look3(t_map *map, t_obj *obj)
{
	int		x;
	int		d;

	x = 1;
	d = 0;
	while (d < map->row)
		x &= !ft_strchr(map->data[d++], 'C');
	if (x && 1 < obj->status)
		x = 2;
	if (obj->busy >= obj->an->imgs[x]->img_s)
	{
			x = 1;
			obj->status = 1;
			obj->busy = 0;
	}
	return (x);
}

void	in3(t_map *map, t_image *win, struct s_obj *obj)
{
	int		x;
	int		i;
	int		d;
	t_image	*img;

	x = look3(map, obj);
	img = obj->an->imgs[x]->img[obj->busy];
		d = 0;
	while (d < map->row)
	{
		i = 0;
		while (i < map->len)
		{
			if (map->data[d][i] == obj->type)
				mlx_put_image_to_window(win->obj, win->win,
					img->data, i * img->width, d * img->height);
			i++;
		}
		d++;
	}
	if (x == 2)
		obj->busy++;
}
