/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:57:49 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/26 18:44:07 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_hook(int btn, int mx, int my, t_env *e)
{
	if (btn == 4 || btn == 5)
	{
		if (e->zoom >= 10.0)
		{
			e->zoom = btn == 4 ? e->zoom * 1.2 : e->zoom / 1.2;
			e->x1 = btn == 4 ? e->x1 + ((mx / 5) / e->zoom) :
				e->x1 - (((mx / (5 * 1.2)) / e->zoom));
			e->y1 = btn == 4 ? e->y1 + ((my / 5) / e->zoom) :
				e->y1 - (((my / (5 * 1.2)) / e->zoom));
			e->coef = btn == 4 ? e->coef / 1.2 : e->coef * 1.2;
			e->it = btn == 4 ? e->it * 1.05 : e->it / 1.05;
			mlx_clear_window(e->mlx, e->win);
			e->f(e);
			if (e->it < 40)
				e->it = 50;
		}
		else
			e->zoom = 10.0;
	}
	if (btn == 1)
		e->onoff = e->onoff == 1 ? 0 : 1;
	return (0);
}
