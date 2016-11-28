#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define N 5
#define lf n
#define rf (n+1)%N
int i;
sem_t s[N];
pthread_t p[N];

void think(int n)
{
	printf("\nPhilosopher %d is thinking",n);
	sleep(1);
}

void hungry(int n)
{
	printf("\nPhilosopher %d is hungry",n);
	sleep(1);
}

void finished(int n)
{
	printf("\nPhilosopher %d finished eating\n",n);
	sleep(1);
}

void philo(int n)
{
	think(n);
	sleep(1);
	hungry(n);
	sem_wait(&s[lf]);
	sem_wait(&s[rf]);
	printf("\nPhilosopher %d is eating",n);
	sleep(1);
	sem_post(&s[lf]);
	sem_post(&s[rf]);
	finished(n);
}

main()
{
	for(i=0;i<5;i++)
		sem_init(&s[i],0,1);
	for(i=0;i<5;i++)
		pthread_create(&p[i],NULL,(void *)philo,(int)i);
	for(i=0;i<5;i++)	
		pthread_join(p[i],NULL);
}

