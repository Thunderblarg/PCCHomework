#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

int ourCounter = 0;

pthread_mutex_t mutex;

void* threadCounter(void* arg){
    pthread_mutex_lock(&mutex);
    int temp = ourCounter;
    sleep(rand()%3+1);
    ourCounter = temp+1;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(){
    srand(time(NULL));
    pthread_t threads[10];
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < 10; i++){
        pthread_create(&threads[i], NULL, threadCounter, NULL);
    }

    for(int i = 0; i<10; i++){
        pthread_join(threads[i], NULL);
    }

    printf("The value of our counter is %d\n", ourCounter);
}