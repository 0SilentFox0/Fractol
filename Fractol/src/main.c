/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:24:01 by aspizhav          #+#    #+#             */
/*   Updated: 2019/01/30 18:13:18 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		fract_change(t_fractol *fractol, int keycode)
{
	if (keycode == 83 || keycode == 84)
	{
		fractol->flg = (keycode == 83 ? 1 : 2);
		fill(*fractol);
	}
	if (keycode == 85 || keycode == 86)
	{
		fractol->flg = (keycode == 85 ? 3 : 4);
		fill(*fractol);
	}
	if (keycode == 87 || keycode == 88)
	{
		fractol->flg = (keycode == 87 ? 5 : 6);
		fill(*fractol);
	}
	if (keycode == 89 || keycode == 91)
	{
		fractol->flg = (keycode == 89 ? 7 : 8);
		fill(*fractol);
	}
}

int			ft_close(void)
{
	exit(1);
	return (0);
}

int			main(int ac, char **av)
{
	t_fractol	fractol;

	menu();
	fractol.flg = correct(ac, av);
	fractol.win = create_win();
	fractol.lim = create_lim(fractol.flg);
	fractol.paint = create_painter(*fractol.lim);
	fractol.color = 0x0F0F0F;
	fractol.depth = 40;
	fill(fractol);
	mlx_hook(fractol.win->win, 2, 5, key_hook, &fractol);
	mlx_mouse_hook(fractol.win->win, mouse_update, &fractol);
	mlx_hook(fractol.win->win, 17, 1L << 17, ft_close, &fractol);
	mlx_hook(fractol.win->win, 6, 0, mouse_julia, &fractol);
	mlx_loop(fractol.win->mlx);
	return (0);
}
