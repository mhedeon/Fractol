/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_burnship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 21:28:14 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/20 17:30:23 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			init_burnship(t_mlx *mlx, t_fract *fract)
{
	fract->min_re = -3;
	fract->max_re = 1.5;
	fract->min_im = -1.0;
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
	fract->color = 3;
	mlx->help = -1;
}

static int		b_itter(t_fract *fract, t_z *z)
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
		z->z_im = -2 * fabs(tmp_re * tmp_im) + z->c_im;
		z->mod = z->z_re * z->z_re + z->z_im * z->z_im;
		if (z->mod > 4)
			return (color(fract, z, i));
	}
	return (0);
}

static void		burnship(t_mlx *mlx)
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
					b_itter(mlx->fract, &z);
		}
	}
}

void			draw_burnship(t_mlx *mlx)
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
						(void *)&burnship, (void *)&c_mlx[i]);
	}
	while (--i > -1)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
							mlx->img->img_ptr, 0, 0);
	if (mlx->help > 0)
		help(mlx);
}
