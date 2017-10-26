/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:34:19 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/26 19:13:32 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		init_env(t_env *e)
{
	e->onoff = 0;
	e->mouse_x = 114;
	e->mouse_y = 5;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->w, e->h, "Gracious Fract'ol");
	e->img = mlx_new_image(e->mlx, e->w, e->h);
	e->pix = mlx_get_data_addr(e->img, &(e->bpp), &(e->szline), &(e->endian));
	e->dx = 0.0;
	e->dy = 0.0;
}

void		init_mandelbrot(t_env *e)
{
	e->x1 = -2.1;
	e->y1 = -1.2;
	e->zoom = 200.0;
	e->it = 50;
	e->w = 540;
	e->h = 480;
	e->coef = 0.2;
}

void		init_julia(t_env *e)
{
	e->zr = 0;
	e->cr = 0;
	e->ci = 0;
	e->zoom = 200;
	e->zi = 0;
	e->w = 400;
	e->h = 480;
	e->x1 = -1;
	e->y1 = -1.2;
	e->it = 50;
	e->coef = 0.2;
}

void		init_julia_bis(t_env *e)
{
	e->zr = 0;
	e->cr = 0;
	e->ci = 0;
	e->zoom = 200;
	e->zi = 0;
	e->w = 650;
	e->h = 540;
	e->x1 = -1.5;
	e->y1 = -1.2;
	e->it = 50;
	e->coef = 0.2;
}

void		init_burningship(t_env *e)
{
	e->cr = 0;
	e->ci = 0;
	e->zr = 0;
	e->zi = 0;
	e->x1 = -1;
	e->y1 = -1;
	e->it = 50;
	e->coef = 0.2;
	e->zoom = 200;
	e->w = 400;
	e->h = 400;
}
