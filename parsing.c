/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:47:24 by shamizi           #+#    #+#             */
/*   Updated: 2021/04/19 16:52:40 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

int		ft_resolution(t_cub *cub, char *str)
{
	int res;

	res = 0;
	if (str[cub->i] != ' ')
		cub->error = 5;
	while (str[cub->i] == ' ' && str[cub->i])
		cub->i++;
	if (str[cub->i] == '+' || str[cub->i] == '-')
		cub->error = 5;
	while (str[cub->i] >= '0' && str[cub->i] <= '9')
	{
		res = 10 * res + (str[cub->i] - '0');
		cub->i++;
	}
	return (res);
}

void	ft_check_FC(char *str, t_cub *cub)
{
	int i;
	int nb;
	int virgule;

	i = 1;
	nb = 0;
	virgule = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != ',' && !(str[i] >= '0' && str[i] <= '9'))
			cub->error = 1;
		if (str[i] >= '0' && str[i] <= '9' && nb == 0)
			nb = 1;
		if (nb == 1 && str[i] == ',')
		{
			virgule++;
			nb = 0;
		}
		i++;
	}
	if (virgule != 2)
		cub->error = 1;
}

int		ft_FC(char *str, t_cub *cub)
{
	int check;

	cub->FC = 0;
	if (str[1] != ' ')
		cub->error = 2;

	ft_check_FC(str, cub);
	while (str[cub->i] == ' ' || str[cub->i] == ',')
	{
		check = 0;
		cub->i++;
		while (str[cub->i] >= '0' && str[cub->i] <= '9')
		{
			cub->FC = cub->FC * 10 + str[cub->i] - 48;
			check = check * 10 + str[cub->i] - 48;
			cub->i++;
		}
		if (check > 255 || check < 0)
			cub->error = 2;
	}
	return (cub->FC);
}

void	ft_color(char **str, t_cub *cub)
{
	int i;

	i = 0;
	cub->i = 1;
	if (cub->nbligne > 0 && (cub->NO == NULL || cub->SO == NULL
				|| cub->EA == NULL|| cub->WE == NULL || cub->SP == NULL))
		cub->error = 3;
//	if  ((cub->NO != NULL || cub->SO != NULL || cub->EA != NULL
//				|| cub->WE != NULL || cub->SP != NULL) && (cub->rx == 0 || cub->ry == 0))
//		cub->error = 3;
	if (*str[i] == 'R')
	{
		if (cub->rx != 0 || cub->ry != 0)
			cub->error = 3;
		cub->rx = ft_resolution(cub, *str);
		cub->ry = ft_resolution(cub, *str);
	}
	else if (*str[i] == 'F')
		cub->F = ft_FC(*str, cub);
	else if (*str[i] == 'C')
		cub->C = ft_FC(*str, cub);
}

void	ft_path(char *str, t_cub *cub, char **texture, int i)
{
	int j;

	j = 0;
	if (*texture != NULL)
		cub->error = 4;
	while (str[i] && str[i] != '.')
	{
		if (str[i] != ' ' && str[i] != '.')
			cub->error = 4;
		i++;
	}
	if (!(*texture = (char *)(malloc(sizeof(char) * (ft_strlen(str) + 1)))))
		cub->error = 4;
	while (str[i])
	{
		(*texture)[j] = str[i];
		i++;
		j++;
	}
	(*texture)[j] = '\0';
}

void	ft_texture(char *str, t_cub *cub)
{
	int i;

	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O')
		ft_path(str, cub, &cub->NO, 2);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		ft_path(str, cub, &cub->SO, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_path(str, cub, &cub->EA, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_path(str, cub, &cub->WE, 2);
	else if (str[i] == 'S' && str[i + 1] != 'O')
		ft_path(str, cub, &cub->SP, 1);
}
void	ft_parsing(char *fichier, t_cub *cub)
{
	int fd;
	int ret;
	char *str;

	ret = 1;
	str = NULL;
	if ((fd = open(fichier, O_DIRECTORY)) != -1)
		ft_error(cub, "IS A DIRECTORY", 14);
	if((fd = open(fichier, O_RDONLY)) == -1)
		ft_error(cub, "INVALIDE .CUB", 13);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, cub);
		if (cub->error != 0)
			ft_error(cub, "erreur de parsing", 17);
		ft_color(&str, cub);
		ft_texture(str, cub);
		ft_map(str, cub);
		free(str);
	}
	close (fd);
	if (cub->nbligne == 0)
		ft_error(cub, "pas de map", 10);
	stock_map(fichier, cub);
}

int		check_cub(char *str, t_cub *cub)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '.')
	{
		if (i == 0)
		{
			ft_error(cub, "nom de fichier invalide", 23);
			return (0);
		}
		i--;
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b' && str[i + 4] == '\0')
		ft_parsing(str, cub);
	else
		ft_error(cub, "nom de fichier invalide", 23);
	return (0);
}

void	ft_init(t_cub *cub)
{
	cub->i = 0;
	cub->error = 0;
	cub->FC = 0;
	cub->nbligne = 0;
	cub->NO = NULL;
	cub->SO = NULL;
	cub->EA = NULL;
	cub->WE = NULL;
	cub->SP = NULL;
	cub->rx = 0;
	cub->ry = 0;
	cub->F = 0;
	cub->C = 0;
	cub->posx = 0;
	cub->posy = 0;
}

int		main(int argc, char **argv)
{
	t_cub *cub;
	cub = malloc(sizeof(*cub));
	ft_init(cub);
	if (argc == 2)
	{
		check_cub(argv[1], cub);
	}
	else
		write(1, "Error\nARGUMENTS INVALIDES\n", 30);
//	printf("\n i :%d\n error :%d\n FC : %d\n nbligne : %d\n NO : %s\n SO : %s\n EA : %s\n WE :%s\n SP: %s\nRX :%d\nRY :%d\nF : %d\n:C %d\n\n FLMAP :%d\n",
//			cub->i,cub->error,cub->FC,cub->nbligne,cub->NO,cub->SO,cub->EA,cub->WE,cub->SP,cub->rx,cub->ry,cub->F,cub->C,cub->FLMAP);
	
	int i;
	int j;
	i = 0;
	while(i < 14)
	{
		j = 0;
		while(cub->map[i][j] != '\0')
		{
			printf("%c", cub->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
