#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * show(void*u)
{
printf("thread is created\n");
}
int main (){
    pthread_t tid;
    for(int i=0;i<3;++i){
        pthread_create(&tid,NULL,&show,NULL);
        printf("Thread number :%d\n",i);
    }
    pthread_join(tid,NULL); 
    return 0;
}

/**
this demonstraites that pthread_join can strict thread to run sequentially, or to demostraite, 
that threads, if they run silmutaneously, can wake up in different times.
**/