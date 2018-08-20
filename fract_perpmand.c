/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_perpmand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 20:26:47 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/20 17:13:40 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_perpmand(t_mlx *mlx, t_fract *fract)
{
	fract->min_re = -1.9;
	fract->max_re = 1.5;
	fract->min_im = -1.1;
	fract->max_im = fract->min_im + (fract->max_re -
					fract->min_re) * WIN_HEIGHT / WIN_WIDTH;
	fract->ds_re = fract->max_re - fract->min_re;
	fract->ds_im = fract->max_im - fract->min_im;
	fract->delta_re = fract->ds_re;
	fract->delta_im = fract->ds_im;
	fract->j_re = 0;
	fract->j_im = 0;
	fract->j_move = 0;
	fract->max_itter = 60;
	fract->color = 5;
	mlx->help = -1;
	good_zoom(fract, 0.8, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}

static int		p_itter(t_fract *fract, t_z *z)
{
	int			i;
	double		tmp_re;
	double		tmp_im;

	z->z_re = 0;
	z->z_im = 0;
	i = -1;
	while (++i < fract->max_itter)
	{
		tmp_re = z->z_re;
		tmp_im = z->z_im;
		z->z_re = tmp_re * tmp_re - tmp_im * tmp_im + z->c_re;
		z->z_im = fabs(tmp_re) * tmp_im * -2.0 + z->c_im;
		z->mod = z->z_re * z->z_re + z->z_im * z->z_im;
		if (z->mod > 4.0)
			return (color(fract, z, i));
	}
	return (0);
}

static void		perpmand(t_mlx *mlx)
{
	int			x;
	int			y;
	int			start;
	t_z			z;

	start = mlx->start;
	y = start - 1;
	while (++y < WIN_HEIGHT / THREADS + start)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			z.c_re = mlx->fract->min_re + x * (mlx->fract->max_re -
						mlx->fract->min_re) / (WIN_WIDTH - 1);
			z.c_im = mlx->fract->max_im - y * (mlx->fract->max_im -
						mlx->fract->min_im) / (WIN_HEIGHT - 1);
			*(int *)(mlx->img->img + x * mlx->img->bits + y * mlx->img->size) =
					p_itter(mlx->fract, &z);
		}
	}
}

void			draw_perpmand(t_mlx *mlx)
{
	t_mlx		c_mlx[THREADS];
	pthread_t	thread[THREADS];
	int			i;

	i = -1;
	while (++i < THREADS)
	{
		c_mlx[i] = *mlx;
		c_mlx[i].start = i * WIN_HEIGHT / THREADS;
		pthread_create(&thread[i], NULL,
						(void *)&perpmand, (void *)&c_mlx[i]);
	}
	while (--i > -1)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr,
							mlx->win_ptr, mlx->img->img_ptr, 0, 0);
	if (mlx->help > 0)
		help(mlx);
}
