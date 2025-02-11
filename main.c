/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:57:53 by asou              #+#    #+#             */
/*   Updated: 2025/02/09 19:43:01 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Error function:
void	incorrect_entry()
{
	ft_printf("Usage: ./fractol [fractal_name]\n");
	ft_printf("fractal_name in [\"mandelbrot\", \"julia\", \"burningship\"]\n");
	ft_printf("for julia add another two argument: X and Y being in the interval [-2, 2]\n");
	exit(EXIT_FAILURE);
}

// checking if the numbers passed in julia are valid (real numbers and they are between -2 and 2)
int	is_valid_julia_number(char *num)
{
	size_t	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// Parse the arguments and set the fractal name
void	parse_args(int argc, char **argv, t_fractal *img)
{
	if (argc == 2  && argv[1] == "mandelbrot")
	{
		img->name = argv[1];
		return ;
	} else
	if (argc == 2 && argv[1] == "burningship")
	{
		img->name = argv[1];
		return ;
	} else
	if (argc == 4 && argv[1] == "julia" &&\
		is_valid_julia_number(argv[2]) && is_valid_julia_number(argv[3]))
	{
		img->name = argv[1];
		return ;
	}
	incorrect_entry();
	img->name = argv[1];
}

// Initialize the fractal
void	init_fractal(t_fractal *img)
{
	
}

// Render the fractal
void	render_fractal(t_fractal *img)
{
	if (&img->name == "mandelbrot")
		render_mandelbrot(&img);
	else if (&img->name == "julia")
		render_julia(&img);
	else if (&img->name == "burningship")
		render_burning_ship(&img);
}

int	main(int argc, char **argv)
{
	t_fractal	img;

	parse_args(argc, argv, &img);
	init_fractal(&img);
	render_fractal(&img);
	mlx_loop(img.mlx);
}
