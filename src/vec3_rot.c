/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_rot.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:19:39 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/18 17:07:31 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void	vec3_rotx(t_vec3 *a, double nb)
{
	t_vec3 new_vec;

	new_vec = ((t_vec3){
		a->x,
		a->y * cos(nb) - a->z * sin(nb),
		a->y * sin(nb) + a->z * cos(nb)
	});
	a->y = new_vec.y;
	a->z = new_vec.z;
}

void	vec3_roty(t_vec3 *a, double nb)
{
	t_vec3 new_vec;

	new_vec = ((t_vec3){
		a->x * cos(nb) + a->z * sin(nb),
		a->y,
		a->z * cos(nb) - a->x * sin(nb)
	});
	a->x = new_vec.x;
	a->z = new_vec.z;
}

t_vec3	vec3_rotxyzk(const t_vec3 *a, const t_vec3 *r)
{
	t_vec3	res;

	if (r->x == 0 && r->y == 0 && r->z == 0)
		return (*a);
	res = *a;
	if (r->x != 0)
		vec3_rotx(&res, r->x);
	if (r->y != 0)
		vec3_roty(&res, r->y);
	if (r->z != 0)
		vec3_rotz(&res, r->z);
	return (res);
}

t_vec3	vec3_rotxk(const t_vec3 *a, double nb)
{
	return ((t_vec3){
		a->x,
		a->y * cos(nb) - a->z * sin(nb),
		a->y * sin(nb) + a->z * cos(nb)
	});
}

void	vec3_rotz(t_vec3 *a, double nb)
{
	t_vec3 new_vec;

	new_vec = ((t_vec3){
		a->x * cos(nb) - a->y * sin(nb),
		a->x * sin(nb) - a->y * cos(nb),
		a->z
	});
	a->x = new_vec.x;
	a->y = new_vec.y;
}
