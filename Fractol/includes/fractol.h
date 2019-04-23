/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <aspizhav@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:32:46 by aspizhav          #+#    #+#             */
/*   Updated: 2019/01/30 18:51:58 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# define IMG_WIN mlx_put_image_to_window
# define DATA_ADR mlx_get_data_addr
# define STR mlx_string_put
# define WIDTH 800
# define HEIGHT 800
# define ALL (WIDTH * HEIGHT)

typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
}					t_mlx;

typedef struct		s_image
{
	void		*img;
	int			end;
	int			sl;
	int			bpp;
	char		*pstr;
}					t_image;

typedef struct		s_paint
{
	double		x;
	double		y;
	double		re;
	double		img;
	int			red;
	int			blue;
	int			green;
}					t_paint;

typedef	struct		s_lim
{
	double		rmax;
	double		rmin;
	double		imax;
	double		imin;
	double		re_rmax;
	double		re_rmin;
	double		re_imax;
	double		re_imin;
}					t_lim;

typedef struct		s_fractol
{
	t_mlx		*win;
	t_image		*img;
	t_paint		*paint;
	t_lim		*lim;
	double		real_julia;
	double		img_julia;
	int			flag;
	int			flg;
	int			color;
	int			depth;
}					t_fractol;

t_lim				*create_lim(int flg);
t_mlx				*create_win(void);
t_image				*create_image(t_mlx *win);
t_paint				*create_painter(t_lim lim);
double				coord_img(double y, t_lim lim);
double				coord_real(double x, t_lim lim);
void				menu(void);
void				move(int keycode, t_fractol fractol);
void				color_fill(t_fractol fractol, int color, int i);
void				draw_pixel(t_paint	*paint, t_image *img, int i);
void				zoom_mouse(int keycode, int x, int y, t_fractol fractol);
void				drawer(t_fractol fract);
void				fill(t_fractol fractol);
void				image_and_real(t_lim lim, t_paint *paint);
void				change_color(t_fractol *fractol, int keycode);
void				respect(t_fractol fractol);
void				fract_change(t_fractol *fractol, int keycode);
int					mouse_update(int keycode, int x, int y, t_fractol *fractol);
int					key_hook(int keycode, t_fractol *fractol);
int					ft_close(void);
int					correct(int ac, char **av);
int					mouse_julia(int x, int y, t_fractol *fract);
int					julia_drug(t_fractol fractol, int i);
int					burn_ship(t_fractol fract, int j);
int					andy(t_fractol fractol, int i);
int					julia(t_fractol fractol, int i);
int					mandelbrot(t_fractol fractol, int i);
int					julia2(t_fractol fractol, int i);
int					mand2(t_fractol fractol, int i);
int					which_one(t_fractol fract, int j);
int					final(t_fractol fractol, int i);
#endif
