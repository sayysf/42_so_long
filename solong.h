/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:41:03 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 19:04:48 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <unistd.h>
# include <libft.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	char	**data;
	int		len;
	int		row;
}	t_map;

typedef struct s_image
{
	void	*obj;
	void	*data;
	void	*addr;
	void	*win;
	int		width;
	int		height;
	int		bit_pp;
	int		l_len;
	int		endian;
}	t_image;

typedef struct s_images
{
	int		img_s;
	t_image	*img[];
}	t_images;

typedef struct s_an
{
	int			imgs_s;
	t_images	*imgs[];
}	t_an;

typedef struct s_obj
{
	t_an		*an;
	void		(*in)(t_map *, t_image *, struct s_obj *);
	int			cnt;
	int			gcnt;
	int			sign;
	int			status;
	int			type;
	int			busy;
	int			posx;
	int			posy;
	int			px;
	int			py;
	int			tpx;
	int			tpy;
	struct
	{
		char	*mov;
		char	*exit;
		char	look;
		char	wait;

	}			s_env;
}	t_obj;

typedef struct s_objs
{
	int		osize;	
	t_obj	*olist[];
}	t_objs;

typedef struct s_game
{
	t_objs	*objs;
	t_map	*map;
	t_image	*window;
	char	*str;
	char	*d;
	size_t	cnt;
	int		stepx;
	int		stepy;
}	t_game;

typedef struct s_basic_game
{
	t_images	*imgs;
	t_map		*map;
	t_image		*win;
	char		*str;
	int			x;
	int			y;
}	t_basic_game;

extern void		*g_init;

char		*get_map(char *av);
t_map		*creat_map(char *s);
t_map		*init(char *av, char *str, char *str2);
int			give_pos(t_map *map, t_obj *d, int c);
int			kill_map(t_map *map);

int			check_wall(t_map *map, int c);
int			check_other(t_map *map, char *str);
t_map		*check_map(char *s, char *str, char *str2);

int			kill_images(t_images *imgs);
int			kill_image(t_image *img);
t_images	*take_images(char **path);
t_image		*take_image(char*path);
t_image		*take_new_window(char *name, int width, int height);

int			kill_an(t_an *an);
t_an		*take_an(char ***path);

int			kill_obj(t_obj	*obj);
int			kill_objs(t_objs *objs);
t_obj		*take_obj(int c, int d, char ***path, void (*in)(t_map *,
					t_image *, struct s_obj *));
t_objs		*take_objs(char *c, char *d, char ****path, void (**in)(t_map *,
					t_image *, struct s_obj *));

int			movright(t_map *map, t_obj *d);
int			movdown(t_map *map, t_obj *d);
int			movleft(t_map *map, t_obj *d);
int			movup(t_map *map, t_obj *d);
int			mov(t_map *map, t_obj *d, int cmd);

void		in0(t_map *map, t_image *win, struct s_obj *obj);
void		in1(t_map *map, t_image *win, struct s_obj *obj);
void		in2(t_map *map, t_image *win, struct s_obj *obj);
void		in3(t_map *map, t_image *win, struct s_obj *obj);
void		in4(t_map *map, t_image *win, struct s_obj *obj);
void		in5(t_map *map, t_image *win, struct s_obj *obj);

t_image		*inx(t_map *map, struct s_obj *obj, int flag, int step);

int			ck_inxt_image(t_map *map, struct s_obj *obj);
int			kill_render(t_game *game);
int			cmd(int key, t_game *game);
int			check_crash(t_game *game);
void		monitor(t_game *game, t_obj *obj);
int			game_render(t_game *game);

#endif
