/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:09:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/16 18:40:52 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <SDL2/SDL.h>
# include "camera.h"
# include "object_container.h"
# include "light_container.h"
# include "keystate.h"

struct s_app;

typedef struct	s_scene
{
	t_camera			camera;
	t_object_container	objects;
	t_light_container	lights;
}				t_scene;

void			my_scene_make(t_scene *scene);

void			scene_update(t_scene *scene, t_keystate *ks);
void			scene_free(t_scene **scene);

t_vec3			light_contribution_at(
	const t_scene *scene, const t_intersection *isect, const t_ray *ray);

#endif
