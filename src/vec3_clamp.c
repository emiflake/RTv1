/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_clamp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 17:53:12 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/28 19:00:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_vec3	vec3_clamp_as_color(t_vec3 v)
{
	return ((t_vec3){
		.x = v.x > 255 ? 255 : v.x,
		.y = v.y > 255 ? 255 : v.y,
		.z = v.z > 255 ? 255 : v.z,
	});
}
