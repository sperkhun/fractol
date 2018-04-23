/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:46:28 by sperkhun          #+#    #+#             */
/*   Updated: 2017/10/28 15:20:07 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb == 0 || nb == 2 || nb < 0)
		return (0);
	while (i * i < nb)
		i++;
	if (nb % i == 0)
		return (i);
	else
		return (0);
}