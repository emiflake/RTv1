/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:48:50 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:54:50 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stdlib.h>
# include "vec3.h"

typedef struct	s_ray
{
	t_vec3	origin;
	t_vec3	direction;

	size_t	level;
}				t_ray;

#endif
