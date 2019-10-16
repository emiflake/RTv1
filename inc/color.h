/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 19:16:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/16 15:43:33 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define RED ((t_vec3){255.0, 0.0, 0.0})
# define GREEN ((t_vec3){0.0, 255.0, 0.0})
# define BLUE ((t_vec3){0.0, 0.0, 255.0})
# define BLACK ((t_vec3){0.0, 0.0, 0.0})
# define WHITE ((t_vec3){255.0, 255.0, 255.0})

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

typedef struct	s_hsl
{
	double	h;
	double	s;
	double	l;
}				t_hsl;

typedef struct	s_gradient
{
	int start;
	int end;
}				t_gradient;

/*
** Convert RGB color to int32 color
*/
int				gfx_color(int r, int g, int b, int a);

t_rgb			gfx_hsl2rgb(t_hsl hsl);
t_hsl			gfx_rgb2hsl(t_rgb rgb);

int				gfx_color_from_rgb(t_rgb rgb);
t_rgb			rgb_clamp(const t_rgb rgb);

#endif
