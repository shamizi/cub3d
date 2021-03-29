/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:47:24 by shamizi           #+#    #+#             */
/*   Updated: 2021/03/29 15:42:36 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	ft_color(char **str, t_cub *cub)
{
	//si on a deja recuperer des infos sur NSEW mais pas la resolution -->error
	//si on a deja un nb de ligne de map mais pas les info NSEW et sprite -->pb
	//verifier caractere R en 1ere position
	//si resolution x ou y est deja initialiser -->double initialisation donc c une erreur 
	//donner les valeur RX et RY
	//premier caractere peut etre aussi Floor ou Celling
}

void	parsing(char *fichier, t_cub *cub)
{
	int fd;
	int ret;
	char *str;

	ret = 1;
	str = NULL;
	if (fd = open(fichier, O_DIRECTORY != -1))
			//ERROR directory;
	if(fd = open(fichier, O_RDONLY == -1))
		//ERROR fichier invalide;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, cub);
		if (cub->error == 2)
			//error de parsing
		ft_color(&str, cub);
		ft_texture(str, cub);
		ft_map(str, cub);
		free(str);
	}
	close (fd);
	if (cub->nbligne == 0 || cub->sizeline == 0)
		//error de map
	ft_parse_map(fichier, cub);
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
			//ERROR nom de fichier map
			return (0);
		}
		i--;
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b' && str[i + 4] == '\0')
		ft_parsing(str, cub);
	else
		//ERROR nom de ficheir map
	return (0);
}
