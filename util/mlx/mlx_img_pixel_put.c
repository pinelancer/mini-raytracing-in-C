/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_pixel_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:13:18 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/06 19:54:16 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxx.h"

void    mlx_img_pixel_put(t_img *img, t_color *color, int x, int y)
{
	char	*dest;

	dest = img->addr + (y * img->width + x * (img->bpp / 8));
	*(unsigned int *)dest = mlx_pixel_color(color);
}
