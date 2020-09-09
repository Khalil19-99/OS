#include <stdio.h>
#include <stdlib.h>
void read_command (char *command)
{
  scanf("%s",command);
}
int main()
{
char command[20];
while(1){
    printf("> ");
    read_command(command);
    system(command);
}
    return 0;
}
