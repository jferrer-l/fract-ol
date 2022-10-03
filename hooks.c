/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:53:37 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/07 18:54:58 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

int	mouse_hook_m(int key, int x, int y, t_vars *vars)
{
	double	scale2;
	double	**coords;

	if (key == 4)
		scale2 = vars->scale * 1.25;
	else if (key == 5)
		scale2 = vars->scale / 1.25;
	else
		return (0);
	vars->x = (((x - 640) / (320 * vars->scale)) - ((x - 640) / (320 * scale2)) + vars->x);
	vars->y = (((y - 640) / (320 * vars->scale)) - ((y - 640) / (320 * scale2)) + vars->y);
	vars->scale = scale2;
	printf("scale = %f\n", vars->scale);
	coords = init_mandelbrot(vars, NULL);
	printfrac(vars->mlx, vars->win, coords);
	return (0);
}

int	mouse_hook_j(int key, int x, int y, t_vars *vars)
{
	double	scale2;
	double	**coords;

	if (key == 4)
		scale2 = vars->scale * 1.25;
	else if (key == 5)
		scale2 = vars->scale / 1.25;
	else
		return (0);
	vars->x = (((x - 640) / (320 * vars->scale
					)) - ((x - 640) / (320 * scale2)) + vars->x);
	vars->y = (((y - 640) / (320 * vars->scale
					)) - ((y - 640) / (320 * scale2)) + vars->y);
	vars->scale = scale2;
	printf("scale = %f\n", vars->scale);
	coords = init_julia(vars, NULL);
	printfrac(vars->mlx, vars->win, coords);
	return (0);
}

int	escape(int key, t_mem *mem)
{
	printf("key = %d\n", key);
	if (key == 53)
	{
		if (mem)
		{
			if (mem->values)
				free(mem->values);
			if (mem->rows)
				free(mem->rows);
			if (mem->vars)
				free(mem->vars);
			free(mem);
		}
		exit (0);
	}
	return (0);
}
