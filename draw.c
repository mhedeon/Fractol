/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:23:47 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/20 17:39:33 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

void		init_fract(t_mlx *mlx)
{
	if (ft_strequ(mlx->win_name, "Tricorn"))
		init_tricorn(mlx, mlx->fract);
	else if (ft_strequ(mlx->win_name, "Bocal"))
		init_bocal(mlx, mlx->fract);
	else if (ft_strequ(mlx->win_name, "Mushroom"))
		init_mushroom(mlx, mlx->fract);
	else if (ft_strequ(mlx->win_name, "Perpendicular Mandelbrot"))
		init_perpmand(mlx, mlx->fract);
	else if (ft_strequ(mlx->win_name, "Julia set"))
		init_julia(mlx, mlx->fract);
	else if (ft_strequ(mlx->win_name, "Mandelbrot set"))
		init_mandelbrot(mlx, mlx->fract);
	else if (ft_strequ(mlx->win_name, "Burning ship"))
		init_burnship(mlx, mlx->fract);
	else if (ft_strequ(mlx->win_name, "Black hole"))
		init_blackhole(mlx, mlx->fract);
	draw_fract(mlx);
}

void		draw_fract(t_mlx *mlx)
{
	mlx->fract->delta_re = mlx->fract->max_re - mlx->fract->min_re;
	mlx->fract->delta_im = mlx->fract->max_im - mlx->fract->min_im;
	if (ft_strequ(mlx->win_name, "Tricorn"))
		draw_tricorn(mlx);
	else if (ft_strequ(mlx->win_name, "Bocal"))
		draw_bocal(mlx);
	else if (ft_strequ(mlx->win_name, "Mushroom"))
		draw_mushroom(mlx);
	else if (ft_strequ(mlx->win_name, "Perpendicular Mandelbrot"))
		draw_perpmand(mlx);
	else if (ft_strequ(mlx->win_name, "Julia set"))
		draw_julia(mlx);
	else if (ft_strequ(mlx->win_name, "Mandelbrot set"))
		draw_mandelbrot(mlx);
	else if (ft_strequ(mlx->win_name, "Burning ship"))
		draw_burnship(mlx);
	else if (ft_strequ(mlx->win_name, "Black hole"))
		draw_blackhole(mlx);
}

void		window(char *win_name)
{
	t_mlx	mlx;
	t_img	img;
	t_fract	fract;

	init_window(&mlx, &img, &fract, win_name);
	init_fract(&mlx);
	mlx_hook(mlx.win_ptr, 6, 5, j_mouse_change, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, exit_win, NULL);
	mlx_key_hook(mlx.win_ptr, deal_key, &mlx);
	mlx_mouse_hook(mlx.win_ptr, deal_mouse, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

void		help(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
					30, 390, 0x00f900, "Move: W: A, S, D");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
					30, 420, 0x00f900, "Zoom: MOUSE WHEEL");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
					30, 450, 0x00f900, "Change color: ARROWS");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
					30, 480, 0x00f900, "Interactive mode: SPACE [on/off]");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
					30, 500, 0x00f900, "(for Julia and Black hole only)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr,
					30, 550, 0x00f900, "Exit: ESC");
}
