/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   primitives.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 14:45:45 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:11:50 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIMITIVES_H
# define PRIMITIVES_H

# include <SDL2/SDL.h>
# include <stdint.h>

void	prim_put_pixel(
	SDL_Surface *surface, size_t x, size_t y, uint32_t color);
void	prim_clear(SDL_Surface *surface, uint32_t color);

#endif
