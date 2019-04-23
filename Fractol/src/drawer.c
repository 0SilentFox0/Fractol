/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 15:05:21 by aspizhav          #+#    #+#             */
/*   Updated: 2019/01/29 18:44:06 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color_fill(t_fractol fractol, int color, int i)
{
	int		red;
	int		green;
	int		blue;

	red = (color >> 16);
	green = (color >> 8);
	blue = color;
	fractol.paint[i].red = red;
	fractol.paint[i].green = green;
	fractol.paint[i].blue = blue;
}

void	draw_pixel(t_paint *paint, t_image *img, int i)
{
	int		color;

	if (paint[i].y >= 0 && paint[i].x >= 0)
		if (paint[i].y < WIDTH && paint[i].x < HEIGHT)
		{
			color = (int)paint[i].y * img->sl + (int)paint[i].x * 4;
			if (color < ALL * 4)
			{
				img->pstr[color] = paint[i].blue;
				img->pstr[color + 1] = paint[i].green;
				img->pstr[color + 2] = paint[i].red;
			}
		}
}

void	drawer(t_fractol fractol)
{
	int		i;

	i = 0;
	while (i < ALL)
	{
		draw_pixel(fractol.paint, fractol.img, i);
		i++;
	}
}

void	fill(t_fractol fract)
{
	int		i;
	int		j;
	char	*depth;

	i = 0;
	depth = ft_itoa(fract.depth);
	while (i < ALL)
	{
		j = which_one(fract, i);
		if (j < fract.depth)
			color_fill(fract, ((j + 1)) * fract.color, i);
		else
			color_fill(fract, 0, i);
		i++;
	}
	fract.img = create_image(fract.win);
	drawer(fract);
	IMG_WIN(fract.win->mlx, fract.win->win, fract.img->img, 0, 0);
	STR(fract.win->mlx, fract.win->win, 70, 10, 0x0516b2, depth);
	STR(fract.win->mlx, fract.win->win, 10, 10, 0x0516b2, "Depth  ");
	free(depth);
	free(fract.img);
}
