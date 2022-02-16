/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:52:18 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 12:34:36 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	in1(t_map *map, t_image *win, struct s_obj *obj)
{
	int		i;
	int		d;
	t_image	*img;

	img = obj->an->imgs[0]->img[0];
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
}
