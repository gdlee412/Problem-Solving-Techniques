#include <stdio.h>

int main()
{
	int x, y, i;
	int max = 0;
	
	scanf("%d %d", &x, &y);
	
	for(i = x; i <= y; i++)
	{
		int n = i;
		int count = 0;
		
		while(n != 1)
		{
			if(n % 2 != 0)
			{
				n = 3 * n + 1;
			}
			
			else
			{
				n /= 2;
			}
			count++;
		}
		count++;
		
		if(count > max)
		{
			max = count;
		}
	}
	
	printf("%d %d %d", x, y, max);
	
	return 0;
}