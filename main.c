/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 17:06:18 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/05 17:06:19 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	checkarg(int i, char *str)
{
	if (i == 1 || i > 3)
	{
		ft_putendl("usage : ./fractol [fractals]\nfractals :\n\
--> mandelbrot\n--> julia\n--> b_ship\n--> spider\n--> newton\n--> biomorph");
		exit(0);
	}
	if (!ft_strcmp("mandelbrot", str))
		return (0);
	else if (!ft_strcmp("b_ship", str))
		return (1);
	else if (!ft_strcmp("spider", str))
		return (2);
	else if (!ft_strcmp("julia", str))
		return (3);
	else if (!ft_strcmp("newton", str))
		return (6);
	else if (!ft_strcmp("biomorph", str))
		return (7);
	else
	{
		ft_putendl("usage : ./fractol [fractals]\nfractals :\n\
--> mandelbrot\n--> julia\n--> b_ship\n--> spider\n--> newton\n--> biomorph");
		exit(0);
	}
	return (0);
}

static void	put_controls(void)
{
	ft_putstr("              CONTROLS:\n\
	zoom_______________ mouse wheel | left/right button\n\
	move_______________ keys: up, down, left, right\n\
	change depth_______ keys: +, -\n\
	change fractal_____ key:  S\n\
	change color_______ key:  C\n\
	reset______________ key:  R\n\
	exit_______________ key:  ESC\n");
}

int			main(int argc, char **argv)
{
	t_thr	t;
	pid_t	pid;

	pid = 1;
	if (argc == 3)
		pid = fork();
	if (pid == 0)
		t.m.pr.fr = checkarg(argc, argv[2]);
	else
		t.m.pr.fr = checkarg(argc, argv[1]);
	put_controls();
	t.thr = (pthread_t*)malloc(sizeof(pthread_t) * 300);
	t.mt = (t_mlx*)malloc(sizeof(t_mlx) * 300);
	opnwin(&t.m);
	setprmt(&t.m);
	draw_image(&t);
	mlx_hook(t.m.win, 2, 5, key_hook, &t);
	mlx_mouse_hook(t.m.win, mouse_hook, &t);
	mlx_hook(t.m.win, 6, 5, mouse_mot, &t);
	mlx_hook(t.m.win, 17, 5, exit_x, &t);
	mlx_loop(t.m.mlx);
	return (0);
}
