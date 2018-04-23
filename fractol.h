/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:49:29 by sperkhun          #+#    #+#             */
/*   Updated: 2018/01/24 13:49:32 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>

# define WIN_SIZE_H 900

# define WIN_SIZE_W 1200

typedef struct		s_nb
{
	int				n;
	int				x;
	int				y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
}					t_nb;

typedef struct		s_par
{
	double			mnr;
	double			mxr;
	double			mni;
	double			mxi;
	double			j_r;
	double			j_i;
	int				fr;
	int				s;
	int				i;
}					t_par;

typedef struct		s_clr
{
	double			r_f;
	double			g_f;
	double			b_f;
	double			r_p;
	double			g_p;
	double			b_p;
	int				w;
	int				c;
	int				k;
}					t_clr;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl_img;
	int				bpp;
	int				s_line;
	int				ed;
	t_par			pr;
	t_clr			c;
	int				t;
	int				z;
	double			a;
	int				xmn;
	int				xmx;
	int				ymn;
	int				ymx;
	int				xxmx;
}					t_mlx;

typedef struct		s_thr
{
	t_mlx			m;
	t_mlx			*mt;
	pthread_t		*thr;
}					t_thr;

void				opnwin(t_mlx *m);
void				draw_image(t_thr *t);
void				putnames(t_thr *t);
void				drawlines(t_mlx *m, int s, int e);
void				drawpxl(int x, int y, t_mlx *m, t_nb nb);
int					key_hook(int key, t_thr *t);
int					exit_x(void *par);
int					mouse_hook(int but, int x, int y, t_thr *t);
int					mouse_mot(int x, int y, t_thr *t);
void				setnbs(t_mlx *m);
void				setxy(t_mlx *m);
void				setclr(t_mlx *m);
void				setprmt(t_mlx *m);
void				mandelbrot(t_mlx *m, t_nb nb);
void				julia(t_mlx *m, t_nb nb);
void				biom(t_mlx *m, t_nb nb);
void				newton(t_mlx *m, t_nb nb);
void				crthr(t_thr *t);

#endif
