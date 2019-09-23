/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:28:40 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 15:40:12 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "shape.h"

typedef struct	s_object
{
	t_shape	shape;
	/* TODO: add material description */
}				t_object;

#endif
