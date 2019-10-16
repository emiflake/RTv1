/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_length.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 16:54:14 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/16 18:15:21 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_length2(const t_vec3 *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z);
}

double	vec3_length(const t_vec3 *a)
{
	return (sqrt(vec3_length2(a)));
}

double	vec3_distance(const t_vec3 *a, const t_vec3 *b)
{
	const t_vec3	delta = vec3_sub(b, a);

	return (vec3_length(&delta));
}
