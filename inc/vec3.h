/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:14:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/27 13:42:04 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

typedef struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

t_vec3			vec3_add(const t_vec3 *a, const t_vec3 *b);
t_vec3			vec3_sub(const t_vec3 *a, const t_vec3 *c);
double			vec3_dot(const t_vec3 *a, const t_vec3 *b);
t_vec3			vec3_cross(const t_vec3 *a, const t_vec3 *b);

double			vec3_length(const t_vec3 *a);
double			vec3_length2(const t_vec3 *a);

void			vec3_normalize(t_vec3 *a);
t_vec3			vec3_normalized(const t_vec3 *a);
t_vec3			vec3_copy(const t_vec3 *a);
t_vec3			vec3_scale(const t_vec3 *a, double nb);
t_vec3			vec3_multi(const t_vec3 *a, double mag);

void			vec3_rotx(t_vec3 *a, double nb);
void			vec3_roty(t_vec3 *a, double nb);
void			vec3_rotz(t_vec3 *a, double nb);

void			vec3_add_mut(t_vec3 *v, const t_vec3 *w);

#endif
