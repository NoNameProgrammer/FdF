/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_par.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:28:16 by sasajj            #+#    #+#             */
/*   Updated: 2020/02/23 13:28:17 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(t_fdf *a, t_fdf *b, t_fdf *param)
{
	a->x *= param->zoom;
	a->y *= param->zoom;
	b->x *= param->zoom;
	b->y *= param->zoom;
	a->z *= param->z_zoom;
	b->z *= param->z_zoom;
	if (param->zoom < 1)
		param->zoom = 1;
}

void	set_param(t_fdf *a, t_fdf *b, t_fdf *param)
{
	zoom(a, b, param);
	if (param->is_isometric)
	{
		isometric(a, param->angle);
		isometric(b, param->angle);
	}
	a->x += param->shift_x;
	a->y += param->shift_y;
	b->x += param->shift_x;
	b->y += param->shift_y;
}
