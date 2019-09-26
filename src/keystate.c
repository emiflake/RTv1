/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 18:33:01 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/26 20:03:07 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "keystate.h"
#include <stdbool.h>

void			keystate_key_down(t_keystate *ks, SDL_Scancode key)
{
	if (key >= 0 && key <= 512)
		ks->keys[key] = true;
}

void			keystate_key_up(t_keystate *ks, SDL_Scancode key)
{
	if (key >= 0 && key <= 512)
		ks->keys[key] = false;
}

bool			is_key_down(const t_keystate *ks, SDL_Scancode key)
{
	if (key >= 0 && key <= 512)
		return (ks->keys[key]);
	else
		return (false);
}
