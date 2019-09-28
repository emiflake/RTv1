/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light_container.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 16:51:19 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/28 17:40:51 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_CONTAINER_H
# define LIGHT_CONTAINER_H

# include "vec3.h"

struct s_scene;
struct s_intersection;
struct s_ray;

typedef struct		s_light
{
	t_vec3	position;
}					t_light;

typedef struct		s_light_node
{
	t_light					light;
	struct s_light_node		*next;
}					t_light_node;

typedef struct		s_light_container {
	t_light_node *root;
}					t_light_container;

t_light_container	*lights_make(void);
void				lights_push_light(
	t_light_container *container, t_light light);

#endif
