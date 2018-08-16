/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:50:09 by wweng             #+#    #+#             */
/*   Updated: 2018/08/05 20:55:25 by wweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int				isavailable(int puzzle[][9], int row, int col, int num)
{
	int i;
	int colstart;
   	int rowstart;

	rowstart = (row / 3) * 3;
	colstart = (col / 3) * 3;
	i = 0;
	while (i < 9)
	{
		if (puzzle[row][i] == num)
			return (0);
		if (puzzle[i][col] == num)
			return (0);
		if (puzzle[rowstart + (i % 3)][colstart + (i / 3)] == num)
			return (0);
		i++;
	}
	return (1);
}

int				fillsudoku(int puzzle[][9], int row, int col)
{
	int i;

	if (row < 9 && col < 9)
	{
		if (puzzle[row][col] != 0)
		{
			if ((col + 1) < 9)
				return (fillsudoku(puzzle, row, col + 1));
			else if ((row + 1) < 9)
				return (fillsudoku(puzzle, row + 1, 0));
			else
				return (1);
		}
		else
		{
			i = 0;
			while (i < 9)
			{
				if (isavailable(puzzle, row, col, i + 1))
				{
					puzzle[row][col] = i + 1;
					if ((col + 1) < 9)
					{
						if (fillsudoku(puzzle, row, col + 1))
							return (1);
						else
							puzzle[row][col] = 0;
					}
					else if ((row + 1) < 9)
					{
						if (fillsudoku(puzzle, row + 1, 0))
							return (1);
						else
							puzzle[row][col] = 0;
					}
					else
						return (1);
				}
				i++;
			}
		}
		return (0);
	}
	else
	{
		return (1);
	}
}

int				main(int argc, char **argv)
{
	int i;
	int j;
	int puzzle[9][9] = {
    	{9, 0, 0, 0, 7, 0, 0, 0, 0},
		{2, 0, 0, 0, 9, 0, 0, 5, 3},
		{0, 6, 0, 0, 1, 2, 4, 0, 0},
		{8, 4, 0, 0, 0, 1, 0, 9, 0},
		{5, 0, 0, 0, 0, 0, 8, 0, 0},
		{0, 3, 1, 0, 0, 4, 0, 0, 0},
		{0, 0, 3, 7, 0, 0, 6, 8, 0},
		{0, 9, 0, 0, 5, 0, 7, 4, 1},
		{4, 7, 0, 0, 0, 0, 0, 0, 0}
    };

	if (fillsudoku(puzzle, 0, 0))
	{
		while (i < 10)
		{
			while (j < 10)
			{
				printf("%d ", puzzle[i - 1][j - 1]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
	else
		printf("\n\nNO SOLUTION\n\n");
	return (0);
}

