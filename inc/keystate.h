/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystate.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 18:28:02 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/26 20:02:45 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYSTATE_H
# define KEYSTATE_H

# include <stdbool.h>
# include <SDL2/SDL.h>

typedef struct	s_keystate
{
	bool	keys[SDL_NUM_SCANCODES];
}				t_keystate;

void			keystate_key_down(t_keystate *ks, SDL_Scancode key);
void			keystate_key_up(t_keystate *ks, SDL_Scancode key);
bool			is_key_down(const t_keystate *ks, SDL_Scancode key);

#endif
