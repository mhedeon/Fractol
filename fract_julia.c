/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 16:21:35 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/16 18:46:24 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_julia(t_mlx *mlx, t_fract *fract)
{
	fract->min_re = -1.5;
	fract->max_re = 1.5;
	fract->min_im = -1.0;
	fract->max_im = fract->min_im + (fract->max_re -
					fract->min_re) * WIN_HEIGHT / WIN_WIDTH;
	fract->ds_re = fract->max_re - fract->min_re;
	fract->ds_im = fract->max_im - fract->min_im;
	fract->delta_re = fract->ds_re;
	fract->delta_im = fract->ds_im;
	fract->j_re = -0.586000;
	fract->j_im = 0.474000;
	fract->j_move = -1;
	fract->max_itter = 100;
	fract->color = 6;
	mlx->help = -1;
}

static int		j_itter(t_fract *fract, t_z *z, int x, int y)
{
	int			i;
	double		tmp_re;
	double		tmp_im;

	z->z_re = fract->min_re + x * (fract->max_re -
				fract->min_re) / (WIN_WIDTH - 1);
	z->z_im = fract->max_im - y * (fract->max_im -
				fract->min_im) / (WIN_HEIGHT - 1);
	i = -1;
	while (++i < fract->max_itter)
	{
		tmp_re = z->z_re;
		tmp_im = z->z_im;
		z->z_re = tmp_re * tmp_re - tmp_im * tmp_im + z->c_re;
		z->z_im = 2 * tmp_re * tmp_im + z->c_im;
		z->mod = z->z_re * z->z_re + z->z_im * z->z_im;
		if (z->mod > 4)
			return (color(fract, z, i));
	}
	return (0);
}

static void		julia(t_mlx *mlx)
{
	int			x;
	int			y;
	int			start;
	t_z			z;

	start = mlx->start;
	y = start - 1;
	z.c_re = mlx->fract->j_re;
	z.c_im = mlx->fract->j_im;
	while (++y < WIN_HEIGHT / THREADS + start)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			*(int *)(mlx->img->img + x * mlx->img->bits + y * mlx->img->size) =
					j_itter(mlx->fract, &z, x, y);
		}
	}
}

void			draw_julia(t_mlx *mlx)
{
	t_mlx		c_mlx[THREADS];
	pthread_t	thread[THREADS];
	int			i;

	i = -1;
	while (++i < THREADS)
	{
		c_mlx[i] = *mlx;
		c_mlx[i].start = i * WIN_HEIGHT / THREADS;
		pthread_create(&thread[i], NULL, (void *)&julia, (void *)&c_mlx[i]);
	}
	while (--i > -1)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr,
							mlx->win_ptr, mlx->img->img_ptr, 0, 0);
	if (mlx->help > 0)
		help(mlx);
}
