/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:41:38 by aspizhav          #+#    #+#             */
/*   Updated: 2019/01/30 13:00:14 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		julia2(t_fractol fractol, int i)
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
		tmp = (re * re) - (img * img);
		img = 2 * re * img + fractol.img_julia;
		re = tmp + fractol.real_julia;
		if ((re * re + img * img) > 4)
			break ;
		k++;
	}
	return (k);
}

int		mand2(t_fractol fractol, int i)
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
		tmp = fabs((re * re) - (img * img));
		img = 2 * img * re + fractol.paint[i].img;
		re = tmp + fractol.paint[i].re;
		if ((re * re + img * img) > 4)
			break ;
		k++;
	}
	return (k);
}

int		final(t_fractol fractol, int i)
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
		tmp = (re * re - (img * img * 3)) * re;
		img = ((re * re * 3) - img * img) * img + fractol.paint[i].img;
		re = tmp + fractol.paint[i].re;
		if ((re * re + img * img) > 4)
			break ;
		k++;
	}
	return (k);
}
