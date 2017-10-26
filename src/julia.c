/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:34:47 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/26 19:00:58 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	it_julia(t_env *e)
{
	long double	tmp;

	e->i = 0;
	while (e->i < e->it && add_powz(e->zr, e->zi, e) < 4)
	{
		tmp = e->zr;
		e->zr = e->zr2 - e->zi2 - 0.8 + (0.6 / ((double)e->mouse_x / e->w));
		e->zi = 2 * e->zi * tmp + 0.27015 / ((double)e->mouse_y / e->h);
		e->i++;
	}
	pix_to_img(e);
}

void		julia(t_env *e)
{
	e->x = 0;
	while (e->x < e->w)
	{
		e->y = 0;
		while (e->y < e->h)
		{
			e->zr = e->x / e->zoom + e->x1;
			e->zi = e->y / e->zoom + e->y1;
			it_julia(e);
			e->y++;
		}
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

static void	it_julia_bis(t_env *e)
{
	long double	tmp;

	e->i = 0;
	while (e->i < e->it && add_powz(e->zr, e->zi, e) < 4)
	{
		tmp = e->zr;
		e->zr = (e->zr * e->zr) - (e->zi * e->zi) + e->cr;
		e->zi = 2 * e->zi * tmp + e->ci;
		e->i++;
	}
	pix_to_img(e);
}

void		julia_bis(t_env *e)
{
	e->x = 0;
	while (e->x < e->w)
	{
		e->y = 0;
		while (e->y < e->h)
		{
			e->zr = e->x / e->zoom + e->x1;
			e->zi = e->y / e->zoom + e->y1;
			e->cr = -0.038088;
			e->ci = 0.9754633;
			it_julia_bis(e);
			e->y++;
		}
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
