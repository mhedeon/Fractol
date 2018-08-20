/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 23:20:32 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/20 17:15:04 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		toxic1(t_fract *fract, int i)
{
	double	h;
	double	t;

	t = (double)i / (double)fract->max_itter;
	h = (9.0 * (1.0 - t) * t * t * t * 255.0);
	h = h / 255 * 360;
	return (hsv2rgb(h, t, 1));
}

int		toxic2(t_fract *fract, int i)
{
	double	h;
	double	t;

	t = (double)i / (double)fract->max_itter;
	h = fabs(sin(t)) * 360;
	return (hsv2rgb(h, t, 1));
}

int		toxic3(t_fract *fract, int i)
{
	double	h;
	double	t;

	t = (double)i / (double)fract->max_itter;
	h = fabs(cos(t)) * 360;
	return (hsv2rgb(h, t, 1));
}

int		color(t_fract *fract, t_z *z, int i)
{
	if (fract->color == 0)
		return (dark(fract, i));
	else if (fract->color == 1)
		return (lsd1(z, i));
	else if (fract->color == 2)
		return (lsd2(fract, z, i));
	else if (fract->color == 3)
		return (red(fract, i));
	else if (fract->color == 4)
		return (toxic1(fract, i));
	else if (fract->color == 5)
		return (toxic2(fract, i));
	else if (fract->color == 6)
		return (toxic3(fract, i));
	return (0);
}
