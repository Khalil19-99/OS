#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
for(int i=0;i<5;i++)
{
    fork();
}
sleep(seconds:5);
    return 0;
}

/*
The `pstree` will be the following:
├─zsh───ex2─┬─ex2─┬─ex2───ex2
│           │     └─ex2
│           ├─ex2───ex2
│           └─ex2

first, each instance of `ex2` forks itself then,
Each new process becomes a child of the old process, again and again till the end of the loop
In the end of execution there should be 2^3 = 8 processes.


when the loop is till 5, the tree will contain 2^5=32 processes:

─zsh─┬─ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
     │     │     │     │     └─ex2
     │     │     │     ├─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2─┬─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2───ex2
     │     │     └─ex2
     │     ├─ex2─┬─ex2─┬─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2───ex2
     │     │     └─ex2
     │     ├─ex2─┬─ex2───ex2
     │     │     └─ex2
     │     ├─ex2───ex2
     │     └─ex2

