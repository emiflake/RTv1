/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 15:56:22 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/28 15:56:24 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "shape.h"

static double	t_calc(const t_plane *plane, const t_ray *ray)
{
	const t_vec3 ray_self = vec3_sub(&plane->origin, &ray->origin);

	return (vec3_dot(&ray_self, &plane->normal)
		/ vec3_dot(&plane->normal, &ray->direction));
}

static t_vec3	ray_function(const t_ray *ray, double t)
{
	const t_vec3	dir_vec = vec3_multi(&ray->direction, t);

	return (vec3_add(&ray->origin, &dir_vec));
}

bool			plane_intersect(
	const struct s_shape *shape, const t_ray *ray, t_intersection *isect)
{
	const t_plane	*plane = &shape->value.plane;
	const double	t = t_calc(plane, ray);

	if (t < 0.001)
		return (false);
	if (t < isect->t)
	{
		isect->t = t;
		isect->normal = plane->normal;
		isect->p = ray_function(ray, t);
		return (true);
	}
	return (false);
}
