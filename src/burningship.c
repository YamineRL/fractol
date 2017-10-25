/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:34:25 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/25 20:03:14 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	it_burningship(t_env *e)
{
	long double	tmp;

	e->i = 0;
	while (add_powz(e->zr, e->zi, e) < 4 && e->i < e->it)
	{
		tmp = e->zr;
		e->zr = e->zr2 - e->zi2 + e->cr;
		e->zi = 2 * fabsl(e->zi * tmp) + e->ci;
		e->i++;
	}
	pix_to_img(e);
}

void		burningship(t_env *e)
{
	e->x = 0;
	while (e->x < e->w)
	{
		e->y = 0;
		while (e->y < e->h)
		{
			e->cr = e->x / e->zoom + e->x1;
			e->ci = e->y / e->zoom + e->y1;
			e->zr = 0;
			e->zi = 0;
			it_burningship(e);
			e->y++;
		}
		e->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
