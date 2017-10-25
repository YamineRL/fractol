/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:35:02 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/25 22:24:04 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	select_fractal(t_env *e, char *str)
{
	if (ft_strcmp(str, "1") == 0)
	{
		e->init = &init_mandelbrot;
		e->f = &mandelbrot;
	}
	else if (ft_strcmp(str, "2") == 0)
	{
		e->init = &init_julia;
		e->f = &julia;
	}
	else if (ft_strcmp(str, "3") == 0)
	{
		e->init = &init_julia_bis;
		e->f = &julia_bis;
	}
	else if (ft_strcmp(str, "4") == 0)
	{
		e->init = &init_burningship;
		e->f = &burningship;
	}
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (error(ac, av) == 0)
	{
		ft_putstr_fd("usage: fractol [number]\n1 -> mandelbrot \n2 -> julia \n\
3 -> details julia\n4 -> burningship\n", 2);
		return (0);
	}
	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		return (0);
	select_fractal(e, av[1]);
	e->init(e);
	init_env(e);
	e->f(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_hook(e->win, 6, (1L << 6), mouse_motion, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_loop(e->mlx);
	free(e);
	return (0);
}
