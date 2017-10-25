/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:35:37 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/25 20:01:11 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	it_mandelbrot(t_env *e)
{
	long double	tmp;

	e->i = 0;
	while (add_powz(e->zr, e->zi, e) < 4.0 && e->i < e->it)
	{
		tmp = e->zr;
		e->zr = e->zr2 - e->zi2 + e->cr;
		e->zi = 2 * e->zi * tmp + e->ci;
		e->i++;
	}
	pix_to_img(e);
}

void		mandelbrot(t_env *e)
{
	e->x = 0;
	while (e->x < e->w)
	{
		e->y = 0;
		while (e->y < e->h)
		{
			e->cr = (double)e->x / e->zoom + e->x1;
			e->ci = (double)e->y / e->zoom + e->y1;
			e->zr = 0;
			e->zi = 0;
			it_mandelbrot(e);
			e->y++;
		}
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
