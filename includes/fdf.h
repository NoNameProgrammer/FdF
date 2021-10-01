/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasajj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 13:45:55 by sasajj            #+#    #+#             */
/*   Updated: 2020/02/23 13:45:56 by sasajj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

typedef	struct
{
	float	x;
	float	y;
	float	z;
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		z_zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		is_last;
	double	angle;
	int		is_isometric;
	int		win_x;
	int		win_y;

	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;
t_fdf		**read_file(char *file_name);
void		draw(t_fdf **data);
int			get_dots_from_line(char *line, t_fdf **matrix_of_dots, int y);
void		print_menu(t_fdf *data);
void		isometric(t_fdf *dot, double angle);
void		set_param(t_fdf *a, t_fdf *b, t_fdf *param);
void		ft_error(char *message);

#endif
