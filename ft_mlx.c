/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:13:46 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/03 18:13:47 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	opnwin(t_mlx *m)
{
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIN_SIZE_W, WIN_SIZE_H, "Fract'ol");
	if (!m->mlx || !m->win)
	{
		perror("Error");
		exit(1);
	}
}

void	draw_image(t_thr *t)
{
	if (!(t->m.img = mlx_new_image(t->m.mlx, t->m.xxmx, t->m.ymx)))
	{
		perror("Error");
		exit(1);
	}
	t->m.pxl_img = mlx_get_data_addr(t->m.img, &(t->m.bpp), \
										&(t->m.s_line), &(t->m.ed));
	t->m.bpp /= 8;
	crthr(t);
	mlx_put_image_to_window(t->m.mlx, t->m.win, t->m.img, t->m.xmn, t->m.ymn);
	mlx_destroy_image(t->m.mlx, t->m.img);
}

void	putnames(t_thr *t)
{
	int c;

	c = t->m.c.k == 4 ? 0xFFFFFF : 0;
	mlx_string_put(t->m.mlx, t->m.win, 20, 250, c, "Mandelbrot");
	mlx_string_put(t->m.mlx, t->m.win, 420, 250, c, "Burning Ship");
	mlx_string_put(t->m.mlx, t->m.win, 820, 250, c, "Spider");
	mlx_string_put(t->m.mlx, t->m.win, 20, 550, c, "Julia");
	mlx_string_put(t->m.mlx, t->m.win, 420, 550, c, "Julia abs form.");
	mlx_string_put(t->m.mlx, t->m.win, 820, 550, c, "Julia cube form.");
	mlx_string_put(t->m.mlx, t->m.win, 23, 855, c, "Newton");
	mlx_string_put(t->m.mlx, t->m.win, 430, 870, c, "Biomorph ^3");
	mlx_string_put(t->m.mlx, t->m.win, 820, 850, c, "Biomorph ^4");
}
