// Bankers Algorithm : 10/03/2015
#include<stdio.h>
int count=0,i,j,k=1,exec,p=0,r=0;
int alloc[5]={0,0,0,0,0};
int current[5][5],maxclaim[5][5],avail[5];
int maxres[5],running[5],safe=0;

main()
{
	printf("\nEnter the no. of processes : ");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		running[i]=1;
		count++;	
	}
	
	printf("\nEnter the no.of resources : ");
	scanf("%d",&r);
	for(i=0;i<r;i++)
	{
		printf("\nEnter the resources for instance %d : ",k++);
		scanf("%d",&maxres[i]);
	}
	
	printf("\nEnter maximum resource table : ");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&maxclaim[i][j]);
		}
	}
	
	printf("\nEnter allocated resource table : ");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&current[i][j]);
		}
	}
	
	printf("\nThe resources of instances : ");
	for(i=0;i<r;i++)
	{
		printf("%d",maxres[i]);
	}
	
	printf("\nThe allocated resource table : ");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d",current[i][j]);
		}
		printf("\n");
	}
	
	printf("\nThe maximum resource table : ");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d",maxclaim[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			alloc[j] = alloc[j] + current[i][j];
		}
	}
	
	printf("\nAllocated resources : ");
	for(i=0;i<r;i++)
	{
		printf("%d",alloc[i]);
	}
	
	for(i=0;i<r;i++)
	{
		avail[i] = maxres[i] - alloc[i];
	}
	
	printf("\nAvailable resources : ");
	for(i=0;i<r;i++)
	{
		printf("%d",avail[i]);
	}
	
	printf("\n");
	
	while(count!=0)
	{
		safe = 0;
		for(i=0;i<p;i++)
		{
			if(running[i])
			{
				exec = 1;
				for(j=0;j<r;j++)
				{
					if(maxclaim[i][j]-current[i][j] > avail[j])
					{
						exec = 0;
						break;
					}
				}	
				if(exec)
				{
					printf("Process %d is executing ",i+1);
					running[i]=0;
					count--;
					safe = 1;
					for(j=0;j<r;j++)
					{
						avail[j] = avail[j] + current[i][j];
					}
					break;
				}
			}
		}
		if(!safe)
		{
			printf("The processees are in unsafe state !!");
			break;
		}
		else
		{
			printf("The processes are in safe state..\n");
			printf("Safe sequence is : ");
			for(i=0;i<r;i++)
			{
				printf("%d",avail[i]);
			}
			printf("\n");
		}
	}
}	
