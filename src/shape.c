/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 16:36:33 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/28 17:50:09 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "shape.h"

bool			shape_intersect(
	const t_shape *shape, const t_ray *ray, t_intersection *isect)
{
	static t_instersection_function fn_lookup_table[] = {
		sphere_intersect,
		plane_intersect,
	};

	return (fn_lookup_table[shape->type](shape, ray, isect));
}

bool			shape_does_intersect(
	const t_shape *shape, const t_ray *ray)
{
	t_intersection	dummy;

	dummy.t = INFINITY;
	return (shape_intersect(shape, ray, &dummy));
}
