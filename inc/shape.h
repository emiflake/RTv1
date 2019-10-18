/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:31:06 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/18 17:18:25 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include <stdbool.h>

# include "ray.h"
# include "intersection.h"
# include "shapes.h"

typedef union	u_shape_value {
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
	t_cone		cone;
}				t_shape_value;

typedef struct	s_shape
{
	enum {
		SPHERE,
		PLANE,
		CYLINDER,
		CONE,
	}				type;
	t_shape_value	value;
}				t_shape;

bool			shape_does_intersect(
	const t_shape *shape, const t_ray *ray);
bool			shape_intersect(
	const t_shape *shape, const t_ray *ray, t_intersection *isect);

#endif
