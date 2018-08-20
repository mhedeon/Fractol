/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:24:47 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/20 17:34:08 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_key_mm(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
	{
		destroy_window(mlx);
		exit_mm();
	}
	return (1);
}

int		deal_mouse_mm(int key, int x, int y)
{
	if (key == MOUSE_CLICK)
	{
		if ((x > 175 && x < 338) && (y > 251 && y < 314))
			window("Tricorn");
		else if ((x > 175 && x < 338) && (y > 337 && y < 399))
			window("Bocal");
		else if ((x > 175 && x < 338) && (y > 424 && y < 487))
			window("Mushroom");
		else if ((x > 175 && x < 338) && (y > 510 && y < 572))
			window("Perpendicular Mandelbrot");
		else if ((x > 461 && x < 624) && (y > 251 && y < 314))
			window("Julia set");
		else if ((x > 461 && x < 624) && (y > 337 && y < 399))
			window("Mandelbrot set");
		else if ((x > 461 && x < 624) && (y > 424 && y < 487))
			window("Burning ship");
		else if ((x > 461 && x < 624) && (y > 510 && y < 572))
			window("Black hole");
	}
	return (1);
}

int		deal_key(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
	{
		destroy_window(mlx);
		return (1);
	}
	if (key == KEY_PLUS)
		mlx->fract->max_itter += 100;
	else if (key == KEY_MINUS)
		mlx->fract->max_itter -= 100;
	else if (key == KEY_SPACE)
		mlx->fract->j_move *= -1;
	else if (key == KEY_H)
		mlx->help *= -1;
	else if (key == KEY_R)
		init_fract(mlx);
	else if (key == ARROW_RIGHT)
		mlx->fract->color = (mlx->fract->color + 1) % 7;
	else if (key == ARROW_LEFT)
		mlx->fract->color = mlx->fract->color == 0 ?
		6 : mlx->fract->color - 1;
	else
		move_fract(key, mlx->fract);
	ft_bzero((void *)mlx->img->img, mlx->img->size * WIN_HEIGHT);
	draw_fract(mlx);
	return (1);
}

int		deal_mouse(int key, int x, int y, t_mlx *mlx)
{
	if (key == WHEEL_DOWN)
	{
		mlx->fract->max_itter -= 1;
		good_zoom(mlx->fract, 0.93, x, WIN_HEIGHT - y);
	}
	else if (key == WHEEL_UP)
	{
		mlx->fract->max_itter += 1;
		good_zoom(mlx->fract, 1.07, x, WIN_HEIGHT - y);
	}
	ft_bzero((void *)mlx->img->img, mlx->img->size * WIN_HEIGHT);
	draw_fract(mlx);
	return (1);
}
