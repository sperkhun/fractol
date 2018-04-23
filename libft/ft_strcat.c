/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:54:39 by sperkhun          #+#    #+#             */
/*   Updated: 2017/11/05 17:10:22 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;

	i = ft_strlen(s1);
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
	return (s1);
}
