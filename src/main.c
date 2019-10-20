/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 15:50:15 by nmartins       #+#    #+#                */
/*   Updated: 2019/10/20 15:50:49 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "app.h"
#include <unistd.h>

int	main(void)
{
	t_app	app;

	app_make(&app, 640, 480);
	app_run(&app);
	scene_free(&app.scene);
	SDL_DestroyWindow(app.window);
	return (EXIT_SUCCESS);
}
