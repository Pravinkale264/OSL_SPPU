#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_mutex_t wr,mutex;
int a=10,readcount=0;

void * reader(void *arg){
    long int num;
    num=(long int ) arg;

    pthread_mutex_lock(&mutex);
        readcount++;
    pthread_mutex_unlock(&mutex);

    if(readcount==1){
        pthread_mutex_lock(&wr);
    }

    printf("\n Reader %ld is in critical section",num);
    printf("\nReader %ld is reading data %d",num,a);
    sleep(1);
    pthread_mutex_lock(&mutex);
    readcount--;
    pthread_mutex_unlock(&mutex);
    if(readcount==0){
        pthread_mutex_unlock(&wr);
    }

    printf("\n Reader %ld left critical section",num);


}

void * writer(void *arg){
    long int num;
    num=(long int ) arg;

    // lock wr variables to enter cs
    pthread_mutex_lock(&wr);

    printf("\n writer %ld is in critical section",num);
    printf("\n Writer %ld has written data as %d",num,++a);
    sleep(1);
    // writer releases a lock on Wr

    pthread_mutex_unlock(&wr);
    printf("\n Writer %ld left critica section",num);
}


int main()
{
    pthread_t r[10],w[10];
    long int i,j;
    int nor,now;

    // initialize mutex variables
    pthread_mutex_init(&wr,NULL);
    pthread_mutex_init(&mutex,NULL);

    // read input data
    printf("Enter number of readers and writers");
    scanf("%d %d",&nor,&now);

    // Create reader and writer threads

    for (i = 0; i < nor; i++)
    {
        pthread_create(&r[i],NULL,reader,(void *)i);
    }
    for (j = 0; j < now; j++)
    {
        pthread_create(&w[j],NULL,writer,(void *)j);
    }
    //  join the threads
    for (int i = 0; i < nor; i++)
    {
       pthread_join(r[i],NULL);
    }
    for (j = 0; j < now; j++)
    {
       pthread_join(w[j],NULL);
    }
    
    return 0;

}