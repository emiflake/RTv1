/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_rot.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:19:39 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 19:10:31 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_rotx(t_vec3 *a, double nb)
{
	return ((t_vec3){
		a->x,
		a->y * cos(nb) - a->z * sin(nb),
		a->y * sin(nb) + a->z * cos(nb)
	});
}

void	vec3_roty(t_vec3 *a, double nb)
{
	const t_vec3 new_vec = ((t_vec3){
		a->x * cos(nb) + a->z * sin(nb),
		a->y,
		a->z * cos(nb) - a->x * sin(nb)
	});
	a->x = new_vec.x;
	a->z = new_vec.z;
}

t_vec3	vec_rotz(t_vec3 *a, double nb)
{
	return ((t_vec3){
		a->x * cos(nb) - a->y * sin(nb),
		a->x * sin(nb) - a->y * cos(nb),
		a->z
	});
}
