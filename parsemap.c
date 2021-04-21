/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsemap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:38:37 by shamizi           #+#    #+#             */
/*   Updated: 2021/04/19 18:03:48 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	floodfill(t_cub *cub, int x, int y,int overflow)
{
	if (x < 0 || y < 0 || !cub->map[y][x])
		ft_error(cub, "wrong map\n", 10);
	if (overflow > 30000)
		ft_error(cub, "overflow\n", 8);
	if (cub->map[y][x] != '0' && cub->map[y][x] != '2')
		return ;
	if (cub->map[y][x] == 'O' || cub->map[y][x] == 'X')
		return ;
	if (cub->map[y][x] == '0')
		cub->map[y][x] = 'O';
	if (cub->map[y][x] == '2')
		cub->map[y][x] = 'X';

	floodfill(cub, x + 1, y, overflow++);
	floodfill(cub, x - 1, y, overflow++);
	floodfill(cub, x, y + 1, overflow++);
	floodfill(cub, x, y - 1, overflow++);
}

void	pos_start(t_cub *cub)
{
	int i;
	int j;
	int compt;

	i = 0;
	compt = 0;
	while(cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
					||cub->map[i][j] == 'W' ||cub->map[i][j] == 'E')
			{
				cub->map[i][j] = '0';
				cub->posx = j;
				cub->posy = i;
				compt++;
			}
			j++;
		}
		i++;
	}
	if (compt != 1)
		cub->error = 9;
}

int		ft_stock_map(char *str, t_cub *cub)
{
	static int i = 0;
	int j;

	j = 0;
	cub->map[i] = NULL;
	if (!(cub->map[i] = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (0);
	while (str[j])
	{
		if(str[j] == ' ')
			cub->map[i][j] = '1';
		else
			cub->map[i][j] = str[j];
		j++;
	}
	cub->map[i][j] = '\0';
	i++;
	return (0);
}


int		stock_map(char *fichier, t_cub *cub)
{
	int fd;
	int res;
	char *str;

	res = 1;
	fd = open(fichier, O_RDONLY);
	if (!(cub->map = malloc(sizeof(char *) * cub->nbligne)))
		return (0);
	while (res != 0)
	{
		res = get_next_line(fd, &str, cub);
		if (str[0] == ' ' || str[0] == '1' ||str[0] == '0' ||str[0] == '2')
			ft_stock_map(str, cub);
		free(str);
	}
	pos_start(cub);
	floodfill(cub, cub->posx, cub->posy, 0);

	close(fd);
	//suite de la fonction
	return (0);
}

int		checkchar(char *str, t_cub *cub)
{
	int i;
	static int j = 0;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != ' '
				&& str[i] != 'N' && str[i] != 'S' && str[i] != 'E' && str[i] != 'W')
			return (0);
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			j++;
		if (j > 1)
			cub->error = 8;
		i++;
	}
	return (1);
}

void	ft_map(char *str, t_cub *cub)
{
	static int nbligne = 0;

	if (str[0] == ' ' || str[0] == '1' ||str[0] == '0' ||str[0] == '2')
		cub->FLMAP = 1;
	if (cub->FLMAP == 1)
	{
		if (cub->NO == NULL || cub->SO == NULL || cub->EA == NULL
				|| cub->WE == NULL || cub->SP == NULL || cub->F == 0 || cub->C == 0
				|| cub->rx == 0 || cub->ry == 0)
			cub->error = 6;
		if (checkchar(str, cub) == 0)
			cub->error = 7;
		nbligne = nbligne + 1;
	}
	cub->nbligne = nbligne;
}
