/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:00:27 by asou              #+#    #+#             */
/*   Updated: 2025/02/09 17:21:06 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <mlx.h>
#include <libc.h> 	// for testing and debugging, to be removed!
#include <stdlib.h> // may be useful, but cusious should be paid!

// Constants
#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

// Structure for the fractal
typedef struct s_fractal
{
    char    *name;
    void	*mlx;
    void	*win;
    void	*img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
    int		width;
    int		height;
}				t_fractal;

// Complex number structure
typedef struct s_complex
{
    double	real;
    double	imaginary;
}				t_complex;


#endif
