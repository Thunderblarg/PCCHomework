#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

struct protectedCounter{
    int counter;
    pthread_mutex_t mutex;
};

void* threadCounter(void* arg){
    struct protectedCounter* c = (struct protectedCounter*) arg;
    pthread_mutex_lock(&c->mutex);
    c->counter = c->counter = 1;
    pthread_mutex_unlock(&c->mutex);

    return NULL;
}

int main(){
    srand(time(NULL));

    pthread_t threads[10];
    struct protectedCounter c1;
    c1.counter = 0;
    pthread_mutex_init(&c1.mutex, NULL);

    struct protectedCounter c2;
    c2.counter = 0;
    pthread_mutex_init(&c2.mutex, NULL);

    for(int idx = 0; idx < 10; idx++){
        if(idx % 2 == 1){
            pthread_create(&threads[idx], NULL, threadCounter, &c1);
        }
        else {
            pthread_create(&threads[idx], NULL, threadCounter, &c2);
        }
    }

    for(int idx = 0; idx < 10; idx++){
        pthread_join(threads[idx], NULL);
    }

    printf("The value of our first mutex is %d\n", c1.counter);
    printf("The value of our first mutex is %d\n", c2.counter);

    return 0;
}