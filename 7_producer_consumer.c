#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
sem_t empty, full;
pthread_mutex_t mutex;

int buffer[5];
int count = 0;

void *producer(void *arg) {
    long int num = (long int) arg;
    
    sem_wait(&empty);
        
        pthread_mutex_lock(&mutex);
            buffer[count]=rand() % 10;
            printf("\nProducer %ld produced: %d", num+1, buffer[count]);
            count++;
        pthread_mutex_unlock(&mutex);
        
    sem_post(&full);
    pthread_exit(NULL);
        
}

void *consumer(void *arg) {
    long int num = (long int) arg;
    
    sem_wait(&full);
        
        pthread_mutex_lock(&mutex);
            count--;
            printf("\nconsumer %ld consumed: %d", num+1, buffer[count]);
        pthread_mutex_unlock(&mutex);
        
    sem_post(&empty);
    pthread_exit(NULL);
        
}

int main() {
    int np, nc;
    pthread_t p[10], c[10];
    
    long int i, j;
    
    printf("\nEnter no of producers and consumers: ");
    scanf("%d %d", &np, &nc);
    
    // init semaphore var
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);
    // declaration of mutex
    pthread_mutex_init(&mutex, NULL);
    
    // create producer thread
    for(i = 0; i < np; i++) {
        pthread_create(&p[i], NULL, producer, (void *)i);
    }
    // create consumer thread
    for(i = 0; i < nc; i++) {
        pthread_create(&c[i], NULL, consumer, (void *)i);
    }
    // join producer thread
    for(i = 0; i < np; i++) {
        pthread_join(p[i], NULL);
    }
    // join consumer thread
    for(i = 0; i < nc; i++) {
        pthread_join(c[i], NULL);
    }
    
    return 0;
}