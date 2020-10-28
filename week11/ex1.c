#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main()
{
    char* text="This is a nice day";
    
    size_t size=strlen(text)+1;
    
    FILE *fp=fopen("ex1.txt","w);
    
    ftruncate(fileno(fp),size-1);
    
    fclose(fp);
    
    int file =open("ex1.txt",O_RDWR);
    char *map;
    map =mmap(NULL,size,PORT_READ|PORT_WRITE,MAP_SHARED,file,0);

    for (size_t i=0;i<size;i++){

        map[i]=text[i];
    }

    return 0;
}
