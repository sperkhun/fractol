/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 12:52:30 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/19 12:52:31 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(int but, int x, int y, t_thr *t)
{
	double mr;
	double mi;
	double interpolation;

	t->m.pr.s = 0;
	interpolation = 0;
	if ((but == 1 || but == 4) && t->m.z < 320)
		interpolation = 0.9;
	if ((but == 2 || but == 5))
		interpolation = 1.1;
	if (interpolation != 0)
	{
		mr = t->m.pr.mnr + x * (t->m.pr.mxr - t->m.pr.mnr) / (WIN_SIZE_W - 1);
		mi = t->m.pr.mxi - y * (t->m.pr.mxi - t->m.pr.mni) / (WIN_SIZE_H - 1);
		t->m.pr.mnr = mr + ((t->m.pr.mnr - mr) * interpolation);
		t->m.pr.mxi = mi + ((t->m.pr.mxi - mi) * interpolation);
		t->m.pr.mxr = mr + ((t->m.pr.mxr - mr) * interpolation);
		t->m.pr.mni = mi + ((t->m.pr.mni - mi) * interpolation);
	}
	interpolation == 1.1 ? t->m.z-- : 0;
	interpolation == 0.9 ? t->m.z++ : 0;
}

static void	choosefract(int x, int y, t_thr *t)
{
	x >= 0 && x < 400 && y >= 0 && y < 300 ? t->m.pr.fr = 0 : 0;
	x >= 400 && x < 800 && y >= 0 && y < 300 ? t->m.pr.fr = 1 : 0;
	x >= 800 && x < 1200 && y >= 0 && y < 300 ? t->m.pr.fr = 2 : 0;
	x >= 0 && x < 400 && y >= 300 && y < 600 ? t->m.pr.fr = 3 : 0;
	x >= 400 && x < 800 && y >= 300 && y < 600 ? t->m.pr.fr = 4 : 0;
	x >= 800 && x < 1200 && y >= 300 && y < 600 ? t->m.pr.fr = 5 : 0;
	x >= 0 && x < 400 && y >= 600 && y < 900 ? t->m.pr.fr = 6 : 0;
	x >= 400 && x < 800 && y >= 600 && y < 900 ? t->m.pr.fr = 7 : 0;
	x >= 800 && x < 1200 && y >= 600 && y < 900 ? t->m.pr.fr = 8 : 0;
	setxy(&t->m);
	setnbs(&t->m);
}

int			mouse_hook(int but, int x, int y, t_thr *t)
{
	if (x > 0 && y > 0 && x < WIN_SIZE_W && y < WIN_SIZE_H && t->m.xxmx != 400\
			&& (but == 1 || but == 2 || but == 4 || but == 5))
	{
		zoom(but, x, y, t);
		draw_image(t);
	}
	if (t->m.xxmx == 400 && but == 1)
	{
		choosefract(x, y, t);
		draw_image(t);
	}
	return (0);
}

int			mouse_mot(int x, int y, t_thr *t)
{
	if (x > 0 && y > 0 && x < WIN_SIZE_W && y < WIN_SIZE_H && t->m.pr.s == 1\
			&& t->m.pr.fr >= 3 && t->m.xxmx == 1200 && t->m.pr.fr != 6)
	{
		t->m.pr.j_r = (double)x / WIN_SIZE_W * 4 - 2;
		t->m.pr.j_i = (double)y / WIN_SIZE_H * 4 - 2;
		draw_image(t);
	}
	return (0);
}

int			exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}
