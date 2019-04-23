/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:42:13 by aspizhav          #+#    #+#             */
/*   Updated: 2019/01/30 10:41:22 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mandelbrot(t_fractol fractol, int i)
{
	int		k;
	double	re;
	double	im;
	double	tmp;

	k = 0;
	re = 0;
	im = 0;
	while (k < fractol.depth)
	{
		tmp = (re * re) - (im * im);
		im = 2 * re * im + fractol.paint[i].img;
		re = tmp + fractol.paint[i].re;
		if ((re * re) + (im * im) > 4)
			break ;
		k++;
	}
	return (k);
}

int		burn_ship(t_fractol fractol, int i)
{
	int		k;
	double	re;
	double	img;
	double	tmp;

	k = 0;
	img = 0;
	re = 0;
	while (k < fractol.depth)
	{
		tmp = ((re * re) - (img * img));
		img = 2 * fabs(re * img) + fractol.paint[i].img;
		re = tmp + fractol.paint[i].re;
		if ((re * re + img * img) > 4)
			break ;
		k++;
	}
	return (k);
}

int		andy(t_fractol fractol, int i)
{
	int		k;
	double	re;
	double	img;
	double	tmp;

	k = 0;
	img = fractol.paint[i].img;
	re = fractol.paint[i].re;
	while (k < fractol.depth)
	{
		tmp = fabs((re * re) - (img * img));
		img = 2 * (re * img + fractol.img_julia);
		re = tmp + fractol.real_julia;
		if ((re * re + img * img) > 4)
			break ;
		k++;
	}
	return (k);
}

int		julia_drug(t_fractol fractol, int i)
{
	int		k;
	double	re;
	double	img;
	double	tmp;

	k = 0;
	img = cos(fractol.paint[i].img);
	re = sin(fractol.paint[i].re);
	while (k < fractol.depth)
	{
		tmp = fabs((re * re) - (img * img));
		img = 2 * re * img + fractol.img_julia;
		re = tmp + fractol.real_julia;
		if ((re * re + img * img) > 4)
			break ;
		k++;
	}
	return (k);
}

int		julia(t_fractol fractol, int i)
{
	int		k;
	double	re;
	double	img;
	double	tmp;

	k = 0;
	img = fractol.paint[i].img;
	re = fractol.paint[i].re;
	while (k < fractol.depth)
	{
		tmp = (re * re) - (img * img);
		img = 2 * re * img + fractol.img_julia;
		re = tmp + fractol.real_julia;
		if ((re * re + img * img) > 4)
			break ;
		k++;
	}
	return (k);
}
