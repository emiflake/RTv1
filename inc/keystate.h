/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystate.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 18:28:02 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:34:27 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYSTATE_H
# define KEYSTATE_H

# include <stdbool.h>

typedef struct	s_keystate
{
	bool	keys[512];
}				t_keystate;

void			keystate_key_down(t_keystate *ks, int key);
void			keystate_key_up(t_keystate *ks, int key);
bool			is_key_down(const t_keystate *ks, int key);

#endif
