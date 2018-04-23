/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:18:19 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/08 10:18:19 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	drawpxl(int x, int y, t_mlx *m, t_nb nb)
{
	int		i;
	double	zn;
	double	ind;

	if (x < 0 || x >= m->xxmx || y < 0 || y >= m->ymx)
		return ;
	i = x * m->bpp + y * m->s_line;
	if ((nb.n < m->pr.i && m->pr.fr < 7) || (m->pr.fr >= 7 &&\
		(fabs(nb.z_r) > 10 || fabs(nb.z_i) > 1000)))
	{
		zn = sqrt(nb.c_r * nb.c_r + nb.c_i * nb.c_i);
		ind = nb.n + 1 - (log(2) / zn) / log(2);
		m->pxl_img[i] = sin(m->c.b_f * ind + m->c.b_p) * m->c.w + m->c.c;
		m->pxl_img[++i] = sin(m->c.g_f * ind + m->c.g_p) * m->c.w + m->c.c;
		m->pxl_img[++i] = sin(m->c.r_f * ind + m->c.r_p) * m->c.w + m->c.c;
	}
	else
	{
		m->pxl_img[i] = 0;
		m->pxl_img[++i] = 0;
		m->pxl_img[++i] = 0;
	}
}

void	drawlines(t_mlx *m, int s, int e)
{
	t_nb	nb;

	nb.y = s;
	while (nb.y <= e)
	{
		nb.c_i = m->pr.mxi - nb.y * (m->pr.mxi - m->pr.mni) / (m->ymx - 1);
		nb.x = 0;
		while (nb.x < m->xxmx)
		{
			nb.c_r = m->pr.mnr + nb.x * (m->pr.mxr - m->pr.mnr) / (m->xxmx - 1);
			nb.z_r = nb.c_r;
			nb.z_i = nb.c_i;
			if (!m->pr.fr || m->pr.fr == 1 || m->pr.fr == 2)
				mandelbrot(m, nb);
			else if (m->pr.fr >= 3 && m->pr.fr <= 5)
				julia(m, nb);
			else if (m->pr.fr == 7 || m->pr.fr == 8)
				biom(m, nb);
			else if (m->pr.fr == 6)
				newton(m, nb);
			nb.x++;
		}
		nb.y++;
	}
}
