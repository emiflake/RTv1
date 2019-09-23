/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_mut.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 18:46:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:46:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

void			vec3_add_mut(t_vec3 *v, const t_vec3 *w)
{
	v->x += w->x;
	v->y += w->y;
	v->z += w->z;
}