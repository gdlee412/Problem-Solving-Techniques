#include <stdio.h>
#define MAX 6

int visited_already(int visited[4][MAX * MAX], int row, int col, int index)
{
	for(int k = 0; k < col; k++)
	{
		if(visited[row][k] == index)
		{
			return 1;
		}
	}
	
	return 0;
}
int main()
{
	int source_row, source_col, dest_row, dest_col;
	int matrix[MAX][MAX];
	int visited[4][MAX * MAX];
	//sum of going to a certain path
	//[0 - 3]: up, left, down, right, respectively
	int sum[4];
	//number of zeroes passed by going to that index
	int zero_count = 0;
	int col_store[4];
	
	//scan
	scanf("%d %d %d %d", &source_row, &source_col, &dest_row, &dest_col);
	
	//match the usual indices for arrays (0 - N)
	source_row -= 1;
	source_col -= 1;
	dest_row -= 1;
	dest_col -= 1;
	
	//scan for the matrix
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	
	for(int i = 0; i < 4; i++)
	{
		int j = 0;
		zero_count = 0;
		int row = source_row;
		int col = source_col;
		visited[i][j] = source_row * 100 + source_col + 101;
		sum[i] = matrix[source_row][source_col];
		if(matrix[source_row][source_col] == 0)
		{
			zero_count++;
		}
		j++;
		
		if(i == 0 && row > 0)
		{
			row--;
		}
		else if(i == 1 && col > 0)
		{
			col--;
		}
		else if(i == 2 && row < 5)
		{
			row++;
		}
		else if(i == 3 && col < 5)
		{
			col++;
		}

		while(1)
		{
			visited[i][j] = row * 100 + col + 101;
			int cur_index = visited[i][j];
			int dest_index = dest_row * 100 + dest_col + 101;
			sum[i] += matrix[row][col];
			j++;
		
			if(cur_index - 100 == dest_index)
			{
				row--;
				continue;
			}
			else if(cur_index - 1 == dest_index)
			{
				col--;
				continue;
			}
			else if(cur_index + 100 == dest_index)
			{
				row++;
				continue;
			}
			else if(cur_index + 1 == dest_index)
			{
				col++;
				continue;
			}
			else if(cur_index == dest_index)
			{
				break;
			}
			
			int candidates[4][2] = {{9999, 0}, {9999, 0}, {9999, 0}, {9999, 0}};
			
			if(row > 0 && visited_already(visited, i, j, (row - 1) * 100 + col + 101) == 0)
			{
				candidates[0][0] = matrix[row - 1][col];
				candidates[0][1] = (row - 1) * 100 + col + 101;
			}
			if(col > 0 && visited_already(visited, i, j, row * 100 + col - 1 + 101) == 0)
			{
				candidates[1][0] = matrix[row][col - 1];
				candidates[1][1] = row * 100 + col - 1 + 101;
			}
			if(row < 5 && visited_already(visited, i, j, (row + 1) * 100 + col + 101) == 0)
			{
				candidates[2][0] = matrix[row + 1][col];
				candidates[2][1] = (row + 1) * 100 + col + 101;
			}
			if(col < 6 && visited_already(visited, i, j, row * 100 + col + 1 + 101) == 0)
			{
				candidates[3][0] = matrix[row][col + 1];
				candidates[3][1] = row * 100 + col + 1 + 101;
			}
			
			int min_index;
			int min = 9999;
			for(int k = 0; k < 4; k++)
			{
				if(candidates[k][0] == -9999)
				{
					continue;
				}
				else if(candidates[k][0] == 0 && zero_count == 1)
				{
					continue;
				}
				
				if(candidates[k][0] < min)
				{
					min = candidates[k][0];
					min_index = candidates[k][1];
				}
			}
			
			if(min == 0)
			{
				zero_count++;
			}
			row = min_index / 100 - 1;
			col = min_index % 100 - 1;
		}
		col_store[i] = j;
	}
	
	int min = 9999;
	int index;
	
	for(int i = 0; i < 4; i++)
	{
		if(sum[i] < min)
		{
			index = i;
			min = sum[i];
		}
	}
	
	printf("%d\n", min);
	for(int i = 0; i < col_store[index]; i++)
	{
		printf("%d %d\n", visited[index][i] / 100, visited[index][i] % 100);
	}
	
}