/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:30:49 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 19:06:52 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>
#include <var.h>

void	*g_init;

void	init_o(t_objs *ob)
{
	int	i;

	i = 0;
	while (i < ob->osize)
	{
		if (ob->olist[i]->type == 'P')
		{
				ob->olist[i]->s_env.mov = "0CMP";
				ob->olist[i]->s_env.look = 'C';
				ob->olist[i]->s_env.wait = 'E';
		}
		if (ob->olist[i]->type == 'M')
		{
				ob->olist[i]->s_env.mov = "0CMP";
				ob->olist[i]->s_env.look = 0;
				ob->olist[i]->s_env.wait = 'P';
		}
		i++;
	}
}

int	game_i(t_game *game, char ****path,
		void (**in)(t_map *, t_image *, struct s_obj *))
{
	int	i;

	game->objs = take_objs(game->str, game->d, path, in);
	if (!game->objs)
	{
		ft_putstr_fd("Erorr\nObje hatası\n", 2);
		exit(-1);
	}
	i = 0;
	while (i < game->objs->osize)
	{
		if (!give_pos(game->map, game->objs->olist[i],
				game->objs->olist[i]->type))
			game->objs->olist[i]->status = 0;
		i++;
	}
	game->window = take_new_window("run run run!",
			game->map->len * game->objs->olist[0]->an->imgs[0]->img[0]->width,
			game->map->row * game->objs->olist[0]->an->imgs[0]->img[0]->height);
	mlx_hook(game->window->win, 17, 0, kill_render, game);
	mlx_hook(game->window->win, 2, 0, cmd, game);
	mlx_loop_hook(game->window->obj, game_render, game);
	mlx_loop(game->window->obj);
	exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac < 2)
	{
		ft_putstr_fd("Error\nArguman Not Found\n", 2);
		return (-1);
	}
	game.map = init(av[1], "01ECPM", "ECP");
	game.str = "01CEPM";
	game.d = "PM";
	if (!game.map)
		return (-1);
	g_init = mlx_init();
	game_i(&game, g_an, g_in);
	return (0);
}
