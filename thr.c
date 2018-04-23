/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:23:58 by sperkhun          #+#    #+#             */
/*   Updated: 2018/02/16 15:24:01 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*runthr(void *m)
{
	t_mlx	*d;
	int		s;
	int		e;
	int		i;

	d = (t_mlx*)m;
	i = d->ymx / 300;
	e = d->t * i + i - 1;
	s = e - i + 1;
	drawlines(d, s, e);
	return (NULL);
}

void		crthr(t_thr *t)
{
	int i;

	i = 0;
	while (i < 300)
	{
		t->m.t = i;
		t->mt[i] = t->m;
		pthread_create(&(t->thr[i]), NULL, runthr, &(t->mt[i]));
		i++;
	}
	i = 0;
	while (i < 300)
	{
		pthread_join(t->thr[i], NULL);
		i++;
	}
}
