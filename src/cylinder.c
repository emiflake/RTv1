/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/18 14:54:09 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/18 17:10:39 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "shapes.h"

static t_vec3	ray_function(const t_ray *ray, double t)
{
	const t_vec3	dir_vec = vec3_multi(&ray->direction, t);

	return (vec3_add(&ray->origin, &dir_vec));
}

static t_vec3	calc_normal(const t_vec3 *p, const t_vec3 *origin)
{
	const t_vec3	smol_origin = (t_vec3){origin->x, p->y, origin->z};
	const t_vec3	unnorm = vec3_sub(p, &smol_origin);

	return (vec3_normalized(&unnorm));
}

bool			cylinder_intersect(
	const struct s_shape *shape, const t_ray *ray, t_intersection *isect)
{
	t_cylinder_f	f;

	f.cylinder = &shape->value.cylinder;
	f.rot_dir = vec3_rotxyzk(&ray->direction, &f.cylinder->rot);
	f.rot_orig = vec3_rotxyzk(&ray->origin, &f.cylinder->rot);
	f.p0 = vec3_sub(&f.rot_orig, &f.cylinder->origin);
	f.a = pow(f.rot_dir.x, 2) + pow(f.rot_dir.z, 2);
	f.b = f.rot_dir.x * f.p0.x + f.rot_dir.z * f.p0.z;
	f.c = f.p0.x * f.p0.x + f.p0.z * f.p0.z - pow(f.cylinder->r, 2);
	f.disc = f.b * f.b - f.a * f.c;
	if (f.disc < 0.00001)
		return (false);
	f.t = (-f.b - sqrt(f.disc)) / f.a;
	if (f.t <= 0.00001)
		return (false);
	if (f.t < isect->t)
	{
		isect->t = f.t;
		isect->p = ray_function(ray, f.t);
		isect->normal = calc_normal(&isect->p, &f.cylinder->origin);
		return (true);
	}
	return (false);
}

t_shape			make_cylinder(double x, double y, double z, double r)
{
	return ((t_shape){
		.type = CYLINDER,
		.value = (t_shape_value){.cylinder = (t_cylinder){
			.origin = (t_vec3) { x, y, z },
			.r = r,
			.rot = (t_vec3){0.0, 0.0, 0.0}
		}},
	});
}
