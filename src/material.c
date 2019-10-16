/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 15:44:47 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/16 17:43:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

t_material		make_material(t_vec3 albedo, double a, double d)
{
	return ((t_material) {
		.albedo = albedo,
		.ambient = a,
		.diffuse = d,
	});
}
