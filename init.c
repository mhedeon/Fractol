/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:12:34 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/16 18:31:58 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_mm(void)
{
	exit(1);
}

int		exit_win(void)
{
	return (1);
}

void	destroy_window(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
}

void	init_mm_window(t_mlx *mlx, t_img *img, char *win_name)
{
	int	a;
	int	b;

	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, MM_WIDTH, MM_HEIGHT, win_name);
	img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "main_menu.xpm", &a, &b);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img_ptr, 0, 0);
	mlx->img = img;
}

void	init_window(t_mlx *mlx, t_img *img, t_fract *fract, char *win_name)
{
	mlx->mlx_ptr = mlx_init();
	if (ft_strequ(win_name, "Help"))
	{
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
					HELP_WIDTH, HELP_HEIGHT, win_name);
		img = NULL;
	}
	else
	{
		mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
						WIN_WIDTH, WIN_HEIGHT, win_name);
		img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		img->img = mlx_get_data_addr(img->img_ptr,
						&img->bits, &img->size, &img->end);
		img->bits /= 8;
		mlx->fract = fract;
		mlx->win_name = win_name;
	}
	mlx->img = img;
}
