/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:03:03 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/19 13:03:04 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	changefract(t_thr *t)
{
	t->m.xxmx = 400;
	t->m.ymx = 300;
	t->m.pr.fr = -1;
	t->m.ymn = 0;
	while (t->m.ymn <= 600)
	{
		t->m.xmx = 0;
		while (t->m.xmx < 1200)
		{
			t->m.pr.fr++;
			t->m.xmn = t->m.xmx;
			t->m.xmx += 400;
			setnbs(&t->m);
			draw_image(t);
		}
		t->m.ymn += 300;
	}
	putnames(t);
}

static void	changecolor2(t_thr *t)
{
	if (t->m.c.k == 2)
	{
		t->m.c.r_f = 0.3;
		t->m.c.g_f = 0.3;
		t->m.c.b_f = 0.3;
		t->m.c.r_p = 2;
		t->m.c.g_p = 0;
		t->m.c.b_p = 4;
		t->m.c.w = 103;
		t->m.c.c = 152;
	}
	else if (t->m.c.k == 3)
	{
		t->m.c.r_f = 1.666;
		t->m.c.g_f = 2.666;
		t->m.c.b_f = 3.666;
		t->m.c.w = 127;
		t->m.c.c = 128;
	}
	else
		setclr(&t->m);
}

static void	changecolor(t_thr *t)
{
	t->m.c.k == 5 ? t->m.c.k = 0 : 0;
	if (t->m.c.k == 0)
	{
		t->m.c.r_p = 1;
		t->m.c.g_p = 2;
		t->m.c.b_p = 4;
	}
	else if (t->m.c.k == 1)
	{
		t->m.c.r_f = 0.2;
		t->m.c.g_f = 0.2;
		t->m.c.b_f = 0.2;
		t->m.c.r_p = 0;
		t->m.c.g_p = 2;
		t->m.c.b_p = 4;
		t->m.c.w = 55;
		t->m.c.c = 200;
	}
	else
		changecolor2(t);
	t->m.c.k++;
	if (t->m.xxmx == 1200)
		draw_image(t);
	else
		changefract(t);
}

static void	move(int key, t_thr *t)
{
	int		n;
	double	u;

	n = t->m.z;
	t->m.a = 0.2;
	u = n > 70 || n < -80 ? 2.5 : 2;
	n > 130 ? u = 3 : 0;
	while (t->m.z > 0 ? n > 0 : n < 0)
	{
		n = t->m.z > 0 ? n - 10 : n + 10;
		t->m.a = t->m.z > 0 ? t->m.a / u : t->m.a * u;
	}
	if (key == 124 && (t->m.pr.mnr -= t->m.a))
		t->m.pr.mxr -= t->m.a;
	else if (key == 123 && (t->m.pr.mnr += t->m.a))
		t->m.pr.mxr += t->m.a;
	else if (key == 125 && (t->m.pr.mni += t->m.a))
		t->m.pr.mxi += t->m.a;
	else if (key == 126 && (t->m.pr.mni -= t->m.a))
		t->m.pr.mxi -= t->m.a;
}

int			key_hook(int key, t_thr *t)
{
	if (key == 53)
	{
		mlx_destroy_window(t->m.mlx, t->m.win);
		exit(0);
	}
	if (key == 15)
	{
		t->m.pr.s = 1;
		setnbs(&t->m);
	}
	key == 69 && t->m.pr.i < 500 ? t->m.pr.i += 1 : 0;
	key == 78 && t->m.pr.i > 10 ? t->m.pr.i -= 1 : 0;
	move(key, t);
	if (key == 8 || (key == 1 && t->m.xxmx == 1200))
	{
		key == 1 ? changefract(t) : 0;
		key == 8 ? changecolor(t) : 0;
		return (0);
	}
	draw_image(t);
	return (0);
}
