/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_convert_to_complex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 17:23:20 by aspizhav          #+#    #+#             */
/*   Updated: 2019/01/30 18:10:52 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	coord_img(double y, t_lim lim)
{
	return (y * ((lim.imax - lim.imin) / WIDTH) + lim.imin);
}

double	coord_real(double x, t_lim lim)
{
	return (x * ((lim.rmax - lim.rmin) / WIDTH) + lim.rmin);
}

void	image_and_real(t_lim lim, t_paint *paint)
{
	int		i;

	i = -1;
	while (++i < ALL)
	{
		paint[i].img = coord_img(paint[i].y, lim);
		paint[i].re = coord_real(paint[i].x, lim);
	}
}

int		mouse_julia(int x, int y, t_fractol *fract)
{
	if ((fract->flg == 2 || fract->flg == 4 || fract->flg == 5
	|| fract->flg == 6) && fract->flag == 1)
	{
		fract->real_julia = coord_real(x, *fract->lim);
		fract->img_julia = coord_img(y, *fract->lim);
		fill(*fract);
	}
	return (1);
}
