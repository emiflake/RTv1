/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   primitives.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmartins <nmartins@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 14:49:50 by nmartins       #+#    #+#                */
/*   Updated: 2019/09/23 18:12:06 by nmartins      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

#include "primitives.h"

/*
** TODO: handle error
*/

void		prim_put_pixel(
	SDL_Surface *surface, size_t x, size_t y, uint32_t color)
{
	uint32_t *pixels_arr;
	uint32_t *loc;

	pixels_arr = (uint32_t*)surface->pixels;
	if (x >= (size_t)surface->w && y >= (size_t)surface->h)
	{
		ft_printf("Out of bounds put_pixel: %lu, %lu\n", x, y);
		exit(0);
	}
	loc = &pixels_arr[x + y * surface->w];
	*loc = color;
}

void		prim_clear(SDL_Surface *surface, uint32_t color)
{
	uint32_t	*pixels_arr;
	size_t		index;

	pixels_arr = (uint32_t*)surface->pixels;
	index = 0;
	while (index < (size_t)(surface->w * surface->h))
	{
		pixels_arr[index] = color;
		index++;
	}
}
