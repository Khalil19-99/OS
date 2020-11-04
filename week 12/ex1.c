#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void main() {
  FILE *in = fopen("/dev/random", "r");
  char str[21];
  fgets(str, 20, in);
  str[20] = 0;
  printf("%s", str);
}
