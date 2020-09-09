#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <sys/types.h>
int main(void)
{
    pid_t pid;
    pid=fork();
    int n =10;
    for(int i=0;i<=n;++i)
    {
        if(pid>0)
        {
            printf("Hello from parent [%d -%d]\n",pid,i);

        }else if (pid==0){
            printf("Hello from child [%d -%d]\n",pid,i);


        }else {
        return EXIT_FAILURE;
        }

    }
    return EXIT_SUCCESS;
}

// Each line in the output will be depending on the PID values, and they are not the same, so each line in the output and the order of them will be different
// OS will control the schedule of the different processes.
// What does the OS do? it copies memory when a program will write into it.
