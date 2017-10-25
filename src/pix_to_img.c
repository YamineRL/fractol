/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pix_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:58:37 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/25 21:47:00 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	color(t_env *e)
{
	int		r;
	int		g;
	int		b;

	if (e->i == e->it)
		e->c = 0x000000;
	else
	{
		r = e->i * 10;
		g = e->i * 10;
		b = e->i * 23;
		e->c = (r << 16) + (g << 8) + b;
	}
}

void		pix_to_img(t_env *e)
{
	int		i;

	i = (e->x * (e->bpp / 8)) + (e->y * e->szline);
	color(e);
	ft_memcpy(e->pix + i, &(e->c), 4);
}
