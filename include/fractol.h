/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:36:27 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/26 18:51:19 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct		s_env
{
	int				mouse_x;
	int				mouse_y;
	long double		dx;
	long double		dy;
	long double		coef;
	int				i;
	int				it;
	long double		cr;
	long double		ci;
	long double		zr;
	long double		zi;
	long double		zr2;
	long double		zi2;
	long double		ix;
	long double		iy;
	long double		x1;
	long double		y1;
	int				onoff;
	void			*mlx;
	void			*win;
	void			*img;
	int				w;
	int				h;
	long double		zoom;
	long long		x;
	long long		y;
	char			*pix;
	int				bpp;
	int				szline;
	int				endian;
	int				c;
	void			(*f)(struct s_env *);
	void			(*init)(struct s_env *);
}					t_env;

int					mouse_motion(int mx, int my, t_env *e);
void				select_fractal(t_env *e, char *str);
int					key_hook(int kc, t_env *e);
void				pix_to_img(t_env *e);
void				julia(t_env *e);
void				julia_bis(t_env *e);
void				julia_ter(t_env *e);
void				init_julia(t_env *e);
void				init_julia_bis(t_env *e);
void				init_julia_ter(t_env *e);
void				burningship(t_env *e);
void				init_burningship(t_env *e);
void				select_fractal_se(t_env *e, char *str);
int					mouse_hook(int btn, int mx, int my, t_env *e);
void				mandelbrot(t_env *e);
int					add_powz(long double a, long double b, t_env *e);
void				init_mandelbrot(t_env *e);
void				init_env(t_env *e);
int					error(int ac, char **av);

#endif
