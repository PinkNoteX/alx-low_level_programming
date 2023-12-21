#!/usr/bin/python3
"""get perimeter of an island"""


def island_perimeter(grid):
    """ island perimeter function """
    c = 0
    if grid:
        lenr = len(grid[0])
        leng = len(grid)
        for id1, row in enumerate(grid):
            for id2, place in enumerate(row):
                if place:
                    if id1 == 0:
                        c += 1
                    else:
                        if not grid[id1 - 1][id2]:
                            c += 1
                    if id1 >= leng - 1:
                        c += 1
                    else:
                        if not grid[id1 + 1][id2]:
                            c += 1
                    if id2 == 0:
                        c += 1
                    else:
                        if not row[id2 - 1]:
                            c += 1
                    if id2 >= lenr - 1:
                        c += 1
                    else:
                        if not row[id2 + 1]:
                            c += 1
    return c

