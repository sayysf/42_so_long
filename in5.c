/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:52:37 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 16:02:52 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

static int	fire(t_map *map, t_obj *obj)
{
	if (obj->status == 100)
	{
		if (0 == mov(map, obj, 1))
			obj->status = 50;
	}
	if (obj->status == 50)
	{
		if (0 == mov(map, obj, 13))
			obj->status = 100;
	}
	return (obj->status);
}

void	in5(t_map *map, t_image *win, struct s_obj *obj)
{
	t_image	*img;

	img = NULL;
	fire(map, obj);
	if (obj->busy)
		img = inx(map, obj, 0, 4);
	if (!img)
		img = obj->an->imgs[0]->img[obj->cnt / 3 % obj->an->imgs[0]->img_s];
	mlx_put_image_to_window(win->obj, win->win,
		img->data, obj->px, obj->py);
}
