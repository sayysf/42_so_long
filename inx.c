/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:52:41 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 15:20:31 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	ck_inxt_image(t_map *map, struct s_obj *obj)
{
	if (obj->tpx == obj->px && obj->tpy == obj->py)
	{
		obj->busy = 0;
		if (ft_strchr(obj->s_env.exit, map->data[obj->posy][obj->posx]))
			obj->status = 0;
		map->data[obj->posy][obj->posx] = obj->type;
		return (1);
	}
	return (0);
}

static t_image	*look1(struct s_obj *obj, int flag, int step)
{
	if (obj->tpy != obj->py)
	{
		if (obj->tpy - obj->py < 0)
		{
			obj->py -= step;
			return (obj->an->imgs[0 * flag]->img[obj->cnt
					% obj->an->imgs[0 * flag]->img_s]);
		}
		else
		{
			obj->py += step;
			return (obj->an->imgs[1 * flag]->img[obj->cnt
					% obj->an->imgs[1 * flag]->img_s]);
		}
	}
	return (NULL);
}

static t_image	*look2(struct s_obj *obj, int flag, int step)
{
	if (obj->tpx != obj->px)
	{
		if (obj->tpx - obj->px < 0)
		{
			obj->px -= step;
			return (obj->an->imgs[3 * flag]->img[obj->cnt
					% obj->an->imgs[3 * flag]->img_s]);
		}
		else
		{
			obj->px += step;
			return (obj->an->imgs[2 * flag]->img[obj->cnt
					% obj->an->imgs[2 * flag]->img_s]);
		}
	}
	return (NULL);
}

t_image	*inx(t_map *map, struct s_obj *obj, int flag, int step)
{
	t_image	*img;

	if (ck_inxt_image(map, obj))
		return (NULL);
	img = look1(obj, flag, step);
	if (img)
		return (img);
	img = look2(obj, flag, step);
	if (img)
		return (img);
	return (NULL);
}
