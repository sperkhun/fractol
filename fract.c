/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:26:35 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/15 15:26:37 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_mlx *m, t_nb nb)
{
	double	tmp;
	double	r;
	double	i;

	nb.n = 0;
	r = nb.c_r;
	i = nb.c_i;
	while (nb.n < m->pr.i && (nb.z_r * nb.z_r + nb.z_i * nb.z_i < 4))
	{
		tmp = nb.z_r * nb.z_r - nb.z_i * nb.z_i;
		if (!m->pr.fr || m->pr.fr == 2)
			nb.z_i = 2 * nb.z_r * nb.z_i + i;
		if (m->pr.fr == 1)
			nb.z_i = -2 * fabs(nb.z_r * nb.z_i) + nb.c_i;
		nb.z_r = tmp + r;
		if (m->pr.fr == 2)
		{
			r = r / 2 + nb.z_r;
			i = i / 2 + nb.z_i;
		}
		nb.n++;
	}
	drawpxl(nb.x, nb.y, m, nb);
}

void	julia(t_mlx *m, t_nb nb)
{
	double	tmp;

	nb.n = 0;
	while (nb.n < m->pr.i && (nb.z_r * nb.z_r + nb.z_i * nb.z_i < 4))
	{
		if (m->pr.fr == 3 || m->pr.fr == 4)
			tmp = nb.z_r * nb.z_r - nb.z_i * nb.z_i;
		else
			tmp = nb.z_r * nb.z_r * nb.z_r - 3 * nb.z_r * nb.z_i * nb.z_i;
		if (m->pr.fr == 3)
			nb.z_i = 2 * nb.z_r * nb.z_i + m->pr.j_i;
		else if (m->pr.fr == 4)
			nb.z_i = -2 * fabs(nb.z_r * nb.z_i) + m->pr.j_i;
		else if (m->pr.fr == 5)
			nb.z_i = 3 * nb.z_r * nb.z_r * nb.z_i - nb.z_i * nb.z_i *\
						nb.z_i + m->pr.j_i;
		nb.z_r = tmp + m->pr.j_r;
		nb.n++;
	}
	drawpxl(nb.x, nb.y, m, nb);
}

void	biom(t_mlx *m, t_nb nb)
{
	double	tmp;

	nb.n = 0;
	while (nb.n < m->pr.i && (nb.z_r * nb.z_r < 50) && (nb.z_i * nb.z_i < 50))
	{
		if (m->pr.fr == 7)
		{
			tmp = 3 * nb.z_r * nb.z_r * nb.z_i - nb.z_i * nb.z_i * nb.z_i;
			nb.z_r = nb.z_r * nb.z_r * nb.z_r - 3 * nb.z_i * nb.z_i * nb.z_r\
						+ m->pr.j_r;
		}
		else
		{
			tmp = 4 * nb.z_r * nb.z_r * nb.z_r * nb.z_i - 4 * nb.z_r * nb.z_i\
						* nb.z_i * nb.z_i;
			nb.z_r = nb.z_r * nb.z_r * nb.z_r * nb.z_r + nb.z_i * nb.z_i *\
						nb.z_i * nb.z_i - 6 * nb.z_r * nb.z_r * nb.z_i *\
						nb.z_i + m->pr.j_r;
		}
		nb.z_i = tmp + m->pr.j_i;
		nb.n++;
	}
	drawpxl(nb.x, nb.y, m, nb);
}

void	newton(t_mlx *m, t_nb nb)
{
	double	p;
	t_nb	t;

	nb.n = 0;
	p = 1.0;
	while (nb.n < m->pr.i && p > 0.000001)
	{
		t = nb;
		p = (t.z_r * t.z_r + t.z_i * t.z_i) * (t.z_r * t.z_r + t.z_i * t.z_i);
		nb.z_r = (2 * nb.z_r * p + nb.z_r * nb.z_r - nb.z_i * nb.z_i) / (3 * p);
		nb.z_i = (2 * nb.z_i * (p - t.z_r)) / (3 * p);
		p = (nb.z_r - t.z_r) * (nb.z_r - t.z_r) + (nb.z_i - t.z_i) *\
				(nb.z_i - t.z_i);
		nb.n++;
	}
	drawpxl(nb.x, nb.y, m, nb);
}
