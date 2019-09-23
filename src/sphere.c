/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 16:44:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:25:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "shape.h"
#include <stdbool.h>
#include <ft_printf.h>

static t_vec3	ray_function(const t_ray *ray, double t)
{
	const t_vec3	dir_vec = vec3_multi(&ray->direction, t);

	return (vec3_add(&ray->origin, &dir_vec));
}

static t_vec3	calc_normal(const t_vec3 *p, const t_vec3 *origin)
{
	const t_vec3	unnorm = vec3_sub(p, origin);

	return (vec3_normalized(&unnorm));
}

bool			sphere_intersect(
	const t_shape *shape, const t_ray *ray, t_intersection *isect)
{
	const t_sphere *sphere = &shape->value.sphere;
	t_vec3 local_ray;
	double tca;
	double d2;
	double thc;
	double t0;
	double t1;
	double t;

	local_ray = vec3_sub(&sphere->origin, &ray->origin);
	tca = vec3_dot(&local_ray, &ray->direction);
	if (tca < 0.0)
		return (false);
	d2 = vec3_length2(&local_ray) - tca * tca;
	if (d2 > sphere->radius * sphere->radius)
		return (false);
	thc = sqrt(sphere->radius * sphere->radius - d2);
	t0 = tca - thc;
	t1 = tca + thc;
	if (t0 < 0.0 && t1 < 0.0)
		return (false);
	if (t0 < 0.0)
		t = t1;
	else if (t1 < 0.0)
		t = t0;
	else
		t = t0 < t1 ? t0 : t1;
	if (t <= 0.0)
		return (false);
	if (t <= isect->t)
	{
		isect->t = t;
		isect->p = ray_function(ray, t);
		isect->normal = calc_normal(&isect->p, &sphere->origin);
		return (true);
	}
	return (false);
}
