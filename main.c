/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhedeon <mhedeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 16:08:38 by mhedeon           #+#    #+#             */
/*   Updated: 2018/08/16 17:23:47 by mhedeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(void)
{
	t_mlx	mlx;
	t_img	img;

	init_mm_window(&mlx, &img, "Main menu)))))");
	mlx_key_hook(mlx.win_ptr, deal_key_mm, &mlx);
	mlx_mouse_hook(mlx.win_ptr, deal_mouse_mm, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 17, exit_mm, NULL);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
