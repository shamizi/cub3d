/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamizi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:55:18 by shamizi           #+#    #+#             */
/*   Updated: 2021/04/19 16:10:57 by shamizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB_H
# define FT_CUB_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 10000
typedef struct s_cub	t_cub;
struct					s_cub
{
	int i;
	int error;
	int FC;
	int nbligne;
	char *NO;
	char *SO;
	char *EA;
	char *WE;
	char *SP;
	int rx;
	int ry;
	int F;
	int C;
	char **map;
	int FLMAP;
	int posx;
	int posy;
};

int		get_next_line(int fd, char **line, t_cub *cub);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_error(t_cub *cub, char *str, int i);
int	stock_map(char *str, t_cub *cub);
void	ft_map(char *str, t_cub *cub);
int	check_cub(char *str, t_cub *cub);
#endif
