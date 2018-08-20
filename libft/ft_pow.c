/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:19:08 by mhedeon           #+#    #+#             */
/*   Updated: 2018/04/17 16:19:08 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_pow(int x, int y)
{
	if (y < 0)
		return (0);
	if (y == 0)
		return (1);
	while (y > 0)
		return (x * ft_pow(x, y - 1));
	return (x);
}