/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_container.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 16:19:02 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:22:20 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "object_container.h"

t_object_container	*container_make()
{
	t_object_container	*container;

	container = (t_object_container*)malloc(sizeof(t_object_container));
	if (!container)
		return (NULL);
	container->root = NULL;
	return (container);
}

static void			push_node(t_object_node	**node, t_object *obj)
{
	t_object_node	*new_node;

	new_node = (t_object_node*)malloc(sizeof(t_object_node));
	if (!new_node)
	{
		ft_printf("Could not allocate memory for pushing of object to object_container\n");
		exit(EXIT_FAILURE);
	}
	new_node->object = obj;
	new_node->next = *node;
	*node = new_node;
}

void				container_push_object(
	t_object_container *container, t_object *obj)
{
	push_node(&container->root, obj);
}

bool				container_intersect(
	const t_object_container *container,
	const t_ray *ray,
	t_intersection *isect)
{
	t_object_node	*curr_node;
	bool			found_intersection;

	found_intersection = false;
	curr_node = container->root;
	while (curr_node != NULL)
	{
		if (shape_intersect(&curr_node->object->shape, ray, isect))
			found_intersection = true;
		curr_node = curr_node->next;
	}
	return (found_intersection);
}
