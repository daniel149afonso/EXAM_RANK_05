/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel149afonso <daniel149afonso@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:49:30 by daniel149af       #+#    #+#             */
/*   Updated: 2026/03/05 13:13:52 by daniel149af      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void put_str(const char *s)
{
    while (*s)
        write(2, s++, 1);
}

static int ft_atoi(const char *s)
{
    int sign = 1;
    long n = 0;

    while (*s == ' ' || (*s >= 9 && *s <= 13))
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-') sign = -1;
        s++;
    }
    while (*s >= '0' && *s <= '9')
    {
        n = n * 10 + (*s - '0');
        s++;
    }
    return (int)(n * sign);
}

static int in_bounds(int x, int y, int w, int h)
{
    return (x >= 0 && y >= 0 && x < w && y < h);
}

static void set_alive(unsigned char *grid, int x, int y, int w, int h)
{
    if (in_bounds(x, y, w, h))
        grid[y * w + x] = 1;
}

static int count_neighbors(unsigned char *g, int x, int y, int w, int h)
{
    int cnt = 0;
    int dy, dx;

    for (dy = -1; dy <= 1; dy++)
    {
        for (dx = -1; dx <= 1; dx++)
        {
            int nx, ny;
            if (dx == 0 && dy == 0)
                continue;
            nx = x + dx;
            ny = y + dy;
            if (in_bounds(nx, ny, w, h))
                cnt += (g[ny * w + nx] != 0);
        }
    }
    return cnt;
}

static void step(unsigned char *cur, unsigned char *nxt, int w, int h)
{
    int x, y;

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            int n = count_neighbors(cur, x, y, w, h);
            unsigned char alive = cur[y * w + x];

            if (alive)
                nxt[y * w + x] = (n == 2 || n == 3) ? 1 : 0;
            else
                nxt[y * w + x] = (n == 3) ? 1 : 0;
        }
    }
}

static void print_grid(unsigned char *g, int w, int h)
{
    int x, y;
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
            putchar(g[y * w + x] ? '0' : ' ');
        putchar('\n');
    }
}

int main(int ac, char **av)
{
    int w, h, it;
    unsigned char *grid = NULL;
    unsigned char *tmp = NULL;
    int pen_down = 0;
    int px = 0, py = 0;

    if (ac != 4)
    {
        put_str("Usage: ./life width height iterations\n");
        return 1;
    }

    w = ft_atoi(av[1]);
    h = ft_atoi(av[2]);
    it = ft_atoi(av[3]);

    if (w <= 0 || h <= 0 || it < 0)
        return 1;

    grid = (unsigned char *)calloc((size_t)w * (size_t)h, 1);
    tmp  = (unsigned char *)calloc((size_t)w * (size_t)h, 1);
    if (!grid || !tmp)
    {
        free(grid);
        free(tmp);
        return 1;
    }

    /* Read commands from stdin */
    {
        char buf[4096];
        ssize_t r;
        while ((r = read(0, buf, sizeof(buf))) > 0)
        {
            ssize_t i = 0;
            while (i < r)
            {
                char c = buf[i++];

                if (c == 'x')
                {
                    pen_down = !pen_down;
                    if (pen_down)
                        set_alive(grid, px, py, w, h);
                }
                else if (c == 'w' || c == 'a' || c == 's' || c == 'd')
                {
                    int nx = px;
                    int ny = py;

                    if (c == 'w') ny--;
                    if (c == 's') ny++;
                    if (c == 'a') nx--;
                    if (c == 'd') nx++;

                    /* Ignore moves that go out of bounds */
                    if (in_bounds(nx, ny, w, h))
                    {
                        px = nx;
                        py = ny;
                        if (pen_down)
                            set_alive(grid, px, py, w, h);
                    }
                }
                /* else: ignore (including '\n') */
            }
        }
    }

    /* Simulate iterations */
    while (it-- > 0)
    {
        step(grid, tmp, w, h);
        /* swap */
        {
            unsigned char *swap = grid;
            grid = tmp;
            tmp = swap;
        }
        /* clear tmp for next step */
        {
            size_t n = (size_t)w * (size_t)h;
            size_t i;
            for (i = 0; i < n; i++)
                tmp[i] = 0;
        }
    }

    print_grid(grid, w, h);

    free(grid);
    free(tmp);
    return 0;
}