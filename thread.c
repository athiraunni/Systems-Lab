#include<pthread.h>
#include<stdio.h>
#define NUM 5
int *printhello(int * tid)
{
	printf("Hellow it's me : %d\n",(int)tid);
	pthread_exit(NULL);
}
int main()
{
	pthread_t thread[NUM];
	int rc;
	long t;
	
	for(t=0;t<NUM;t++)
	{
		printf("\n main creating thread %ld\n",t);
	
		rc=pthread_create(&thread[t],NULL,&printhello,(int *)t);
		if(rc)
		{
			printf("ERROR:thread is %d",rc);
			return 0;
		}
	}
		pthread_exit(NULL);
}
