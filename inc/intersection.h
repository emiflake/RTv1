/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:41:02 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 15:47:37 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "vec3.h"

typedef struct	s_intersection
{
	double	t;
	t_vec3	p;
	t_vec3	normal;
}				t_intersection;

#endif
