/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhaddar <yhaddar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:34:36 by yhaddar           #+#    #+#             */
/*   Updated: 2017/10/26 19:33:05 by yhaddar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int			error(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (ft_strcmp(av[1], "1") != 0 && ft_strcmp(av[1], "2") != 0
			&& ft_strcmp(av[1], "3") != 0 && ft_strcmp(av[1], "4") != 0
			&& ft_strcmp(av[1], "5") != 0)
		return (0);
	return (1);
}
