/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light_container.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 16:51:19 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/16 18:47:18 by nmartins      ########   odam.nl         */
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
	double	brightness;
}					t_light;

typedef struct		s_light_node
{
	t_light					light;
	struct s_light_node		*next;
}					t_light_node;

typedef struct		s_light_container
{
	t_light_node *root;
}					t_light_container;

typedef struct		s_light_container_f
{
	t_vec3			diff_contribution;
	t_vec3			light_dir;
	t_vec3			curr_diffuse;
	t_vec3			bias;
	t_light_node	*curr_node;
	double			amount;
	t_ray			shadow_ray;
	t_intersection	shisect;
}					t_light_container_f;

t_light_container	*lights_make(void);
void				lights_push_light(t_light_node **node, t_light light);
void				lights_free(t_light_node *node);
#endif
