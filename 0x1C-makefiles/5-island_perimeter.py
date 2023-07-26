#!/usr/bin/python3
"""Defining an island perimeter"""


def island_perimeter(grid):
    """Returns the perimeter of the island described in the grid"""
    size = 0
    edges = 0
    width = len(grid[0])
    height = len(grid)

    for a in range(height):
        for b in range(width):
            if grid[a][b] == 1:
                size += 1
                if (b > 0 and grid[a][b - 1] == 1):
                    edges += 1
                if (a > 0 and grid[a - 1][b] == 1):
                    edges += 1
    return size * 4 - edges * 2
