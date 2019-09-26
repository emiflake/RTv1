/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 16:44:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/26 20:51:00 by nmartins      ########   odam.nl         */
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
	const t_vec3 local_sphere = vec3_sub(&ray->origin, &sphere->origin);
	t_vec3 mul_loc;
	double b;
	double c;
	double disc;
	double t0;
	double t1;
	double t;

	mul_loc = vec3_multi(&local_sphere, 2.0);
	b = vec3_dot(&mul_loc, &ray->direction);
	c = vec3_dot(&local_sphere, &local_sphere) - (sphere->radius * sphere->radius);
	disc = b * b - 4 * c;
	if (disc < 0.0)
		return (false);
	else
		disc = sqrt(disc);
	t0 = -b + disc;
	t1 = -b - disc;
	if (t1 > 0.0)
		t = t1 / 2.0;
	else if (t0 > 0.0)
		t = t0 / 2.0;
	else
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
