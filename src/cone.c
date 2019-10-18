/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cone.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/18 17:22:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/18 18:29:35 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "shapes.h"

static t_vec3	ray_function(const t_ray *ray, double t)
{
	const t_vec3	dir_vec = vec3_multi(&ray->direction, t);

	return (vec3_add(&ray->origin, &dir_vec));
}

static t_vec3	calc_normal(const t_vec3 *p, const t_cone *cone)
{
	t_vec3 v;
	t_vec3 n;

	v = vec3_sub(p, &cone->origin);
	v.y = 0;
	vec3_normalize(&v);
	n.x = v.x * cone->h / cone->r;
	n.z = v.z * cone->h / cone->r;
	n.y = cone->r / cone->h;
	return (n);
}

bool			cone_intersect(
	const struct s_shape *shape, const t_ray *ray, t_intersection *isect)
{
	const t_cone *cone = &shape->value.cone;
	const t_vec3 rot_dir = vec3_rotxyzk(&ray->direction, &cone->rot);
	const t_vec3 rot_orig = vec3_rotxyzk(&ray->origin, &cone->rot);
	const t_vec3 p0 = vec3_sub(&rot_orig, &cone->origin);
	const double a = cone->cos_alpha_sq*rot_dir.x*rot_dir.x+cone->cos_alpha_sq*rot_dir.z*rot_dir.z-cone->sin_alpha_sq*rot_dir.y*rot_dir.y;
	const double b = cone->cos_alpha_sq*rot_dir.x*p0.x +cone->cos_alpha_sq*rot_dir.z*p0.z-cone->sin_alpha_sq*rot_dir.y*p0.y;
	const double c = cone->cos_alpha_sq*p0.x*p0.x+cone->cos_alpha_sq*p0.z*p0.z-cone->sin_alpha_sq*p0.y*p0.y;
	const double delta = b * b - a * c;
	double t;
	double y;

	if (delta < 0.0001)
		return (false);
	t = (-b - sqrt (delta))/a;
	if (t < 0.00001)
		return (false);
	y = p0.y + t * rot_dir.y;
	// if (y < -cone->h - 0.00001)
	// 	return false;
	if (t <= 0.00001)
		return (false);
	if (t < isect->t)
	{
		isect->t = t;
		isect->p = ray_function(ray, t);
		isect->normal = calc_normal(&isect->p, cone);
		return (true);
	}
	return (false);
}

t_shape			make_cone(t_vec3 origin, double h, double r)
{
	const t_vec3 p1 = (t_vec3){origin.x + r, origin.y, origin.z};
	const t_vec3 p2 = (t_vec3){origin.x, origin.y + h, origin.z};
	const t_vec3 delta = vec3_sub(&p1, &p2);
	const double d = vec3_length(&delta);

	return ((t_shape){
		.type = CONE,
		.value = (t_shape_value){.cone = (t_cone){
			.origin = origin,
			.r = r,
			.h = h,
			.cos_alpha_sq = h / d,
			.sin_alpha_sq = r / d,
		}},
	});
}
