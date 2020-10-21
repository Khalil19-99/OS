
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void print_other(ino_t inode, char *name) {
  DIR *dp;
  struct stat sbuf;
  struct dirent *entry;
  dp = opendir("/tmp");
  chdir("/tmp");
  while ((entry = readdir(dp)) != NULL) {
    lstat(entry->d_name, &sbuf);
    if (S_ISREG(sbuf.st_mode)) {
      if (strcmp(entry->d_name, name) && sbuf.st_ino == inode) {
        printf("%s: %s\n", name, entry->d_name);
      }
    }
  }
  closedir(dp);
}
void print_main() {
  DIR *dp;
  struct stat sbuf;
  struct dirent *entry;
  dp = opendir("/tmp");
  chdir("/tmp");
  while ((entry = readdir(dp)) != NULL) {
    lstat(entry->d_name, &sbuf);
    if (S_ISREG(sbuf.st_mode)) {
      if (sbuf.st_nlink >= 2) {
        print_other(sbuf.st_ino, entry->d_name);
      }
    }
  }
  closedir(dp);
}

void main() {
  printf("Inode scan:\n");
  print_main();
}
