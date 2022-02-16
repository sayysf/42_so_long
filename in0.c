/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in0.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:51:30 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 12:34:33 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

void	in0(t_map *map, t_image *win, struct s_obj *obj)
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
			mlx_put_image_to_window(win->obj, win->win,
				img->data, i * img->width, d * img->height);
			i++;
		}
		d++;
	}
}
