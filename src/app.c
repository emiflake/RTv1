/* ************************************************************************** */
/*                                                                            */
/*                                                             ::::::::       */
/*   app.c                                                   :+:    :+:       */
/*                                                          +:+               */
/*   By: emiflake <marvin@student.codam.nl>                +#+                */
/*                                                        +#+                 */
/*   Created: 2019/09/18 15:21:20 by emiflake            #+#    #+#           */
/*   Updated: 2019/09/18 15:41:39 by emiflake            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <ft_printf.h>

#include "app.h"

int	app_make(t_app *app, size_t width, size_t height)
{
	app->width = width;
	app->height = height;
	app->running = 1;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}
	ft_printf("Successfully initialized SDL with Video\n");
	app->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, app->width, app->height, SDL_WINDOW_SHOWN);
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
	return (0);
}

void	app_tick(t_app *app)
{
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
				app->running = 0;
		}
		app_tick(app);
	}
	return (0);
}
