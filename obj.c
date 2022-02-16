/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:24:51 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 15:27:34 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	kill_obj(t_obj	*obj)
{
	if (!obj)
		return (0);
	if (obj->an)
		kill_an(obj->an);
	obj->an = 0;
	obj->posx = 0;
	obj->posy = 0;
	free(obj);
	return (1);
}

int	kill_objs(t_objs *objs)
{
	int	i;

	if (!objs)
		return (0);
	i = 0;
	while (i < objs->osize)
	{
		kill_obj(objs->olist[i]);
		objs->olist[i] = NULL;
		i++;
	}
	free(objs);
	return (1);
}

void	init_obj(t_obj *obj)
{
	if (obj->type == 'P')
	{
		obj->s_env.mov = "0CMP";
		obj->s_env.exit = "EM";
		obj->s_env.look = 'C';
		obj->s_env.wait = 'E';
	}
	if (obj->type == 'M')
	{
		obj->s_env.mov = "0CMP";
		obj->s_env.exit = "X";
		obj->s_env.look = 0;
		obj->s_env.wait = 'P';
	}
}

t_obj	*take_obj(int c, int d, char ***path,
	void (*in)(t_map *, t_image *, struct s_obj *))
{
	t_obj	*obj;

	obj = ft_calloc(sizeof(t_obj), 1);
	if (!obj)
		return (NULL);
	obj->an = take_an(path);
	if (!obj->an)
		return (NULL);
	obj->gcnt = 0;
	obj->in = in;
	obj->sign = d;
	obj->status = 100;
	obj->type = c;
	obj->busy = 0;
	init_obj(obj);
	return (obj);
}

t_objs	*take_objs(char *c, char *d, char ****path,
	void (**in)(t_map *, t_image *, struct s_obj *))
{
	int		dn;
	int		i;
	t_objs	*objs;

	i = 0;
	while (path[i])
		i++;
	objs = ft_calloc(sizeof(t_objs) + (sizeof(t_obj *) * i), 1);
	objs->osize = i;
	i = 0;
	while (i < objs->osize)
	{
		dn = ft_strchr(d, c[i]) != NULL;
		objs->olist[i] = take_obj(c[i], dn, path[i], in[i]);
		if (!objs->olist[i])
		{
			kill_objs(objs);
			return (NULL);
		}
		i++;
	}
	return (objs);
}
