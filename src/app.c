/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: emiflake <marvin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 15:21:20 by emiflake       #+#    #+#                */
/*   Updated: 2019/09/26 20:14:48 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <ft_printf.h>
#include <libft.h>

#include "app.h"
#include "color.h"
#include "primitives.h"

int	app_make(t_app *app, size_t width, size_t height)
{
	app->width = width;
	app->height = height;
	app->running = true;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}
	ft_printf("Successfully initialized SDL with Video\n");
	app->window = SDL_CreateWindow(
		"RTv1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		app->width, app->height, SDL_WINDOW_SHOWN);
	if (!app->window)
	{
		ft_printf("Unable to create window: %s\n", SDL_GetError());
		return (1);
	}
	app->screen_surface = SDL_GetWindowSurface(app->window);
	if (!app->screen_surface)
	{
		ft_printf("Unable to get screen surface: %s\n", SDL_GetError());
		return (1);
	}
	app->scene = (t_scene*)malloc(sizeof(t_scene));
	if (!app->scene)
	{
		ft_printf("Unable to allocate scene\n");
		return (1);
	}
	ft_bzero(&app->keystate, sizeof(app->keystate));
	my_scene_make(app->scene);
	return (0);
}

void	app_tick(t_app *app)
{
	const t_vec2	dim = (t_vec2){(double)app->width, (double)app->height};
	t_vec2			pixel_pos;
	t_ray			ray;
	t_intersection	isect;

	scene_update(app->scene, &app->keystate);
	pixel_pos.y = 0;
	prim_clear(app->screen_surface, 0x000000);
	while (pixel_pos.y < app->height)
	{
		pixel_pos.x = 0;
		while (pixel_pos.x < app->width)
		{
			camera_project_ray(&app->scene->camera, &pixel_pos, &dim, &ray);
			isect.t = INFINITY;
			if (container_intersect(app->scene->objects, &ray, &isect))
			{
				prim_put_pixel(
					app->screen_surface, pixel_pos.x, pixel_pos.y,
						gfx_color_from_rgb(rgb_clamp((t_rgb){255.0 - isect.t * 10.0, 255.0 - isect.t * 10.0, 255.0 - isect.t * 10.0})));
			}
			pixel_pos.x++;
		}
		pixel_pos.y++;
	}
	SDL_UpdateWindowSurface(app->window);
}

int	app_run(t_app *app)
{
	SDL_Event evt;

	while (app->running)
	{
		while (SDL_PollEvent(&evt))
		{
			if (evt.type == SDL_QUIT)
				app->running = false;
			if (evt.type == SDL_KEYDOWN)
			{
				if (evt.key.keysym.sym == SDLK_ESCAPE)
					app->running = false;
				keystate_key_down(&app->keystate, evt.key.keysym.scancode);
			}
			if (evt.type == SDL_KEYUP)
				keystate_key_up(&app->keystate, evt.key.keysym.scancode);
		}
		app_tick(app);
	}
	return (0);
}
