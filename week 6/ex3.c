#include <stdio.h>

// function to help bubble sort e.g.
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {

  int j, n, count;
  int time, remain, time_quantum;
  int switcher = 0;
  int waiting_time = 0, turnaround_time = 0, arrival_time[32], burst_time[32],
      remaining_time[32], complete_time[32];

  printf("Number of processes : ");
  scanf("%d", &n);
  remain = n;
  printf("\nfor each process enter arrival time and burst time:\n");

  // input
  for (count = 0; count < n; count++) {
    printf("P[%d] arrival time: ", count + 1);
    scanf("%d", &arrival_time[count]);
    printf("P[%d] burst time: ", count + 1);
    scanf("%d", &burst_time[count]);
    remaining_time[count] = burst_time[count];
    printf("\n");
  }

  // sort our data by arrival time (using bubble sort e.g.)
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arrival_time[j] > arrival_time[j + 1]) {
        swap(&arrival_time[j], &arrival_time[j + 1]);
        swap(&burst_time[j], &burst_time[j + 1]);
      }
    }
  }

  // input time quantum
  printf("Time quantum: ");
  scanf("%d", &time_quantum);
  printf("\n");

  // proceed with data and print it
  // header
  printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
  for (time = 0, count = 0; remain != 0;) {
    // calculate turnaround and complete time
    if (remaining_time[count] <= time_quantum && remaining_time[count] > 0) {
      time += remaining_time[count];
      remaining_time[count] = 0;
      switcher = 1;
    } else if (remaining_time[count] > 0) {
      remaining_time[count] -= time_quantum;
      time += time_quantum;
    }
    complete_time[count] = time;

    // calculate waiting time and print processes
    if (remaining_time[count] == 0 && switcher == 1) {
      remain--;
      printf("P%d\t%d\t%d\t%d\t%d\t%d\n", count + 1, arrival_time[count],
             burst_time[count], complete_time[count],
             time - arrival_time[count],
             time - arrival_time[count] - burst_time[count]);
      waiting_time += time - arrival_time[count] - burst_time[count];
      turnaround_time += time - arrival_time[count];
      switcher = 0;
    }
    if (count == n - 1)
      count = 0;
    else if (arrival_time[count + 1] <= time)
      count++;
    else
      count = 0;
  }

  // finally print average times
  printf("\nAvg turnaround time = %f\n", turnaround_time * 1.0 / n);
  printf("Avg waiting time = %f", waiting_time * 1.0 / n);

  return 0;
}

