/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 16:06:53 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/16 17:43:22 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "vec3.h"
# include "color.h"

typedef struct	s_material
{
	t_vec3	albedo;

	double	ambient;
	double	diffuse;
}				t_material;

t_material		make_material(t_vec3 albedo, double	a, double d);

#endif
