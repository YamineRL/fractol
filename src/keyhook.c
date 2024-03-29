/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:58:00 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/26 18:00:55 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		key_hook(int kc, t_env *e)
{
	if (kc == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	if (kc == 125 || kc == 126)
	{
		e->y1 += (kc == 125) ? e->coef : 0 - e->coef;
		mlx_clear_window(e->mlx, e->win);
		e->f(e);
	}
	if (kc == 123 || kc == 124)
	{
		e->x1 += kc == 124 ? e->coef : 0 - e->coef;
		mlx_clear_window(e->mlx, e->win);
		e->f(e);
	}
	return (0);
}
