/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_rot.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:19:39 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/27 13:41:56 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void	vec3_rotx(t_vec3 *a, double nb)
{
	const t_vec3 new_vec = ((t_vec3){
		a->x,
		a->y * cos(nb) - a->z * sin(nb),
		a->y * sin(nb) + a->z * cos(nb)
	});
	a->y = new_vec.y;
	a->z = new_vec.z;
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

void	vec3_rotz(t_vec3 *a, double nb)
{
	const t_vec3 new_vec = ((t_vec3){
		a->x * cos(nb) - a->y * sin(nb),
		a->x * sin(nb) - a->y * cos(nb),
		a->z
	});
	a->x = new_vec.x;
	a->y = new_vec.y;
}
