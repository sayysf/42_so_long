/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:16:43 by ysay              #+#    #+#             */
/*   Updated: 2022/02/09 09:11:50 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

int	kill_render(t_game *game)
{
	kill_objs(game->objs);
	kill_image(game->window);
	kill_map(game->map);
	exit(1);
	return (0);
}

int	cmd(int key, t_game *game)
{
	if (key == 53)
		kill_render(game);
	if (1 == mov(game->map, game->objs->olist[4], key))
	{
		game->objs->olist[4]->gcnt++;
		ft_printf("%d\n", game->objs->olist[4]->gcnt);
	}
	return (0);
}

int	check_crash(t_game *game)
{
	int		x;
	int		y;
	t_obj	*o1;
	t_obj	*o2;

	x = 0;
	y = 0;
	o1 = game->objs->olist[4];
	o2 = game->objs->olist[5];
	x |= ((o1->px <= o2->px && (o1->px + 25) >= o2->px));
	x |= ((o2->px <= o1->px && (o2->px + 25) >= o1->px));
	y |= ((o1->py <= o2->py && (o1->py + 25) >= o2->py));
	y |= ((o2->py <= o1->py && (o2->py + 25) >= o1->py));
	if (x & y)
		o1->status = 0;
	return (0);
}

void	monitor(t_game *game, t_obj *obj)
{
	char	*s;

	s = ft_itoa(obj->gcnt);
	mlx_string_put(game->window->obj, game->window->win, 15, 15, 0, s);
	free(s);
}

int	game_render(t_game *game)
{
	int	i;
	int	tt;

	if (game->objs->olist[4]->status == 0)
		kill_render(game);
	i = 0;
	while (i < game->objs->osize)
	{
		check_crash(game);
		game->objs->olist[i]->cnt = game->cnt;
		if (game->objs->olist[i]->status)
			game->objs->olist[i]->in(game->map,
				game->window, game->objs->olist[i]);
		i++;
	}
	monitor(game, game->objs->olist[4]);
	tt = 0;
	while (tt++ < 0x02ffffff)
		;
	game->cnt++;
	return (0);
}
