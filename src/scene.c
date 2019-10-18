/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 16:10:45 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/18 18:35:41 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "app.h"
#include "color.h"

void			*crash_alloc(size_t len)
{
	void *ptr;

	ptr = malloc(len);
	if (!ptr)
		exit(EXIT_FAILURE);
	return (ptr);
}

void			make_objects(t_scene *scene)
{
	t_object	*my_object;

	my_object = (t_object*)crash_alloc(sizeof(t_object));
	my_object->material = make_material(RED, 0.2, 0.8);
	my_object->shape = make_sphere(0.0, 5.0, 8.0, 5.0);
	container_push_object(&scene->objects.root, my_object);
	my_object = (t_object*)crash_alloc(sizeof(t_object));
	my_object->material = make_material((t_vec3){180.0, 180.0, 0.0}, 0.2, 0.8);
	my_object->shape = make_cone((t_vec3){10.0, 5.0, 10.0}, 10.0, 5.0);
	container_push_object(&scene->objects.root, my_object);
	my_object = (t_object*)crash_alloc(sizeof(t_object));
	my_object->material = make_material(GREEN, 0.2, 0.8);
	my_object->shape = make_cylinder(-10.0, 5.0, 10.0, 5.0);
	my_object->shape.value.cylinder.rot.z += M_PI_4;
	container_push_object(&scene->objects.root, my_object);
	my_object = (t_object*)crash_alloc(sizeof(t_object));
	my_object->material = make_material(WHITE, 0.2, 0.8);
	my_object->shape =
		make_plane((t_vec3){0.0, 0.0, 0.0}, (t_vec3){0.0, 1.0, 0.0});
	container_push_object(&scene->objects.root, my_object);
}

void			my_scene_make(t_scene *scene)
{
	scene->camera = (t_camera){
		.origin = (t_vec3) { 0.0, 5.0, -10.0 },
		.rotation = (t_vec3) { 0.0, 0.0, 0.0 },
		.fov = 70.0,
	};
	scene->lights.root = NULL;
	scene->objects.root = NULL;
	camera_recompute(&scene->camera);
	make_objects(scene);
	lights_push_light(&scene->lights.root, (t_light){
		.position = (t_vec3){10.0, 10.0, -5.0}, .brightness = 1.0, });
}

void			scene_update(t_scene *scene, t_keystate *ks)
{
	const double speed = is_key_down(ks, SDL_SCANCODE_LSHIFT) ? 5.0 : 1.0;

	if (is_key_down(ks, SDL_SCANCODE_A))
		camera_move(&scene->camera, (t_vec3){-speed, 0.0, 0.0});
	if (is_key_down(ks, SDL_SCANCODE_D))
		camera_move(&scene->camera, (t_vec3){speed, 0.0, 0.0});
	if (is_key_down(ks, SDL_SCANCODE_W))
		camera_move(&scene->camera, (t_vec3){0.0, 0.0, -speed});
	if (is_key_down(ks, SDL_SCANCODE_S))
		camera_move(&scene->camera, (t_vec3){0.0, 0.0, speed});
	if (is_key_down(ks, SDL_SCANCODE_Q))
		camera_move(&scene->camera, (t_vec3){0.0, -speed, 0.0});
	if (is_key_down(ks, SDL_SCANCODE_E))
		camera_move(&scene->camera, (t_vec3){0.0, speed, 0.0});
	if (is_key_down(ks, SDL_SCANCODE_LEFT))
		scene->camera.rotation.y -= 0.05 * speed;
	if (is_key_down(ks, SDL_SCANCODE_RIGHT))
		scene->camera.rotation.y += 0.05 * speed;
	if (is_key_down(ks, SDL_SCANCODE_UP))
		scene->camera.rotation.x -= 0.05 * speed;
	if (is_key_down(ks, SDL_SCANCODE_DOWN))
		scene->camera.rotation.x += 0.05 * speed;
}

void			scene_free(t_scene **scene)
{
	container_free((*scene)->objects.root);
	lights_free((*scene)->lights.root);
	free(*scene);
	*scene = NULL;
}
