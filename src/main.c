/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:04:51 by sasajj            #+#    #+#             */
/*   Updated: 2020/02/23 16:08:59 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_program(t_fdf **data)
{
	mlx_destroy_window(data[0][0].mlx_ptr, data[0][0].win_ptr);
	free(data);
	exit(0);
}

void	shift_image(int key, t_fdf **data)
{
	if (key == 126)
		data[0][0].shift_y -= 10;
	else if (key == 125)
		data[0][0].shift_y += 10;
	else if (key == 124)
		data[0][0].shift_x += 10;
	else if (key == 123)
		data[0][0].shift_x -= 10;
}

int		deal_key(int key, t_fdf **data)
{
	if (key == 126 || key == 125 || key == 124 || key == 123)
		shift_image(key, data);
	else if (key == 24 || key == 69)
		data[0][0].zoom += 1;
	else if (key == 84 || key == 19)
		data[0][0].z_zoom -= 1;
	else if (key == 88)
		data[0][0].angle += 0.06;
	else if (key == 86)
		data[0][0].angle -= 0.06;
	else if (key == 91 || key == 28)
		data[0][0].z_zoom += 1;
	else if (key == 27 || key == 78)
		data[0][0].zoom -= 1;
	else if (key == 49 || key == 87 || key == 23)
		data[0][0].is_isometric = (data[0][0].is_isometric) ? 0 : 1;
	if (key == '5')
		exit_program(data);
	mlx_clear_window(data[0][0].mlx_ptr, data[0][0].win_ptr);
	print_menu(*data);
	draw(data);
	return (0);
}

void	set_default(t_fdf *param)
{
	param->zoom = 20;
	param->z_zoom = 1;
	param->is_isometric = 1;
	param->angle = 0.923599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr,
	param->win_x, param->win_y, "t_fdf");
}

int		main(int argc, char **argv)
{
	t_fdf **data;

	if (argc != 2)
	{
		ft_putstr("usage: t_fdf map.txt\n");
		return (0);
	}
	data = read_file(*++argv);
	if (&data[0][0] == NULL)
		ft_error("file is empty");
	set_default(&data[0][0]);
	draw(data);
	print_menu(*data);
	mlx_key_hook(data[0][0].win_ptr, deal_key, data);
	mlx_loop(data[0][0].mlx_ptr);
}
