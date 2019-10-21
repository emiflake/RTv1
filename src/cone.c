/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cone.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/18 17:22:31 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/21 15:16:20 by nmartins      ########   odam.nl         */
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

void			define_abc(t_cone_f *f)
{
	f->a = f->co->cas * pow(f->rd.x, 2)
		+ f->co->cas * pow(f->rd.z, 2)
		- f->co->sas * pow(f->rd.y, 2);
	f->b = f->co->cas * f->rd.x * f->p0.x
		+ f->co->cas * f->rd.z * f->p0.z
		- f->co->sas * f->rd.y * f->p0.y;
	f->c = f->co->cas * f->p0.x * f->p0.x
		+ f->co->cas * f->p0.z * f->p0.z
		- f->co->sas * f->p0.y * f->p0.y;
}

bool			cone_intersect(
	const struct s_shape *shape, const t_ray *ray, t_intersection *isect)
{
	t_cone_f	f;

	f.co = &shape->value.cone;
	f.rd = vec3_rotxyzk(&ray->direction, &f.co->rot);
	f.rot_orig = vec3_rotxyzk(&ray->origin, &f.co->rot);
	f.p0 = vec3_sub(&f.rot_orig, &f.co->origin);
	define_abc(&f);
	f.delta = f.b * f.b - f.a * f.c;
	if (f.delta < 0.0001)
		return (false);
	f.t = (-f.b - sqrt(f.delta)) / f.a;
	if (f.t < 0.00001)
		return (false);
	f.y = f.p0.y + f.t * f.rd.y;
	if (f.t > 0.00001 && f.t < isect->t)
	{
		isect->t = f.t;
		isect->p = ray_function(ray, f.t);
		isect->normal = calc_normal(&isect->p, f.co);
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
			.cas = h / d,
			.sas = r / d,
		}},
	});
}
