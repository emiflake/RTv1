/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:54:56 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/28 15:35:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include <stdbool.h>

# include "vec3.h"
# include "ray.h"
# include "intersection.h"

struct s_shape;

typedef bool(*t_instersection_function)(const struct s_shape *shape, const t_ray *ray, t_intersection *isect);
typedef struct	s_sphere
{
	t_vec3	origin;
	double	radius;
}				t_sphere;

bool			sphere_intersect(
	const struct s_shape *shape, const t_ray *ray, t_intersection *isect);

typedef struct	s_plane
{
	t_vec3	origin;
	t_vec3	normal;
}				t_plane;

bool			plane_intersect(
	const struct s_shape *shape, const t_ray *ray, t_intersection *isect);

#endif
