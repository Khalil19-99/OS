#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  setvbuf(stdout, NULL, _IOLBF, 5);
  printf("%s", "H");
  sleep(1);
  printf("%s", "e");
  sleep(1);
  printf("%s", "l");
  sleep(1);
  printf("%s", "l");
  sleep(1);
  printf("%s", "o");
  sleep(1);

  return 0;
}
