/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:32:26 by aspizhav          #+#    #+#             */
/*   Updated: 2019/01/30 18:13:54 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 83 || keycode == 84 || keycode == 85 || keycode == 86
	|| keycode == 87 || keycode == 88 || keycode == 89 || keycode == 91)
		fract_change(fractol, keycode);
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
		fractol->flag = 0;
	if (keycode == 1)
		fractol->flag = 1;
	if ((keycode >= 18 && keycode <= 23) || keycode == 26 || keycode == 49)
		change_color(fractol, keycode);
	if (keycode == 3)
		respect(*fractol);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		move(keycode, *fractol);
	if (keycode == 69 || keycode == 78)
	{
		fractol->depth += (keycode == 69 ? 10 : -10);
		fill(*fractol);
	}
	return (1);
}

void	move(int keycode, t_fractol fractol)
{
	double	key;

	if (keycode == 123 || keycode == 124)
	{
		key = (keycode == 123 ? 0.01 : -0.01);
		fractol.lim->rmax = fractol.lim->rmax + key;
		fractol.lim->rmin = (fractol.lim->rmin + key);
	}
	if (keycode == 125 || keycode == 126)
	{
		key = (keycode == 125 ? -0.01 : 0.01);
		fractol.lim->imax = fractol.lim->imax + key;
		fractol.lim->imin = fractol.lim->imin + key;
	}
	image_and_real(*fractol.lim, fractol.paint);
	fill(fractol);
}

void	zoom_mouse(int keycode, int x, int y, t_fractol fractol)
{
	double	r;
	double	i;
	double	key;

	r = coord_real(x, *fractol.lim);
	i = coord_img(y, *fractol.lim);
	key = (keycode == 5 ? 1.1 : 0.9);
	fractol.lim->rmax = fractol.lim->rmax * key + r * (1 - key);
	fractol.lim->rmin = fractol.lim->rmin * key + r * (1 - key);
	fractol.lim->imax = fractol.lim->imax * key + i * (1 - key);
	fractol.lim->imin = fractol.lim->imin * key + i * (1 - key);
	image_and_real(*fractol.lim, fractol.paint);
	fill(fractol);
}

int		mouse_update(int keycode, int x, int y, t_fractol *fractol)
{
	if (keycode == 5 || keycode == 4)
		zoom_mouse(keycode, x, y, *fractol);
	return (1);
}

void	change_color(t_fractol *fractol, int keycode)
{
	if (keycode == 18)
		fractol->color = 0xea5804;
	if (keycode == 19)
		fractol->color = 0x002302;
	if (keycode == 20)
		fractol->color = 0x030023;
	if (keycode == 21)
		fractol->color = 0x230102;
	if (keycode == 22)
		fractol->color = 0x0F0F0F;
	if (keycode == 23)
		fractol->color = 0x0F0F00;
	if (keycode == 26)
		fractol->color = 0x00F0FF;
	if (keycode == 49)
		fractol->color += 250;
	fill(*fractol);
}
