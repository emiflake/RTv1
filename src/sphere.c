/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 16:44:57 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/18 18:25:59 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "shape.h"
#include <stdbool.h>

t_shape			make_sphere(double x, double y, double z, double r)
{
	return ((t_shape){
		.type = SPHERE,
		.value = (t_shape_value){.sphere = (t_sphere){
			.origin = (t_vec3) { x, y, z }, .radius = r, }},
	});
}

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

static bool		calc_new_intersection(
	double t, const t_ray *ray, t_intersection *isect, const t_sphere *sphere)
{
	isect->t = t;
	isect->p = ray_function(ray, t);
	isect->normal = calc_normal(&isect->p, &sphere->origin);
	return (true);
}

bool			sphere_intersect(
	const t_shape *shape, const t_ray *ray, t_intersection *isect)
{
	const t_sphere	*sphere = &shape->value.sphere;
	const t_vec3	local_sphere = vec3_sub(&ray->origin, &sphere->origin);
	t_vec3			mul_loc;
	t_sphere_f		f;

	mul_loc = vec3_multi(&local_sphere, 2.0);
	f.b = vec3_dot(&mul_loc, &ray->direction);
	f.c = vec3_dot(&local_sphere, &local_sphere)
		- (sphere->radius * sphere->radius);
	f.disc = f.b * f.b - 4 * f.c;
	if (f.disc < 0.0)
		return (false);
	else
		f.disc = sqrt(f.disc);
	f.t0 = -f.b + f.disc;
	f.t1 = -f.b - f.disc;
	if (f.t1 > 0.0 || f.t0 > 0.0)
		f.t = (f.t1 > 0.0 ? f.t1 : f.t0) / 2.0;
	else
		return (false);
	if (f.t <= isect->t && f.t > 0)
		return (calc_new_intersection(f.t, ray, isect, sphere));
	return (false);
}
