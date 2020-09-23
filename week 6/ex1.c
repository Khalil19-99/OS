#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void main() {

  int burst_time[32] = {0}, arrival_time[32] = {0};
  int complete_time[32] = {0}, turnaround_time[32] = {0},
      waiting_time[32] = {0};
  int n, sum = 0;
  float total_turnaround_time = 0, total_waiting_time = 0;

  printf("Number of processes : ");
  scanf("%d", &n);

  printf("\n enter arrival time and burst time:\n");

  // input data
  for (int i = 0; i < n; i++) {
    printf("P[%d] arrival time: ", i + 1);
    scanf("%d", &arrival_time[i]);
    printf("P[%d] burst time: ", i + 1);
    scanf("%d", &burst_time[i]);
    printf("\n");
  }

  // sorting our data by arrival time (using bubble sort e.g.)
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arrival_time[j] > arrival_time[j + 1]) {
        swap(&arrival_time[j], &arrival_time[j + 1]);
        swap(&burst_time[j], &burst_time[j + 1]);
      }
    }
  }

  // completion time calculation
  for (int j = 0; j < n; j++) {
    sum += burst_time[j];
    complete_time[j] = sum;
  }

  // turnaround time calculation
  for (int k = 0; k < n; k++) {
    turnaround_time[k] = complete_time[k] - arrival_time[k];
    total_turnaround_time += turnaround_time[k];
  }

  // waiting time calculation
  for (int k = 0; k < n; k++) {
    waiting_time[k] = turnaround_time[k] - burst_time[k];
    total_waiting_time += waiting_time[k];
  }

  printf("Process\tAT\tBT\tCT\tTAT\tWT\t\n");
  for (int i = 0; i < n; i++)
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, arrival_time[i], burst_time[i],
           complete_time[i], turnaround_time[i], waiting_time[i]);

  printf("\nAverage turnaround time = %f\n", total_turnaround_time / n);
  printf("Averag waiting time = %f\n", total_waiting_time / n);
}
