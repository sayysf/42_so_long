/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:52:35 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 16:09:00 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	in4(t_map *map, t_image *win, struct s_obj *obj)
{
	t_image	*img;
	int		x;
	int		d;

	img = NULL;
	x = 1;
	d = 0;
	while (d < map->row)
		x &= !ft_strchr(map->data[d++], obj->s_env.look);
	if (obj->busy)
		img = inx(map, obj, 1, 12);
	if (!img)
		img = obj->an->imgs[4]->img[x];
	mlx_put_image_to_window(win->obj, win->win,
		img->data, obj->px, obj->py);
}
