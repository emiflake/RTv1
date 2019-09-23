/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 17:43:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:55:47 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vec2.h"
#include "ray.h"

void	camera_move(t_camera *camera, const t_vec3 delta)
{
	vec3_add_mut(&camera->origin, &delta);
}

void	camera_project_ray(
	const t_camera *camera, const t_vec2 *pos, const t_vec2 *dim, t_ray *ray)
{
	const double	aspect_ratio = dim->x / dim->y;
	double			px;
	double			py;
	t_vec3			direction;

	px = (2.0 * (((double)pos->x + 0.5) / dim->x) - 1.0) * aspect_ratio * camera->t_f;
	py = (1.0 - 2.0 * ((double)pos->y + 0.5) / dim->y) * camera->t_f;
	direction = (t_vec3) { px, py, 1.0 };
	vec3_normalize(&direction);
	ray->direction = direction;
	ray->level = 5;
	ray->origin = camera->origin;
}

void			camera_recompute(t_camera *camera)
{
	camera->t_f = tan(camera->fov / 2.0 * M_PI / 180.0);
}
