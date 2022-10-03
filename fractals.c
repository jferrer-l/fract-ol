/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:58:20 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/07 19:12:18 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

static double	lim_at_infinity_j(double *data, double max_iter);
static double	lim_at_infinity_i(double *data, double max_iter);

double	**init_mandelbrot(t_vars *vars, t_mem *mem)
{
	int				i;
	int				j;
	double			max_iter;
	double			data[4];
	static double	**coords;

	max_iter = 50 * pow(log10(vars->scale + 10), 1.25);
	if (!coords)
		coords = create_array(1281, mem);
	i = -1;
	while (++i < 1281)
	{
		j = -1;
		data[0] = (i - 640.0) / (320.0 * vars->scale) + vars->x;
		while (++j < 1281)
		{
			data[2] = 0;
			data[3] = 0;
			data[1] = (j - 640.0) / (320.0 * vars->scale) + vars->y;
			coords[i][j] = lim_at_infinity_i(data, max_iter);
		}
	}
	return (coords);
}

double	**init_julia(t_vars *vars, t_mem *mem)
{
	int				i;
	int				j;
	double			max_iter;
	double			data[4];
	static double	**coords;

	max_iter = 50 * pow(log10(vars->scale + 10), 1.25);
	if (!coords)
		coords = create_array(1281, mem);
	i = -1;
	while (++i < 1281)
	{
		j = -1;
		while (++j < 1281)
		{
			data[0] = vars->init_z;
			data[1] = vars->init_zi;
			data[2] = (i - 640.0) / (320.0 * vars->scale) + vars->x;
			data[3] = (j - 640.0) / (320.0 * vars->scale) + vars->y;
			coords[i][j] = lim_at_infinity_j(data, max_iter);
		}
	}
	return (coords);
}

static double	lim_at_infinity_j(double *data, double max_iter)
{
	double	tempz;
	double	tempzi;
	double	count;

	count = -1;
	while (data[2] * data[2] + data[3] * data[3] < 4 && ++count < max_iter)
	{
		tempz = data[2] * data[2] - data[3] * data[3] + data[0];
		tempzi = 2.0 * data[2] * data[3] + data[1];
		if (data[2] == tempz && data[3] == tempzi)
		{
			count = max_iter;
			break ;
		}
		data[2] = tempz;
		data[3] = tempzi;
	}
	return (count);
}

static double	lim_at_infinity_i(double *data, double max_iter)
{
	double	tempz;
	double	tempzi;
	double	count;

	count = -1;
	while (sqrt(data[2] * data[2] + data[3] * data[3]
		) <= 2.0 && ++count < max_iter)
	{
		tempz = data[2];
		tempzi = data[3];
		data[2] = tempz * tempz + data[0] - tempzi * tempzi;
		data[3] = 2 * tempz * tempzi + data[1];
	}
	return (count);
}
