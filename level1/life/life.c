/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:38:54 by daniel149af       #+#    #+#             */
/*   Updated: 2026/03/11 23:04:43 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 1024

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return i;
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void ft_putgrid(char *str, int width, int height)
{
	int pos = 0;
	for (int i = 0; i < (width * height); i++)
	{
		if (pos == width)
		{
			putchar('\n');
			pos = 0;
		}
		if (str[i] == '\0')
			putchar(' ');
		else
			putchar(str[i]);
		pos++;
	}
	putchar('\n');
}

void handle_movements(char c, int *x, int *y, int *pen, int width, int height, char *grid)
{
	int tmp_x = *x;
	int tmp_y = *y;

	if (c == 'd')
		tmp_x++;
	if (c == 'a')
		tmp_x--;
	if (c == 'w')
		tmp_y--;
	if (c == 's')
		tmp_y++;
	if (c == 'x')
	{
		*pen = !*pen;
	}
	if (tmp_x >= 0 && tmp_x < width && tmp_y >= 0 && tmp_y < height)
	{
		*x = tmp_x;
		*y = tmp_y;
	}
	if (*pen == 1)
	{
		int index = (*y) * width + (*x);
		grid[index] = '0';
	}
}

void gameOfLife(int iterations, int height, int width, char * grid, char *new_grid)
{
	int count;
	for (int it = 0; it < iterations; it++)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				count = 0;
				int index = y * width + x;
				if (x + 1 < width && grid[index + 1] == '0')
					count++;
				if (x > 0 && grid[index - 1] == '0')
					count++;
				if (y > 0 && grid[index - width] == '0')
					count++;
				if (y + 1 < height && grid[index + width] == '0')
					count++;
				if (y > 0 && x > 0 && grid[index - width - 1] == '0')
					count++;
				if (y + 1 < height && x > 0 && grid[index + width - 1] == '0')
					count++;
				if (y > 0 && x + 1 < width && grid[index - width + 1] == '0')
					count++;
				if (y + 1 < height && x + 1 < width && grid[index + width + 1] == '0')
					count++;
				if (grid[index] == '0')
				{
					if (count == 2 || count == 3)
						new_grid[index] = '0';
					else
						new_grid[index] = '\0';
				}
				else
				{
					if (count == 3)
						new_grid[index] = '0';
				}
			}
		}
		for (int i = 0; i < width * height; i++)
			grid[i] = new_grid[i];
		for (int i = 0; i < width * height; i++)
			new_grid[i] = '\0';
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (ft_putstr("Error arguments: width height iterations\n"), 1);

	int x = 0;
	int y = 0;
	int pen = 0;
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int iterations = atoi(argv[3]);
	
	char *grid = calloc((width * height), sizeof(char));
	if (!grid)
		return (1);
	char *buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (1);
	char *new_grid = calloc((width * height), sizeof(char));
	if (!new_grid)
		 return (1);
	int r; 
	while ((r = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[r] = '\0';
		for (int i = 0; i < r; i++)
		{
			char c = buffer[i];
			handle_movements(c, &x, &y, &pen, width, height, grid);
		}
	}
	// debug
	putchar('\n');
	ft_putgrid(grid, width, height);
	// end debud
	gameOfLife(iterations, height, width, grid, new_grid);
	ft_putgrid(grid, width, height);
	free(new_grid);
	free(grid);
	free(buffer);
	return (0);
}
