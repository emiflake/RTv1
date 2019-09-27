/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 17:43:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/27 13:42:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "camera.h"
#include "vec2.h"
#include "ray.h"

void	camera_move(t_camera *camera, const t_vec3 delta)
{
	camera->origin.x +=
		cos(camera->rotation.y) * delta.x - sin(camera->rotation.y) * delta.z;
	camera->origin.y += delta.y;
	camera->origin.z +=
		-cos(camera->rotation.y) * delta.z - sin(camera->rotation.y) * delta.x;
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

	vec3_rotx(&direction, camera->rotation.x);
	vec3_roty(&direction, camera->rotation.y);
	vec3_normalize(&direction);
	ray->direction = direction;
	ray->level = 5;
	ray->origin = camera->origin;
}

void			camera_recompute(t_camera *camera)
{
	camera->t_f = tan(camera->fov / 2.0 * M_PI / 180.0);
}
