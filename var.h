/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysay <ysay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:27:57 by ysay              #+#    #+#             */
/*   Updated: 2022/02/09 08:56:38 by ysay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VAR_H
# define VAR_H

char	*g_m1[] = {"./maps/m/a1.xpm", "./maps/m/a2.xpm", "./maps/m/a3.xpm",
	"./maps/m/a4.xpm", "./maps/m/a5.xpm", "./maps/m/a5.xpm",
	"./maps/m/a7.xpm", "./maps/m/a8.xpm", NULL};
char	**g_m_an[] = {g_m1, NULL};

char	*g_p1[] = {"./maps/p/u1.xpm", "./maps/p/u2.xpm",
	"./maps/p/u3.xpm", "./maps/p/u4.xpm", NULL};
char	*g_p2[] = {"./maps/p/d1.xpm", "./maps/p/d2.xpm",
	"./maps/p/d3.xpm", "./maps/p/d4.xpm", NULL};
char	*g_p3[] = {"./maps/p/r1.xpm", "./maps/p/r2.xpm",
	"./maps/p/r3.xpm", "./maps/p/r4.xpm", NULL};
char	*g_p4[] = {"./maps/p/l1.xpm", "./maps/p/l2.xpm",
	"./maps/p/l3.xpm", "./maps/p/l4.xpm", NULL};
char	*g_p5[] = {"./maps/p/s1.xpm", "./maps/p/s2.xpm",
	"./maps/p/s3.xpm", NULL};
char	**g_p_an[] = {g_p1, g_p2, g_p3, g_p4, g_p5, NULL};

char	*g_c1[] = {"./maps/c/a1.xpm", "./maps/c/a2.xpm", "./maps/c/a3.xpm",
	"./maps/c/a4.xpm", "./maps/c/a5.xpm", "./maps/c/a6.xpm", NULL};
char	**g_c_an[] = {g_c1, NULL};

char	*g_e1[] = {"./maps/e/s1.xpm", NULL};
char	*g_e2[] = {"./maps/e/s2.xpm", NULL};
char	*g_e3[] = {"./maps/e/a1.xpm", "./maps/e/a2.xpm",
	"./maps/e/a3.xpm", "./maps/e/a4.xpm", NULL};
char	**g_e_an[] = {g_e1, g_e2, g_e3, NULL};

char	*g_o_[] = {"./maps/0/0.xpm", NULL};
char	**g_o_an[] = {g_o_, NULL};

char	*g_i_[] = {"./maps/1/1.xpm", NULL};
char	**g_i_an[] = {g_i_, NULL};

char	***g_an[] = {
	g_o_an, g_i_an, g_c_an, g_e_an, g_p_an, g_m_an, NULL};

void	(*g_in[6])(t_map *, t_image *, struct s_obj *) = {
	in0,
	in1,
	in2,
	in3,
	in4,
	in5
};

#endif