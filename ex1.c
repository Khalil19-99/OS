#include <stdio.h>
int main(){
int* pc;
int c;
c=22;

printf("Address of c:%04x\n",&c);
printf("Value of c:%04x\n\n",c);
pc=&c;
printf("Address of pointer pc:%04x\n",pc);
printf("Content of pointer pc:%04x\n\n",*pc);
c=11;
printf("Address of pointer pc:%04x\n",pc);
printf("Content of pointer pc:%04x\n\n",*pc);
*pc=2;
printf("Address of c:%04x\n",&c);
printf("Value of c:%04x\n\n",c);
return 0;
}
