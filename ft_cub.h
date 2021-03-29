/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:55:18 by shamizi           #+#    #+#             */
/*   Updated: 2021/03/25 13:09:12 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

typedef struct s_cub	t_cub;
struct					s_cub
{
	char *res;
	char *south;
	char *north;
	char *east;
	char *west;
	int	floor;
	int *celling;
	char *sprite;
	int	resx;
	int resy;
	int save;
	int fd;
	char cp;
	char *line;
}
