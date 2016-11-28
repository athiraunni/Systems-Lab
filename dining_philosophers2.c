#include<stdio.h>
#include<pthread.h>
#include<stdio.h>

pthread_mutex_t forks[5] ;
void *sim(void *p)
{
    int i = (int)p;
    while(1)
    {
        printf("Philosopher %d is hungry\n",i);
        if(i == 4)
        {
		    pthread_mutex_lock(&forks[0]);
		    printf("Philosopher %d taking right fork\n",i);
		    sleep(1);
		    if(pthread_mutex_trylock(&forks[4]))
        	{
         		pthread_mutex_unlock(&forks[0]);
          		printf("Philosopher %d returning right fork\n",i); 
        	}
            else
            {
                printf("Philosopher %d taking left fork\n",i);
                sleep(1);
                printf("Philosopher %d eating\n",i);
                sleep(1);
                pthread_mutex_unlock(&forks[0]);
                printf("Philosopher %d returning right fork\n",i);
                pthread_mutex_unlock(&forks[4]);
                printf("Philosopher %d returning left fork\n",i);
                printf("Philosopher %d is thinking\n",i);
                sleep(1);
            }
        }
        else
        {    
            pthread_mutex_lock(&forks[i]);
            printf("Philosopher %d taking left fork\n",i);
            sleep(1);
            if(pthread_mutex_trylock(&forks[(i+1)%5]))
            {
                 pthread_mutex_unlock(&forks[i]);
                 printf("Philosopher %d returning left fork\n",i); 
            }
            else
            {
                printf("Philosopher %d taking right fork\n",i);
                sleep(1);
                printf("Philosopher %d eating\n",i);
                sleep(1);
                pthread_mutex_unlock(&forks[i]);
                sleep(1);
                printf("Philosopher %d returning left fork\n",i);
                pthread_mutex_unlock(&forks[(i+1)%5]);
                printf("Philosopher %d returning right fork\n",i);
                printf("Philosopher %d is thinking\n",i);
                sleep(1);
            }
        }
    }
}

int main()
{
    int i;
    pthread_t philosopher[5];

    for(i=0;i<5;++i)
    {
        pthread_mutex_unlock(&forks[i]);
    }
    for(i=0;i<5;++i)
        pthread_create(&philosopher[i],NULL,sim, (void *)i);

    for(i=0;i<5;++i)
        pthread_join(philosopher[i],NULL);        
    
    return 0;

}
