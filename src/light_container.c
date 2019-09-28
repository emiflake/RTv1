/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light_container.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 16:54:18 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/28 17:49:39 by nmartins      ########   odam.nl         */
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

static void			push_node(t_light_node **node, t_light light)
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

void				lights_push_light(
	t_light_container *container, t_light light)
{
	push_node(&container->root, light);
}

t_vec3				light_contribution_at(
	const t_scene *scene, const t_intersection *isect, const t_ray *ray)
{
	t_vec3			contribution;
	t_light_node	*curr_node;
	t_vec3			light_dir;
	t_vec3			curr_diffuse;
	double			amount;
	t_vec3			bias;
	t_ray			shadow_ray;

	(void)ray;
	contribution = (t_vec3){0,0,0};
	curr_node = scene->lights->root;
	while (curr_node)
	{
		light_dir = vec3_sub(&curr_node->light.position, &isect->p);
		vec3_normalize(&light_dir);
		amount = vec3_dot(&isect->normal, &light_dir);
		amount = amount > 0.0 ? amount : 0.0;
		curr_diffuse = vec3_multi(&isect->object->material.albedo, amount);
		bias = vec3_multi(&isect->normal, 0.001);
		shadow_ray = (t_ray){ .origin = vec3_add(&isect->p, &bias),
			.direction = light_dir, .level = ray->level - 1 };
		if (!container_does_intersect(scene->objects, &shadow_ray))
			vec3_add_mut(&contribution, &curr_diffuse);
		contribution.x = contribution.x > 255 ? 255 : contribution.x;
		contribution.y = contribution.y > 255 ? 255 : contribution.y;
		contribution.z = contribution.z > 255 ? 255 : contribution.z;
		curr_node = curr_node->next;
	}
	return (vec3_multi(&contribution, isect->object->material.diffuse));
}
