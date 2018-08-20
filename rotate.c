/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 16:56:02 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/16 17:01:45 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		move_fract(int key, t_fract *fract)
{
	if (key == KEY_W)
	{
		fract->min_im += 0.1 * (fract->delta_re / fract->ds_re);
		fract->max_im += 0.1 * (fract->delta_re / fract->ds_re);
	}
	else if (key == KEY_S)
	{
		fract->min_im -= 0.1 * (fract->delta_re / fract->ds_re);
		fract->max_im -= 0.1 * (fract->delta_re / fract->ds_re);
	}
	else if (key == KEY_A)
	{
		fract->min_re -= 0.1 * (fract->delta_im / fract->ds_im);
		fract->max_re -= 0.1 * (fract->delta_im / fract->ds_im);
	}
	else if (key == KEY_D)
	{
		fract->min_re += 0.1 * (fract->delta_im / fract->ds_im);
		fract->max_re += 0.1 * (fract->delta_im / fract->ds_im);
	}
}

int			j_mouse_change(int x, int y, t_mlx *mlx)
{
	t_fract	*fract;

	fract = mlx->fract;
	if (fract->j_move > 0)
	{
		fract->j_re = (double)x / WIN_WIDTH *
						(fract->max_re - fract->min_re) + fract->min_re;
		fract->j_im = (double)y / WIN_HEIGHT *
						(fract->max_im - fract->min_im) + fract->min_im;
		ft_bzero((void *)mlx->img->img, mlx->img->size * WIN_HEIGHT);
		draw_fract(mlx);
	}
	return (1);
}

double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void		good_zoom(t_fract *fract, double zoom, int x, int y)
{
	double interpolation;

	interpolation = 1.0 / zoom;
	fract->mouse_re = (double)x / WIN_WIDTH *
						(fract->max_re - fract->min_re) + fract->min_re;
	fract->mouse_im = (double)y / WIN_HEIGHT *
						(fract->max_im - fract->min_im) + fract->min_im;
	fract->min_re = interpolate(fract->mouse_re, fract->min_re, interpolation);
	fract->min_im = interpolate(fract->mouse_im, fract->min_im, interpolation);
	fract->max_re = interpolate(fract->mouse_re, fract->max_re, interpolation);
	fract->max_im = interpolate(fract->mouse_im, fract->max_im, interpolation);
}
