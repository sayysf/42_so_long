/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:22:56 by ysay              #+#    #+#             */
/*   Updated: 2022/02/08 18:52:06 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solong.h>

char	*get_map(char *av)
{
	int		fd;
	char	*tmp;
	char	*str;
	char	*s;

	s = NULL;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	str = ft_calloc(1, 1);
	tmp = get_next_line(fd);
	if (!tmp)
		free(str);
	while (tmp)
	{
		s = ft_strjoin(str, tmp);
		free(str);
		free(tmp);
		str = s;
		tmp = get_next_line(fd);
	}
	return (s);
}

t_map	*creat_map(char *s)
{
	t_map	*map;

	map = calloc(sizeof(t_map), 1);
	map->data = ft_split(s, '\n');
	if (!map->data)
	{	
		free(map);
		return (0);
	}
	map->len = ft_strlen(map->data[0]);
	map->row++;
	while (map->data[map->row])
	{
		if (map->len != (int)ft_strlen(map->data[map->row]))
		{
			kill_map(map);
			return (0);
		}
		map->row++;
	}
	return (map);
}

int	give_pos(t_map *map, t_obj *d, int c)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->len)
		{
			if (map->data[y][x] == c)
			{
				d->posx = x;
				d->posy = y;
				d->px = d->an->imgs[0]->img[0]->width * x;
				d->py = d->an->imgs[0]->img[0]->height * y;
				d->tpx = d->an->imgs[0]->img[0]->width * x;
				d->tpy = d->an->imgs[0]->img[0]->height * y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	kill_map(t_map *map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (i < map->row)
	{
		if (map->data[i])
			free(map->data[i]);
		i++;
	}
	free(map->data);
	free(map);
	return (1);
}

t_map	*init(char *av, char *str, char *str2)
{
	size_t	l;
	char	*s;
	t_map	*map;

	l = ft_strlen(av);
	if (l < 4 || av[l - 4] != '.' || av[l - 3] != 'b' || av[l - 2] != 'e'
		|| av[l - 1] != 'r')
	{	
		ft_putstr_fd("Error\nArguman Error\n", 2);
		exit (-1);
	}
	s = get_map(av);
	map = check_map(s, str, str2);
	free(s);
	if (!map)
	{	
		ft_putstr_fd("Error\nMap Error\n", 2);
		exit (-1);
	}
	return (map);
}
