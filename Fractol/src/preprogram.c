/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprogram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 12:32:23 by aspizhav          #+#    #+#             */
/*   Updated: 2019/01/30 18:59:29 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	usage(void)
{
	ft_putstr("Usage ./fractol 1 || 2 || 3 || 4 || 5 || 6 || 7\n");
	ft_putstr("1 - Mandelbrot || 2 - Julia|| 3 - Burnship || 4 - Andy ||");
	ft_putstr("5 - Julia_Drug || 6 - Julia2 || 7 - Mand2 || 8 - Final\n");
	exit(1);
}

int		correct(int ac, char **av)
{
	int flg;

	flg = 0;
	if (ac == 1 || 0)
		usage();
	if (av[1][0] == '1')
		flg = 1;
	else if (av[1][0] == '2')
		flg = 2;
	else if (av[1][0] == '3')
		flg = 3;
	else if (av[1][0] == '4')
		flg = 4;
	else if (av[1][0] == '5')
		flg = 5;
	else if (av[1][0] == '6')
		flg = 6;
	else if (av[1][0] == '7')
		flg = 7;
	else if (av[1][0] == '8')
		flg = 8;
	else
		usage();
	return (flg);
}

int		which_one(t_fractol fract, int j)
{
	int		res;

	if (fract.flg == 1)
		res = mandelbrot(fract, j);
	if (fract.flg == 2)
		res = julia(fract, j);
	if (fract.flg == 3)
		res = burn_ship(fract, j);
	if (fract.flg == 4)
		res = andy(fract, j);
	if (fract.flg == 5)
		res = julia_drug(fract, j);
	if (fract.flg == 6)
		res = julia2(fract, j);
	if (fract.flg == 7)
		res = mand2(fract, j);
	if (fract.flg == 8)
		res = final(fract, j);
	return (res);
}

void	menu(void)
{
	ft_putstr("|-----------------\x1b[31;01m MENU \x1b[0m-----------------|\n");
	ft_putstr("| Use \033[1;32mUP || DOWN || LEFT || RIGHT\033[m to move|\n");
	ft_putstr("| Use keys \033[1;32m[1 - 7]\033[m to change color mode  |\n");
	ft_putstr("| Use 	\033[1;32m[+] & [-]\033[m - to iterate		 |\n");
	ft_putstr("| Use \033[1;32m[SPACE]\033[m to feel epilepsy 	  	 |\n");
	ft_putstr("| Use \x1b[33;01mNumeric Keyboard\x1b[m to switch Fractals|\n");
	ft_putstr("| Key	\033[1;32m[W]\033[m	and		\033[1;32m[S]\033[m	 |\n");
	ft_putstr("|      	 ↓   	  		 ↓	 |\n");
	ft_putstr("|    	STOP	 		RUN 	 |\n");
	ft_putstr("| 	Press \033[1;32m[F]\033[m to pay respect 	 |\n");
	ft_putstr("|----------------------------------------|\n");
}
