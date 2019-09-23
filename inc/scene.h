/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 15:09:46 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:39:38 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <SDL2/SDL.h>
# include "camera.h"
# include "object_container.h"
# include "keystate.h"

struct s_app;

typedef struct	s_scene
{
	t_camera			camera;
	t_object_container	*objects;
	// void				*lights;
}				t_scene;

void			scene_render_to_surface(
	const t_scene *scene, SDL_Surface *surface);


void			my_scene_make(t_scene *scene);

void			scene_update(t_scene *scene, t_keystate *ks);

#endif
