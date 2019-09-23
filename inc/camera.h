/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:12:51 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:55:33 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3.h"
# include "vec2.h"
# include "ray.h"

typedef struct	s_camera
{
	t_vec3	origin;
	t_vec3	rotation;

	double	fov;
	double	t_f;
}				t_camera;

void			camera_move(t_camera *camera, const t_vec3 delta);
void			camera_project_ray(
	const t_camera *camera, const t_vec2 *pos, const t_vec2 *dim, t_ray *ray);

void			camera_recompute(t_camera *camera);

#endif
