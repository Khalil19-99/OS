#include <stdio.h>
#include <limits.h>

int number_of_pages;

int find_old_page(int age[]) {
  int min = INT_MAX;
  int min_index = 0;

  for (int i = 0; i < number_of_pages; i++) {
    if (min > age[i]) {
      min = age[i];
      min_index = i;
    }
  }

  return min_index;
}

void increase_age(int age[], int number, int frame[]) {
  for (int i = 0; i < number_of_pages; i++) {
    if (frame[i] == number)
      age[i] = INT_MAX;
    else
      age[i] = age[i] >> 1;
  }
}

int check_presence(int number, int frame[]) {
  for (int i = 0; i < number_of_pages; i++)
    if (frame[i] == number)
      return 1;

  return 0;
}

int main() {
  int number, hit, miss;

  printf("N: ");
  scanf("%d", &number_of_pages);

  int frame[number_of_pages];
  int age[number_of_pages];

  for (int i = 0; i < number_of_pages; ++i) {
    age[i] = 0;
    frame[i] = 0;
  }

  FILE *input = fopen("input.txt", "r");

  while (fscanf(input, "%d", &number) != EOF) {
    int check_flag = check_presence(number, frame);

    if (check_flag) {
      hit++;
      increase_age(age, number, frame);
    } else {
      miss++;
      int old_page = find_old_page(age);
      frame[old_page] = number;
      age[old_page] = 0;
      increase_age(age, number, frame);
    }
  }

  fclose(input);

  printf("HIT :) %d\n", hit);
  printf("MISS :( %d\n", miss);
  printf("H/M ratio: %lf\n", ((double)hit / (double)miss));
}