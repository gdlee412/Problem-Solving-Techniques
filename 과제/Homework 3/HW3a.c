#include <stdio.h>
#define MAX 10

int main()
{
	int source_row, source_col, dest_row, dest_col;
	int matrix[MAX][MAX];
	
	//scan
	scanf("%d %d %d %d", &source_row, &source_col, &dest_row, &dest_col);
	
	//match the usual indices for arrays (0 - N)
	source_row -= 1;
	source_col -= 1;
	dest_row -= 1;
	dest_col -= 1;
	
	//array size of the minimum possible pathways
	int sum_row = dest_row - source_row + 1;
	int sum_col = dest_col - source_col + 1;
	//sum of going to a certain path
	int sum[sum_row][sum_col];
	// xxyy: (to consider 10)
	// xx = row val
	// yy = col val
	int derived_graph[sum_row][sum_col];
	//number of zeroes passed by going to that index
	int zero_graph[sum_row][sum_col];
	
	//initialize
	for(int i = 0; i < sum_row; i++)
	{
		for(int j = 0; j < sum_col; j++)
		{
			zero_graph[i][j] = 0;
		}
	}
	
	//scan for the matrix
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	
	//calculate all the arrays
	for(int i = 0; i < sum_row; i++)
	{
		for(int j = 0; j < sum_col; j++)
		{
			//starting index
			if(i == 0 && j == 0)
			{
				sum[i][j] = matrix[i + source_row][j + source_col];
				derived_graph[i][j] = (i + source_row) * 100 + j + source_col + 101;
				if(matrix[i + source_row][j + source_col] == 0)
				{
					zero_graph[i][j]++;
				}
			}
			//first row
			else if(i == 0 && j > 0)
			{
				if(matrix[i + source_row][j + source_col] == -9999)
				{
					sum[i][j] = sum[i][j - 1] - matrix[i + source_row][j + source_col];
				}
				else
				{
					sum[i][j] = sum[i][j - 1] + matrix[i + source_row][j + source_col];
				}
				derived_graph[i][j] = (i + source_row) * 100 + (j - 1) + source_col + 101;
				
				zero_graph[i][j] = zero_graph[i][j - 1];
				if(matrix[i + source_row][j + source_col] == 0)
				{
					zero_graph[i][j]++;
					if(zero_graph[i][j] >= 2)
					{
						sum[i][j] += 9999;
					}
				}
			}
			//first column
			else if(i > 0 && j == 0)
			{
				if(matrix[i + source_row][j + source_col] == -9999)
				{
					sum[i][j] = sum[i - 1][j] - matrix[i + source_row][j + source_col];
				}
				else
				{
					sum[i][j] = sum[i - 1][j] + matrix[i + source_row][j + source_col];
				}
				derived_graph[i][j] = ((i - 1) + source_row) * 100 + j + source_col + 101;
				
				zero_graph[i][j] = zero_graph[i - 1][j];
				if(matrix[i + source_row][j + source_col] == 0)
				{
					zero_graph[i][j]++;
					if(zero_graph[i][j] >= 2)
					{
						sum[i][j] += 9999;
					}
				}
			}
			else
			{
				int row_derived, col_derived;
				int row_zero, col_zero;
				if(matrix[i + source_row][j + source_col] == -9999)
				{
					row_derived = sum[i - 1][j] - matrix[i + source_row][j + source_col];
					col_derived = sum[i][j - 1] - matrix[i + source_row][j + source_col];
				}
				else
				{
					row_derived = sum[i - 1][j] + matrix[i + source_row][j + source_col];
					col_derived = sum[i][j - 1] + matrix[i + source_row][j + source_col];
				}
				
				row_zero = zero_graph[i - 1][j];
				col_zero = zero_graph[i][j - 1];
				if(matrix[i + source_row][j + source_col] == 0)
				{
					row_zero++;
					col_zero++;
				}
				
				if(row_zero >= 2 && col_zero >= 2)
				{
					sum[i][j] += 9999;
					derived_graph[i][j] = (i + source_row) * 100 + (j - 1) + source_col + 101;
					zero_graph[i][j] = col_zero;
				}
				else if(row_zero >= 2 && col_zero < 2)
				{
					sum[i][j] = col_derived;
					derived_graph[i][j] = (i + source_row) * 100 + (j - 1) + source_col + 101;
					zero_graph[i][j] = col_zero;
				}
				else if(row_zero < 2 && col_zero >= 2)
				{
					sum[i][j] = row_derived;
					derived_graph[i][j] = ((i - 1) + source_row) * 100 + j + source_col + 101;
					zero_graph[i][j] = row_zero;
				}
				else
				{
					if(row_derived < col_derived)
					{
						sum[i][j] = row_derived;
						derived_graph[i][j] = ((i - 1) + source_row) * 100 + j + source_col + 101;
						zero_graph[i][j] = row_zero;
					}
					else
					{	
						sum[i][j] = col_derived;
						derived_graph[i][j] = (i + source_row) * 100 + (j - 1) + source_col + 101;
						zero_graph[i][j] = col_zero;
					}
				}
			}
		}
	}
	
	printf("%d\n", sum[sum_row - 1][sum_col - 1]);

	int result[sum_row + sum_col - 1];
	result[sum_row + sum_col - 2] = dest_row * 100 + dest_col + 101;	
	
	for(int i = sum_row + sum_col - 3; i >= 0; i--)
	{
		int col = (result[i + 1] / 100) - source_row - 1;
		int row = (result[i + 1] % 100) - source_col - 1;
		result[i] = derived_graph[col][row];
	}
	
	for(int i = 0; i < sum_row + sum_col - 1; i++)
	{
		printf("%d %d\n", result[i] / 100, result[i] % 100);
	}
	
}