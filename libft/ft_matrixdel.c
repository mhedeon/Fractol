/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:45:40 by mhedeon           #+#    #+#             */
/*   Updated: 2018/04/17 19:45:40 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_matrixdel(void **mat, size_t height)
{
	size_t	i;

	i = 0;
	if (!mat || !height)
		return ;
	while (i < height)
	{
		free(*(mat + i));
		i++;
	}
	free(mat);
}
