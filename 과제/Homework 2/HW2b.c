#include <stdio.h>

int main()
{
	int a, b, c, d;
	char results[20][20];
	int num_of_ties;
	int i, j;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	for(i = 0; i < 20; i++)
	{
		//num of ties for the rankings for > / >= c
		if(d == 1) 
			num_of_ties = c;
		else 
			num_of_ties = c - 1;
		
		for(j = i; j < 20; j++)
		{
			//diagonal is X
			if(i == j)
			{
				results[i][j] = 'X';
			}
			//have C - 1 number of ties
			else if(num_of_ties - 1 - i > 0)
			{
				results[i][j] = 'T';
				results[j][i] = 'T';
				num_of_ties--;
			}
			//for minimum, everything else is a tie
			else if(i >= num_of_ties)
			{
				results[i][j] = 'T';
				results[j][i] = 'T';
			}
			//remaining are wins
			else
			{
				results[i][j] = 'W';
				results[j][i] = 'L';
			}
		}
	}
		
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			printf("%c", results[i][j]);
		}
		printf("\n");
	}
}