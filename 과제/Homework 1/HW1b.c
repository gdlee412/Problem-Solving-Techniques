#include <stdio.h>

int value_exists(int existing_values[], int value, int size);

int main()
{
	int n, i, j;
	
	//matrix size
	scanf("%d", &n);
	
	int matrix[n][n], existing_values[n * n];
	int unique_number_count = 0;
	
	//initialize matrix
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
		}
	}
	
	//receive and input data for first diagonal
	for(i = 0; i < n; i++)
	{
		int element;
		scanf("%d", &element);
		
		matrix[i][i] = element;
		existing_values[unique_number_count] = element;
		unique_number_count++;
		
		if(i != 0 && matrix[i][i] - matrix[i - 1][i - 1] < 3)
		{
			printf("Infeasible");
			return 0;
		}
	}
	
	//receive and input data for second diagonal
	for(i = 0; i < n; i++)
	{
		int element;
		scanf("%d", &element);
		
		// disregard the middle element if n is odd
		if(n % 2 == 1 && i == n / 2)
		{
			continue;
		}
		else
		{
			matrix[n - 1 - i][i] = element;
			existing_values[unique_number_count] = element;
			unique_number_count++;
			
			//check if there are enough numbers to insert between the variables
			int diagonal_difference = abs(element - matrix[n - 1 - i][n - 1 - i]);
			int vertical_diagonal_difference = abs(element - matrix[i][i]);
			int number_of_gaps = abs(n - 1 - 2 * i) - 1;
			
			if(diagonal_difference < number_of_gaps || vertical_diagonal_difference < number_of_gaps)
			{
				printf("Infeasible");
				return 0;
			}
			else if(diagonal_difference == number_of_gaps)
			{
				for(j = i + 1; j < n - 1 - i; j++)
				{
					matrix[i][j] = matrix[i][j - 1] + 1;
					existing_values[unique_number_count] = element;
					unique_number_count++;
				}
			}
			else if(vertical_diagonal_difference == abs(n - 1 - 2 * i) - 1)
			{
				for(j = i + 1; j < n - 1 - i; j++)
				{
					matrix[i][j] = matrix[i][j - 1] + 1;
					existing_values[unique_number_count] = element;
					unique_number_count++;
				}
			}
		}
	}
	
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			//if it is a diagonal element, skip
			if(i == j || i + j == n - 1)
			{
				continue;
			}
			else
			{
				//case 1: to the right of the diagonal entries && left of antidiagonal entries
				if(j > i && i + j < n - 1)
				{
					matrix[i][j] = matrix[i][i];
					
					while(value_exists(existing_values, matrix[i][j], n * n) == 1)
					{
						matrix[i][j]++;
						int increment = 1;
						int comparing_element = 0;
						while(comparing_element == 0)
						{
							comparing_element = matrix[i + increment][j];
							increment++;
						}
						
						if(matrix[i][j] >= comparing_element)
						{
							printf("Infeasible");
							return 0;
						}
					}	
					existing_values[unique_number_count] = matrix[i][j];
					unique_number_count++;	
				}
				
				//case 2: to the left of both diagonal and antidiagonal entries
				else if(j < i && i + j < n - 1)
				{
					matrix[i][j] = matrix[i - 1][j];
					
					while(value_exists(existing_values, matrix[i][j], n * n) == 1)
					{
						matrix[i][j]++;
						int increment = 1;
						int comparing_element = 0;
						while(comparing_element == 0)
						{
							comparing_element = matrix[i][j + increment];
							increment++;
						}
						
						if(matrix[i][j] >= comparing_element)
						{
							printf("Infeasible");
							return 0;
						}
					}
					existing_values[unique_number_count] = matrix[i][j];
					unique_number_count++;
				}
				
				
				//case 3: to the right of both diagonal and antidiagonal entries
				else if(j > i && i + j > n - 1)
				{
					matrix[i][j] = matrix[i - 1][j];
					
					while(value_exists(existing_values, matrix[i][j], n * n) == 1)
					{
						matrix[i][j]++;
						int increment = 1;
						int comparing_element = 0;
						while(comparing_element == 0)
						{
							comparing_element = matrix[i][j - increment];
							increment++;
						}
						while(matrix[i][j] <= comparing_element)
						{
							matrix[i][j]++;
						}
						
						//compare with diagonal entry in the same column
						if(matrix[i][j] >= matrix[j][j])
						{
							printf("Infeasible");
							return 0;
						}
					}
					existing_values[unique_number_count] = matrix[i][j];
					unique_number_count++;
				}
				
				//case 4: left of antidiagonal entries and right of diagonal entries
				else if(j < i && i + j > n - 1)
				{
					matrix[i][j] = matrix[i][j - 1];
					
					while(value_exists(existing_values, matrix[i][j], n * n) == 1)
					{
						matrix[i][j]++;
						int increment = 1;
						int comparing_element = 0;
						while(comparing_element == 0)
						{
							comparing_element = matrix[i - increment][j];
							increment++;
						}
						
						while(matrix[i][j] <= comparing_element)
						{
							matrix[i][j]++;
						}
						
						//compare with diagonal entry in the same column
						if(matrix[i][j] >= matrix[i][i])
						{
							printf("Infeasible");
							return 0;
						}
					}
					existing_values[unique_number_count] = matrix[i][j];
					unique_number_count++;
				}
				
			}
		}
	}
	
	//print matrix
	for(i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

int value_exists(int existing_values[], int value, int size)
{
	for(int i = 0; i < size; i++)
	{
		if(existing_values[i] == value)
		{
			return 1;
		}
	}
	
	return 0;
}