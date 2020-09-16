#include <stdio.h>
#include <pthread.h>
#define N 20 
char s[N];
int Position;
int bConsumerSleeping, bProducerSleeping;
long long int t;
void* Consume(void *x){
    while(1){
        if(bConsumerSleeping)
        continue;
        if (Position==0){
         bConsumerSleeping=1;
         bProducerSleeping=0;   
         continue;
        }
    printf("%c",s[Position]);
    Position--;
    }
    pthread_exit(NULL);
    return NULL;
}

void* Produce(void *x){
    while(1){
        if(bProducerSleeping)
        continue;
        if (Position==20)
        {
            bConsumerSleeping=0;
            bProducerSleeping=1;
            printf("Done production with time %lld\n",t++);
            continue;
        }
        s[Position]='a'+Position;
        Position++;
    }
    pthread_exit(NULL);
    return NULL;
}
int main ()
{
    bConsumerSleeping=1;
    pthread_t tProducer,tConsumer;
    pthread_create(&tProducer,NULL,Produce,NULL);
    pthread_create(&tConsumer,NULL,Consume,NULL);
    while (1);
    return 0;
}
/**
this program demonstrates "producer consumer problem", depends on data synchronization.
this problem can be solved with using mutexes (mutual exclusion) e.g. this code shows, 
that to synchronize producer and consumer speed, we can use two simple integer variables, 
to store activity of both sides, to prevent unexpected behaviour.
if we do not protect this, we can get very strange results, due to unsynchronized threads.
IO load will only postpone the problem, but it will still occur.
**/

