/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:36:13 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/26 19:03:42 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			add_powz(long double a, long double b, t_env *e)
{
	e->zr2 = a * a;
	e->zi2 = b * b;
	return (e->zr2 + e->zi2);
}

static void	it_julia_ter(t_env *e)
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

void		julia_ter(t_env *e)
{
	e->x = 0;
	if (e->zoom == 200)
	{
		e->x1 = -1.6;
		e->y1 = -1.3;
	}
	while (e->x < e->w)
	{
		e->y = 0;
		while (e->y < e->h)
		{
			e->zr = e->x / e->zoom + e->x1;
			e->zi = e->y / e->zoom + e->y1;
			e->cr = -0.835;
			e->ci = -0.2321;
			it_julia_ter(e);
			e->y++;
		}
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
