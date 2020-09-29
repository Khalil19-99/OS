#include <stdio.h>
int main() {
  char **s;
  char *foo = "Hello World";
  s = &foo; 
  printf("s is %s\n", *s); // get string by ptr
  s[0] = foo; // s[0] is poiting to string
  printf("s[0] is %s\n", s[0]);
  return (0);
}
