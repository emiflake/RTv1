/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:28:40 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/16 15:48:18 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "shape.h"
# include "material.h"

typedef struct	s_object
{
	t_shape		shape;
	t_material	material;
}				t_object;

t_shape			make_sphere(double x, double y, double z, double r);
t_shape			make_plane(t_vec3 pos, t_vec3 normal);

#endif
