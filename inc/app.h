/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   app.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: emiflake <marvin@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 15:19:52 by emiflake       #+#    #+#                */
/*   Updated: 2019/09/23 18:29:58 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include <SDL2/SDL.h>
# include <stdlib.h>
# include <stdbool.h>

# include "scene.h"
# include "keystate.h"

typedef struct	s_app
{
	size_t		width;
	size_t		height;

	bool		running;

	t_scene		*scene;

	SDL_Window	*window;
	SDL_Surface	*screen_surface;

	t_keystate	keystate;
}				t_app;

int				app_make(t_app *app, size_t width, size_t height);
int				app_run(t_app *app);

#endif
