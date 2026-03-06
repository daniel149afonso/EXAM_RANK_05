/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:38:54 by daniel149af       #+#    #+#             */
/*   Updated: 2026/03/05 23:23:57 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return i;
}

void ft_pustr(char *str)
{
	write(1, str, ft_strlen(str));
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (ft_pustr("Error arguments: width height iterations\n"), 1);

	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int iterations = atoi(argv[3]);
	
	char **grid = malloc((width * height) * sizeof(char));
	if (!grid)
		return 1;
	char *buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (1);

	int r; 
	while ((r = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = '\0';
		ft_pustr(buffer);
	}

	free(buffer);
	return (0);
}