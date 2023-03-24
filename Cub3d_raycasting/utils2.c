/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:44:31 by ysensoy           #+#    #+#             */
/*   Updated: 2023/03/24 13:49:48 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_color(t_cub3d *img)
{
	int (i) = 0;
	img->ut_color = ft_split(img->split[1], ',');
	while (i < 3)
	{
		if (!img->ut_color[i] || !is_number(img->ut_color[i])
			|| ft_atoi(img->ut_color[i]) > 255 || ft_atoi(img->ut_color[i]) < 0)
			exit_double_split_func(img->split, img->ut_color, img);
		else if (strcmp(img->split[0], "F") == 0)
		{
			img->f_color[i] = ft_atoi(img->ut_color[i]);
			if (i == 2)
				img->f = 1;
		}
		else if (strcmp(img->split[0], "C") == 0)
		{
			img->c_color[i] = ft_atoi(img->ut_color[i]);
			if (i == 2)
				img->c = 1;
		}
		i++;
	}
}
