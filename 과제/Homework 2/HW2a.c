#include <stdio.h>

int main()
{
	int a, b;
	char results[20][21];
	int scores[20] = {0, 0,};
	int i, j;
	
	scanf("%d %d", &a, &b);
	
	for(i = 0; i < 20; i++)
	{
		scanf("%s", results[i]);
	}
	
	for(i = 0; i < 20; i++)
	{
		for(j = 0; j < 20; j++)
		{
			if(results[i][j] == 'W')
			{
				scores[i] += a;
			}
			else if(results[i][j] == 'T')
			{
				scores[i] += b;
			}
		}
		int index = i;
		while(scores[index] > scores[index - 1] && index > 0)
		{
			int temp = scores[index];
			scores[index] = scores[index - 1];
			scores[index - 1] = temp;
			index--;
		}
	}
	
	for(i = 0; i < 20; i++)
	{
		printf("%d\n", scores[i]);
	}
}