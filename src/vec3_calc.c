/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_calc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:18:50 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 17:55:29 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_normalized(const t_vec3 *a)
{
	double l;

	l = vec3_length(a);
	return ((t_vec3){a->x / l, a->y / l, a->z / l});
}

void	vec3_normalize(t_vec3 *v)
{
	double l;

	l = vec3_length(v);
	v->x /= l;
	v->y /= l;
	v->z /= l;
}

t_vec3	vec3_copy(const t_vec3 *a)
{
	return ((t_vec3){a->x, a->y, a->z});
}

t_vec3	vec3_scale(const t_vec3 *a, double nb)
{
	return ((t_vec3){a->x / nb, a->y / nb, a->z / nb});
}

t_vec3	vec3_multi(const t_vec3 *a, double mag)
{
	return ((t_vec3){a->x * mag, a->y * mag, a->z * mag});
}
