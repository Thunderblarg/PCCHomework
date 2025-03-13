#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define HORDE_SIZE 1000
// #define MONSTER_SPAWNERS 10
#define DEFENDING_FORCES 10

const char* UNIT[] = {
    "ALPHA",
    "BRAVO",
    "CHARLIE",
    "DELTA",
    "ECHO",
    "FOX",
    "GOLF",
    "HOTEL",
    "INDIA",
    "JULIET",
    "KILO",
    "LIMA",
    "MIKE",
    "NOVEMBER",
    "OSCAR",
    "PAPA",
    "QUEEN",
    "ROMEO",
    "SIERRA",
    "TANGO",
    "UNICORN",
    "VICTOR",
    "WHISKEY",
    "YANKEE",
    "ZULU"
};

struct monster {
    int health;
};

struct threadData {
    struct monster** army;
    int unitLabel;
};

pthread_mutex_t mutex;
sem_t readyForBriefing;

void millisleep(int ms) {
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;

    nanosleep(&ts, NULL);  
}

static int frontLines = 0;


void* summonArmy(void* arg){
    struct monster* m = (struct monster*)arg;
    m->health = 1;
    int randall = rand() % 69;
    for(int idx = 0; idx < randall; idx++){
        printf(" ");
    }
    printf("raaargh\n");
    return NULL;
}


void engageArmy(void* arg){
    int label = ((struct threadData*)arg)->unitLabel;

    while(frontLines < HORDE_SIZE){
        sem_wait(&readyForBriefing);

        int orders = getBattlePlans(label);
        if(orders >= 0){
            printf("Orders received! Unit %s engaging the enemy at sector %d!\n", UNIT[label] ,orders);

            for(int idx = 0; idx < 10; idx++){                
                millisleep((rand() % 10) * 10);
                printf("%s: Target destroyed!\n", UNIT[label]);
                struct monster** enemySquad = ((struct threadData*)arg)->army;
                enemySquad[orders + idx]->health = enemySquad[orders + idx]->health ? 0
                                                                                    : 1;
            }
        }
    }
    printf("%s: Hooray! Victoly!\n", UNIT[label]);
    free(((struct threadData*)arg));
}

int getBattlePlans(int label){
    printf("Unit %s is being briefed!\n", UNIT[label]);
    pthread_mutex_lock(&mutex);
    int orders;

    if(frontLines < HORDE_SIZE){
        orders = frontLines;
        frontLines += 10;
        millisleep((rand() % 25) * 10);
    }
    else {
        orders = -1;
    }
    
    pthread_mutex_unlock(&mutex);
    printf("Unit %s is ready!\n", UNIT[label]);
    sem_post(&readyForBriefing);
    
    return orders;
}

int main(){
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);

    struct monster** army = malloc(sizeof(struct monster*) * HORDE_SIZE);
    for(int idx = 0; idx < HORDE_SIZE; idx++){
        army[idx] = malloc(sizeof(struct monster));
    }

    for(int idx = 0; idx < HORDE_SIZE; idx++){
        summonArmy(army[idx]);
    }
    printf("ARISE MY GOBLIN ARMY, AND LAY WASTE\n");

    sem_init(&readyForBriefing, 0, 1);
    
    pthread_t defenders[DEFENDING_FORCES];

    for(int idx = 0; idx < DEFENDING_FORCES; idx++){
        struct threadData* data = malloc(sizeof(struct threadData));
        data->army = army;
        data->unitLabel = idx;
        pthread_create(&defenders[idx], NULL, engageArmy, data);
    }

    for(int idx = 0; idx < DEFENDING_FORCES; idx++){
        pthread_join(defenders[idx], NULL);
    }
    
    printf("\nCheck the bodies!\n\n");
    // If we find any live ones, we messed up. We take no prisoners
    for(int idx = 0; idx < HORDE_SIZE; idx++){
        if((army[idx]->health) > 0){
            printf("Monster #%d health: %d\n", idx, army[idx]->health);
        }
        else{
            free(army[idx]);
        }
    }
    
    printf("If we haven't found any bodies, we win!\n");

    free(army);    
    sem_destroy(&readyForBriefing);
    pthread_mutex_destroy(&mutex);

    return 0;
}

