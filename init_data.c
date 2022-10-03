/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:03:29 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/08 16:31:03 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"

void	init_data(t_vars *vars, double z, double zi)
{
	vars->x = 0.0;
	vars->y = 0.0;
	vars->scale = 1.0;
	vars->init_z = z;
	vars->init_zi = zi;
}

double	**create_array(int i, t_mem *mem)
{
	int		j;
	double	*values;
	double	**rows;

	values = malloc(i * i * sizeof(double));
	if (!values)
		exit(-1);
	mem->values = values;
	rows = malloc(i * sizeof(double *));
	if (!rows)
		exit (-1);
	mem->rows = rows;
	j = -1;
	while (++j < i)
		rows[j] = values + j * i;
	return (rows);
}
