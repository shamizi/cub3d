/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <shamizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:19:04 by shamizi           #+#    #+#             */
/*   Updated: 2021/04/21 16:17:37 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h" 

void	ft_error(t_cub *cub, char *str, int i)
{
	size_t x;
	size_t y;
	cub->error = cub->error;
	x = write(1, "Error\n", 6);
	y = write(1, str, i);
	(void)x;
	(void)y;
	exit(EXIT_FAILURE);
}
