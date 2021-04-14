/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:38:37 by shamizi           #+#    #+#             */
/*   Updated: 2021/04/14 14:55:43 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int		stock_map(char *str, t_cub *cub)
{
	static int i = 0;
	int j;

	j = 0;
	cub->map[i] = NULL;
	if (!(cub->map[i] = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	while (str[j])
	{
		cub->map[i][j] = str[j];
		j++;
	}
	cub->map[i][j] = '\0';
	i++;
	return (0);
}

int		checkchar(char *str, t_cub *cub)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' || str[i] != '1' || str[i] != '2' || str[i] != ' '
				|| str[i] != 'N' || str[i] != 'S' || str[i] != 'E' || str[i] != 'W')
			return (0);
		i++;
	}
	return (1);
}
void	ft_map(char *str, t_cub *cub)
{
	static int nbligne = 0;

	if (str[0] == ' ' ||str[0] == '1' ||str[0] == '0' ||str[0] == '2')
		cub->FLMAP = 1;
	if (cub->FLMAP == 1)
	{
		if (cub->NO == NULL || cub->SO == NULL || cub->EA == NULL
				|| cub->WE == NULL || cub->SP == NULL || cub->F == 0 || cub->C == 0
				|| cub->rx == 0 || cub->ry == 0)
			cub->error = 2;
		if (checkchar(str, cub) == 0)
			cub->error = 2;
		nbligne = nbligne + 1;
	}
	cub->nbligne = nbligne;
}
