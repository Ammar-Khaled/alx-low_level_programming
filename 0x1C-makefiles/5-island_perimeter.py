#!/usr/bin/python3
"""Island Perimeter Problem."""


def check_neighbours(grid, i, j):
    """Check the land cells adjacent to a specific cell."""
    subtract = 0

    if i > 0 and grid[i - 1][j] == 1:
        subtract += 1
    if j > 0 and grid[i][j - 1] == 1:
        subtract += 1
    if i < len(grid) - 1 and grid[i + 1][j] == 1:
        subtract += 1
    if j < len(grid[i]) - 1 and grid[i][j + 1] == 1:
        subtract += 1

    return subtract


def island_perimeter(grid):
    """Return the perimeter of the island represented by the grid."""
    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4
                perimeter -= check_neighbours(grid, i, j)

    return perimeter
