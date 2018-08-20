/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv2rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:56:24 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/16 17:06:44 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	choose1(t_hsv *hsv, t_rgb *rgb)
{
	if (hsv->hi == 3)
	{
		rgb->r = hsv->p * 255.0;
		rgb->g = hsv->q * 255.0;
		rgb->b = hsv->v * 255.0;
	}
	else if (hsv->hi == 4)
	{
		rgb->r = hsv->t * 255.0;
		rgb->g = hsv->p * 255.0;
		rgb->b = hsv->v * 255.0;
	}
	else if (hsv->hi == 5)
	{
		rgb->r = hsv->v * 255.0;
		rgb->g = hsv->p * 255.0;
		rgb->b = hsv->q * 255.0;
	}
}

static void	choose(t_hsv *hsv, t_rgb *rgb)
{
	if (hsv->hi == 0)
	{
		rgb->r = hsv->v * 255.0;
		rgb->g = hsv->t * 255.0;
		rgb->b = hsv->p * 255.0;
	}
	else if (hsv->hi == 1)
	{
		rgb->r = hsv->q * 255.0;
		rgb->g = hsv->v * 255.0;
		rgb->b = hsv->p * 255.0;
	}
	else if (hsv->hi == 2)
	{
		rgb->r = hsv->p * 255.0;
		rgb->g = hsv->v * 255.0;
		rgb->b = hsv->t * 255.0;
	}
	else
		choose1(hsv, rgb);
}

int			hsv2rgb(int h, double s, double v)
{
	t_hsv	hsv;
	t_rgb	rgb;
	double	f;

	hsv.h = hsv.h == 360 ? 0 : h / 60.0;
	hsv.hi = (int)trunc(hsv.h);
	hsv.s = s;
	hsv.v = v;
	if (hsv.s == 0)
	{
		rgb.r = hsv.v * 255;
		rgb.g = hsv.v * 255;
		rgb.b = hsv.v * 255;
	}
	else
	{
		f = (double)hsv.h - (double)hsv.hi;
		hsv.p = hsv.v * (1.0 - hsv.s);
		hsv.q = hsv.v * (1.0 - (hsv.s * f));
		hsv.t = hsv.v * (1.0 - (hsv.s * (1.0 - f)));
		choose(&hsv, &rgb);
	}
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}
