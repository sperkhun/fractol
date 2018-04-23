/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setprmt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:55:25 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/18 17:55:26 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setnbs(t_mlx *m)
{
	m->pr.mnr = -2.1;
	m->pr.mxr = 1.1;
	m->pr.mni = -1.2;
	if (m->pr.fr >= 2 && m->pr.fr <= 6)
	{
		m->pr.mnr = -2.6;
		m->pr.mxr = 2.6;
		m->pr.mni = -2.0;
	}
	if (m->pr.fr == 1)
	{
		m->pr.mxr = 1.6;
		m->pr.mni = -1.0;
	}
	if (m->pr.fr >= 7)
	{
		m->pr.mnr = -3.5;
		m->pr.mxr = 3.5;
		m->pr.mni = -2.5;
	}
	m->pr.mxi = m->pr.mni + (m->pr.mxr - m->pr.mnr) * m->ymx / m->xxmx;
	m->pr.j_r = -0.4;
	m->pr.j_i = 0.6;
	m->pr.s = 1;
	m->z = 0;
}

void	setxy(t_mlx *m)
{
	m->xmn = 0;
	m->ymn = 0;
	m->xmx = WIN_SIZE_W;
	m->ymx = WIN_SIZE_H;
	m->xxmx = WIN_SIZE_W;
}

void	setclr(t_mlx *m)
{
	m->c.r_f = 0.01;
	m->c.g_f = 0.013;
	m->c.b_f = 0.016;
	m->c.r_p = 0.1;
	m->c.g_p = 0.2;
	m->c.b_p = 0.4;
	m->c.w = 230;
	m->c.c = 25;
}

void	setprmt(t_mlx *m)
{
	m->pr.i = 120;
	m->c.k = 0;
	setxy(m);
	setnbs(m);
	setclr(m);
}
