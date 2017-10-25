/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemotion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:05:28 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/25 20:05:30 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		mouse_motion(int mx, int my, t_env *e)
{
	if (mx < 0 || mx >= e->w || my < 0 || my >= e->h)
		return (0);
	if (e->f == &julia && e->onoff == 1)
	{
		e->mouse_x = mx;
		e->mouse_y = my;
	}
	mlx_clear_window(e->mlx, e->win);
	e->f(e);
	return (1);
}
