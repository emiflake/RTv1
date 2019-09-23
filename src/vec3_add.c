/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_add.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:17:03 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 16:55:19 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_add(const t_vec3 *a, const t_vec3 *b)
{
	return ((t_vec3){a->x + b->x, a->y + b->y, a->z + b->z});
}

t_vec3	vec3_sub(const t_vec3 *a, const t_vec3 *b)
{
	return ((t_vec3){a->x - b->x, a->y - b->y, a->z - b->z});
}

double	vec3_dot(const t_vec3 *a, const t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec3	vec3_cross(const t_vec3 *a, const t_vec3 *b)
{
	return ((t_vec3){a->y * b->z - a->z * b->y,\
	a->z * b->x - b->z * a->x, a->x * b->y - b->x * a->y});
}
