#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main() {
  struct stat buffer;
  int s_fd;
  int d_fd;
  char *source_file;
  char *destination_file;

  s_fd = open("ex1.txt", O_RDWR);

  fstat(s_fd, &buffer);
  source_file = mmap(NULL, buffer.st_size, PROT_READ, MAP_PRIVATE, s_fd, 0);

  d_fd = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0664);

  ftruncate(d_fd, buffer.st_size);

  destination_file = mmap(NULL, buffer.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, d_fd, 0);

  memcpy(destination_file, source_file, buffer.st_size);

  munmap(source_file, buffer.st_size);

  munmap(destination_file, buffer.st_size);

  close(s_fd);
  close(d_fd);
}
