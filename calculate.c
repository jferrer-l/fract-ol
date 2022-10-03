/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jferrer- <jferrer-@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:50:44 by jferrer-          #+#    #+#             */
/*   Updated: 2022/03/08 16:32:26 by jferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "utils.h"
#include "minilibx_mms_20200219/mlx.h"

static int		main_julia(double z, double zi, t_mem *mem);
static int		main_mandelbrot(t_mem *mem);
void			printfrac(void *p, void *window, double **coords);

int	main(int argc, char **argv)
{
	t_mem	*mem;

	mem = malloc(sizeof(t_mem));
	if (!mem)
		return (0);
	if (argc > 1 && ft_strncmp(argv[1],
			"mandelbrot", (int)ft_strlen(argv[1])) == 0)
		main_mandelbrot(mem);
	else if (argc > 3 && ft_strncmp(argv[1],
			"julia", (int)ft_strlen(argv[1])) == 0 && argc)
		main_julia(double_atoi(argv[2]), double_atoi(argv[3]), mem);
	else
	{
		printf("formato incorrecto, parametros posibles: mandelbrot, ");
		printf("julia double1 double2\n");
	}
	return (0);
}

static int	main_julia(double z, double zi, t_mem *mem)
{
	double	**coords;
	t_data	img;
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	mem->vars = vars;
	init_data(vars, z, zi);
	vars->mlx = mlx_init();
	img.img = mlx_new_image(vars->mlx, 1281, 1281);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	vars->win = mlx_new_window(vars->mlx, 1281, 1281, "made by jferrer-");
	coords = init_julia(vars, mem);
	mlx_key_hook(vars->win, escape, mem);
	mlx_mouse_hook(vars->win, mouse_hook_j, vars);
	printfrac(vars->mlx, vars->win, coords);
	mlx_loop(vars->mlx);
	return (0);
}

static int	main_mandelbrot(t_mem *mem)
{
	double	**coords;
	t_data	img;
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	mem->vars = vars;
	init_data(vars, 0.0, 0.0);
	vars->mlx = mlx_init();
	img.img = mlx_new_image(vars->mlx, 1281, 1281);
	img.addr = mlx_get_data_addr(img.img,
			&img.bits_per_pixel, &img.line_length, &img.endian);
	vars->win = mlx_new_window(vars->mlx, 1281, 1281, "made by jferrer-");
	coords = init_mandelbrot(vars, mem);
	mlx_key_hook(vars->win, escape, mem);
	mlx_mouse_hook(vars->win, mouse_hook_m, vars);
	printfrac(vars->mlx, vars->win, coords);
	mlx_loop(vars->mlx);
	return (0);
}

void	printfrac(void *p, void *window, double **coords)
{
	int			i;
	int			j;
	static int	temp[35] = {0xfffafa, 0xfdf5e6, 0xffebcd,
		0xffe4b5, 0xfffacd, 0xf0f8ff, 0xfff0f5, 0xffe4e1,
		0x0, 0x696969, 0x778899, 0x191970, 0xb0c4de, 0xced1,
		0x66cdaa, 0x2e8b57, 0x20b2aa, 0x7fff00, 0x9acd32,
		0xfafad2, 0xffff00, 0xb8860b, 0xbc8f8f, 0xcd5c5c,
		0xf5f5dc, 0xb22222, 0xe9967a, 0xf08080, 0xff69b4,
		0xdb7093, 0xda70d6, 0x9370db, 0xeecbad, 0xe0eeee,
		0xffc1c1};

	i = -1;
	while (++i < 1281.0)
	{
		j = -1;
		while (++j < 1281.0)
			mlx_pixel_put(p, window, j, i,
				temp[(int)coords[j][i] % 35]);
	}
}
