/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:28:40 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/28 16:09:28 by nmartins      ########   odam.nl         */
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

#endif
