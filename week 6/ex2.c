#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Process { // it makes the working with process easier
  int pid;               // process pid
  int burst_time;
  int arrival_time;
} Process;

void swap(Process *a, Process *b) {
  Process temp = *a;
  *a = *b;
  *b = temp;
}

// this function can find the waiting time for each process
void f_waiting_time(Process current_processes[], int n, int waiting_time[]) {
  int remaining_time[n];
  for (int i = 0; i < n; i++)
    remaining_time[i] = current_processes[i].burst_time;

  int complete = 0, t = 0;
  int min_value = INT_MAX;
  int shortest = 0, finish_time;
  bool check = false;

 
  while (complete != n) {

    // minimum time
    for (int j = 0; j < n; j++) {
      if ((current_processes[j].arrival_time <= t) &&
          (remaining_time[j] < min_value) && remaining_time[j] > 0) {
        min_value = remaining_time[j];
        shortest = j;
        check = true;
      }
    }

    if (check == false) {
      t++;
      continue;
    }

    remaining_time[shortest]--;

    // update minimum
    min_value = remaining_time[shortest];
    if (min_value == 0)
      min_value = INT_MAX;

    if (remaining_time[shortest] == 0) {
      complete++;
      check = false;
      finish_time = t + 1; 

      // waiting time
      waiting_time[shortest] = finish_time -
                               current_processes[shortest].burst_time -
                               current_processes[shortest].arrival_time;

      if (waiting_time[shortest] < 0)
        waiting_time[shortest] = 0;
    }
    t++;
  }
}

void find_all_time(Process current_processes[], int n) {
  int waiting_time[n], turnaround_time[n], complete_time[n];
  float total_waiting_time = 0, total_turnaround_time = 0;
  int sum = 0;

  // run function to find waiting time
  f_waiting_time(current_processes, n, waiting_time);

  // find turnaround time for each process
  for (int i = 0; i < n; i++)
    turnaround_time[i] = current_processes[i].burst_time + waiting_time[i];

  // completion time calculation
  for (int j = 0; j < n; j++) {
    sum += current_processes[j].burst_time;
    complete_time[j] = sum;
  }

  // waiting and turnaround time calculation
  printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++) {
    total_waiting_time = total_waiting_time + waiting_time[i];
    total_turnaround_time = total_turnaround_time + turnaround_time[i];
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", current_processes[i].pid,
           current_processes[i].arrival_time, current_processes[i].burst_time,
           complete_time[i], turnaround_time[i], waiting_time[i]);
  }

  printf("\naverage turnaround time = %f\n", total_turnaround_time / n);
  printf("average waiting time = %f", total_waiting_time / n);
}

int main() {
  int n;
  printf("Number of processes: ");
  scanf("%d", &n);

  Process current_processes[32] = {0};
  printf("\nfor each process enter id, arrival time and "
         "burst time:\n");

  // input data
  for (int i = 0; i < n; i++) {
    printf("P[%d] id: ", i + 1);
    scanf("%d", &current_processes[i].pid);
    printf("P[%d] arrival time: ", i + 1);
    scanf("%d", &current_processes[i].arrival_time);
    printf("P[%d] burst time: ", i + 1);
    scanf("%d", &current_processes[i].burst_time);
    printf("\n");
  }

  // sort our data by arrival time (using bubble sort e.g.)
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (current_processes[j].arrival_time >
          current_processes[j + 1].arrival_time)
        swap(&current_processes[j], &current_processes[j + 1]);
    }
  }

  // sort our data by burst time (using bubble sort e.g.)
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (current_processes[j].burst_time >
          current_processes[j + 1].burst_time)
        swap(&current_processes[j], &current_processes[j + 1]);
    }
  }

  // proceed with data
  find_all_time(current_processes, n);
  return 0;
}