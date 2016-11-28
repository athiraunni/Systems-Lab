#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define rn 10
#define wn 4

sem_t readwritelock, writewritelock;
int read_count = 0, write_count = 0;

void* reader( void* p )
{

    int n = ( int ) p;
    unsigned int val;

    while(1)
    {
        printf( "Reader %d waiting for reading\n", n );
        while( write_count > 0 );
        if( read_count == 0 )
            sem_wait( &readwritelock );

        read_count++;
        printf( "Reader %d is reading\n", n );
        sleep(1);
        printf( "Reader %d finished reading\n", n );
        read_count--;

        if( read_count == 0 )
            sem_post( &readwritelock );
        sleep(1);
    }
}

void* writer( void *p )
{
    int n = ( int ) p;

    while(1)
    {
        sleep(1);
        write_count++;

        printf( "Writer %d waiting for writing\n", n );
        sem_wait( &readwritelock );
        sem_wait( &writewritelock );
        write_count--;

        printf( "Writer %d is writing\n", n );
        sleep(1);
        printf( "Writer %d finished writing\n", n );
        sem_post( &readwritelock );
        sem_post( &writewritelock );
        sleep(2);
    }
}


int main()
{
    pthread_t read[rn], write[wn];
    int i;

    sem_init( &readwritelock, 0, 1 );
    sem_init( &writewritelock, 0, 1 );

    for( i = 0; i < rn; ++i )
        pthread_create( &read[i], NULL, reader, ( void * )i );

    for( i = 0; i < wn; ++i )
        pthread_create( &write[i], NULL, writer, ( void * )i );

    for( i = 0; i < rn; ++i )
        pthread_join( read[i], NULL );

    for( i = 0; i < wn; ++i )
        pthread_join( write[i], NULL);

    return 0;
}
