/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 14:34:28 by aspizhav          #+#    #+#             */
/*   Updated: 2019/01/29 18:35:29 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_mlx		*create_win(void)
{
	t_mlx	*win;

	win = (t_mlx*)malloc(sizeof(t_mlx));
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "Fractol");
	return (win);
}

t_image		*create_image(t_mlx *win)
{
	t_image	*image;

	image = (t_image*)malloc(sizeof(t_image));
	image->bpp = 0;
	image->sl = 0;
	image->end = 0;
	image->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	image->pstr = DATA_ADR(image->img, &image->bpp, &image->sl, &image->end);
	return (image);
}

t_paint		*create_painter(t_lim lim)
{
	t_paint	*paint;
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	x = 0;
	paint = (t_paint*)malloc(sizeof(t_paint) * (ALL + 1));
	while (y < HEIGHT)
	{
		if (x == WIDTH)
			y++;
		if (x == WIDTH)
			x = 0;
		paint[i].y = y;
		paint[i].x = x;
		i++;
		x++;
	}
	image_and_real(lim, paint);
	return (paint);
}

t_lim		*create_lim(int flg)
{
	t_lim	*limit;

	limit = (t_lim*)malloc(sizeof(t_lim) + 1);
	if (flg == 1)
	{
		limit->rmax = 0.5;
		limit->rmin = -2;
		limit->imax = 1.25;
		limit->imin = -1.25;
	}
	else
	{
		limit->rmax = 2.25;
		limit->rmin = -2.25;
		limit->imax = 2;
		limit->imin = -2;
	}
	limit->re_rmax = limit->rmax;
	limit->re_rmin = limit->rmin;
	limit->re_imax = limit->imax;
	limit->re_imin = limit->imin;
	return (limit);
}

void		respect(t_fractol fractol)
{
	fractol.lim->rmax = fractol.lim->re_rmax;
	fractol.lim->rmin = fractol.lim->re_rmin;
	fractol.lim->imax = fractol.lim->re_imax;
	fractol.lim->imin = fractol.lim->re_imin;
	image_and_real(*fractol.lim, fractol.paint);
	fill(fractol);
}
