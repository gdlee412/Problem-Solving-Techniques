#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NFLOORS 100	//buiding height in floors
#define MAX_RIDERS 500 //elevator capacity

int stops[MAX_RIDERS]; //floor that each passenger gets off
int nriders; //num of riders
int nstops; //num of allowed stops
int MAXINT = 100000; //a decently sized maxint
int count = 0; //

int m[NFLOORS + 1][MAX_RIDERS]; //dynamic programming cost table
int p[NFLOORS + 1][MAX_RIDERS]; //dynamic programming parent table

int min(int a, int b)
{
	if(a < b)
	{
		return a;
	}
	
	return b;
}

int floors_walked(int previous, int current)
{
	int nsteps = 0;
	int i;
	
	for(i = 0; i < nriders; i++)
	{
		if((stops[i] > previous) && (stops[i] <= current))
		{
			nsteps += min(stops[i] - previous, current - stops[i]);
		}
	}
	return nsteps;
}

int optimize_floors()
{
	int i, j, k;
	int cost;
	int laststop;
	
	for(i = 0; i <= NFLOORS; i++)
	{
		m[i][0] = floors_walked(0, MAXINT);
		p[i][0] = -1;
	}
	
	for(j = 1; j <= nstops; j++)
	{
		for(i = 0; i <= NFLOORS; i++)
		{
			m[i][j] = MAXINT;
			for(k = 0; k <= i; k++)
			{
				cost = m[k][j - 1] - floors_walked(k, MAXINT) + floors_walked(k, i) + floors_walked(i, MAXINT);
				if(cost <= m[i][j])
				{
					m[i][j] = cost;
					p[i][j] = k;
				} 
			}
		}
	}
	
	laststop = 0;
	for(i = 1; i <= NFLOORS; i++)
	{
		if(m[i][nstops] <= m[laststop][nstops])
		{
			laststop = i;
		}
	}
	
	return laststop;
}

void reconstruct_path(int lastfloor, int stops_to_go, int floor[])
{
	if(stops_to_go > 1)
	{
		reconstruct_path(p[lastfloor][stops_to_go], stops_to_go - 1, floor);
	}
	
	floor[count] = lastfloor;
	count++;
}

int main()
{
	scanf("%d", &nriders);
	scanf("%d", &nstops);
	
	int floor[nstops];
	
	for(int i = 0; i < nriders; i++)
	{
		scanf("%d", &stops[i]);
	}
	
	int opt = optimize_floors();
	
	reconstruct_path(opt, nstops, floor);
	
	for(int i = 0; i < nriders; i++)
	{
		int temp_min = MAXINT;
		int temp_floor;
		for(int j = 0; j < nstops; j++)
		{
			if(abs(stops[i] - floor[j]) <= temp_min)
			{
				temp_min = abs(stops[i] - floor[j]);
				temp_floor = floor[j];
			}
		}
		printf("%d\n", temp_floor);
	}
}
