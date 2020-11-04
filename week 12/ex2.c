#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char **argv) {
  int a_flag = 0;
  if (!strcmp(argv[1], "-a"))
    a_flag = 1;
  int input = open("/dev/stdin", O_RDONLY);
  int output = open("/dev/stdou", O_WRONLY);
  int file = 0;
  if (a_flag)
    file = open(argv[2], O_APPEND | O_WRONLY | O_CREAT, 0666);
  else
    file = open(argv[1], O_WRONLY | O_CREAT, 0666);
  int buf[4096];
  int temp = 0;
  while ((temp = read(input, buf, sizeof(buf)))) {
    write(output, buf, temp); 
    write(file, buf, temp); 
  }
  return 0;
}
