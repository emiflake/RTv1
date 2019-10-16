/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light_container.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 16:54:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/16 18:54:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

#include <ft_printf.h>
#include <stdlib.h>

t_light_container	*lights_make(void)
{
	t_light_container	*container;

	container = (t_light_container*)malloc(sizeof(t_light_container));
	if (!container)
		return (NULL);
	container->root = NULL;
	return (container);
}

void				lights_push_light(t_light_node **node, t_light light)
{
	t_light_node	*new_node;

	new_node = (t_light_node*)malloc(sizeof(t_light_node));
	if (!new_node)
	{
		ft_printf("Could not allocate memory for\
			pushing of light to container\n");
		exit(EXIT_FAILURE);
	}
	new_node->light = light;
	new_node->next = *node;
	*node = new_node;
}

t_vec3				light_contribution_at(
	const t_scene *scene, const t_intersection *isect, const t_ray *ray)
{
	t_light_container_f	f;

	f.diff_contribution = (t_vec3){0, 0, 0};
	f.curr_node = scene->lights.root;
	while (f.curr_node)
	{
		f.light_dir = vec3_sub(&f.curr_node->light.position, &isect->p);
		vec3_normalize(&f.light_dir);
		f.amount = vec3_dot(&isect->normal, &f.light_dir);
		f.amount = f.amount > 0.0 ? f.amount : 0.0;
		f.curr_diffuse = vec3_multi(&isect->object->material.albedo,
			f.amount * f.curr_node->light.brightness);
		f.bias = vec3_multi(&isect->normal, 0.001);
		f.shadow_ray = (t_ray){ .origin = vec3_add(&isect->p, &f.bias),
			.direction = f.light_dir, .level = ray->level - 1 };
		f.shisect.t = INFINITY;
		if (!container_intersect(&scene->objects, &f.shadow_ray, &f.shisect)
	|| f.shisect.t > vec3_distance(&isect->p, &f.curr_node->light.position))
			vec3_add_mut(&f.diff_contribution, &f.curr_diffuse);
		f.curr_node = f.curr_node->next;
	}
	f.diff_contribution = vec3_clamp_as_color(f.diff_contribution);
	f.diff_contribution = vec3_multi(&f.diff_contribution,
		isect->object->material.diffuse);
	return (f.diff_contribution);
}

void				lights_free(
	t_light_node *node)
{
	if (!node)
		return ;
	lights_free(node->next);
	free(node);
}
