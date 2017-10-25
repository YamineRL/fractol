/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:36:13 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/25 19:57:26 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		add_powz(long double a, long double b, t_env *e)
{
	e->zr2 = a * a;
	e->zi2 = b * b;
	return (e->zr2 + e->zi2);
}
