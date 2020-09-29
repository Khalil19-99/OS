#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *crutch_realloc(void *ptr, int size) {
  if (!ptr)
    return (int *)malloc(size*sizeof(int)); // allocate memory
  else {
    if (!size) {
      free(ptr);
      return NULL; // always null ptr
    } else {
      int *temp = (int *)malloc(size*sizeof(int)); // now our new allocated space filled with zeros
      memcpy(temp, ptr, size * sizeof(int));
      return temp;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n); //Size of array

  int *m = (int *)malloc(n*sizeof(int));

  printf("Source array:\n");
  for (int i = 0; i < n; i++) {
    m[i] = i;
    printf("%d ", m[i]);
  }

  int n1;
  scanf("%d", &n1); //New size of array

  m = crutch_realloc(m, n1); 

  for (int i = n; i < n1; i++)
    m[i] = i;

  printf("New array:\n");
  for (int i = 0; i < n1; i++)
    printf("%d ", m[i]);

  free(m);
  m = NULL; // always null ptr
  return 0;
}
