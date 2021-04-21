/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:19:04 by shamizi           #+#    #+#             */
/*   Updated: 2021/04/19 18:04:27 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h" 

void	ft_error(t_cub *cub, char *str, int i)
{
	//if (cub->error != 0)
	//{
		write(1, "Error\n", 6);
		write(1, str, i);
		exit(EXIT_FAILURE);
	//}
	/*if (cub->error == 1)
		printf("\nerreur dqns check fc\n");
	else if (cub->error == 2)
		printf("erreur dans ft_fc\n");
	else if (cub->error == 3)
		printf("erreur dqns color\n");
	else if (cub->error == 4)
		printf("erreur dqns path\n");
	else if (cub->error == 5)
		printf("erreur dans resolution");
	else if (cub->error == 6)
		printf("erreur dans l'autre fichier");
	else if (cub->error == 7)
		printf("erreur dans checkchar");
*/
}
