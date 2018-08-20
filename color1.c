/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 10:57:19 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/20 17:14:37 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			dark(t_fract *fract, int i)
{
	double	v;
	double	t;
	double	a;
	double	b;
	double	d;

	a = 0.5;
	b = 0.5;
	d = 0.49;
	t = (double)i / (double)fract->max_itter;
	v = a + b * cos(2.0 * M_PI * (t + d));
	return (hsv2rgb(0, 0, v));
}

int			lsd1(t_z *z, int i)
{
	double	h;
	double	mu;

	mu = (double)(i + 1) - log2(log(z->mod));
	h = 0.95 + 20.0 * mu;
	if (h > 360)
		h = (int)h % 360;
	if (h < 0)
		h = 360 - (int)-h % 360;
	return (hsv2rgb(h, 0.9, 1));
}

int			lsd2(t_fract *fract, t_z *z, int i)
{
	double	h;
	double	t;
	double	mu;

	mu = (double)(i + 1) - log2(log(z->mod));
	t = (double)i / (double)fract->max_itter;
	h = fabs(cos(mu)) * 360;
	return (hsv2rgb(h, t, 1));
}

int			red(t_fract *fract, int i)
{
	double	t;

	t = (double)i / (double)fract->max_itter;
	return (hsv2rgb(359, 1, t));
}
