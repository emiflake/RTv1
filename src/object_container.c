/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_container.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 16:19:02 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/16 18:54:35 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "object_container.h"

void				container_push_object(t_object_node **node, t_object *obj)
{
	t_object_node	*new_node;

	new_node = (t_object_node*)malloc(sizeof(t_object_node));
	if (!new_node)
	{
		ft_printf("Could not allocate memory\
		for pushing of object to object_container\n");
		exit(EXIT_FAILURE);
	}
	new_node->object = obj;
	new_node->next = *node;
	*node = new_node;
}

bool				container_does_intersect(
	const t_object_container *container,
	const t_ray *ray)
{
	t_object_node	*curr_node;

	curr_node = container->root;
	while (curr_node)
	{
		if (shape_does_intersect(&curr_node->object->shape, ray))
			return (true);
		curr_node = curr_node->next;
	}
	return (false);
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
		{
			isect->object = curr_node->object;
			found_intersection = true;
		}
		curr_node = curr_node->next;
	}
	return (found_intersection);
}

void				container_free(
	t_object_node *node)
{
	if (!node)
		return ;
	container_free(node->next);
	free(node->object);
	free(node);
}
