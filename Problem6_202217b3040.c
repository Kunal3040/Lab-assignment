#include <stdio.h>

// Function prototypes
void calculateTimes(int n, int burst_time[], int arrival_time[], int waiting_time[], int turnaround_time[]);
void displayResults(int n, int waiting_time[], int turnaround_time[]);
void calculateAndDisplayAverages(int n, int waiting_time[], int turnaround_time[]);

int main() {
    int n, i;
    int burst_time[10], arrival_time[10], waiting_time[10], turnaround_time[10];

    // Initialize the arrays
    for(i = 0; i < 10; i++) {
        burst_time[i] = 0;
        arrival_time[i] = 0;
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }

    // Read number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Read burst times
    printf("Enter the burst times:\n");
    for(i = 0; i < n; i++) {
        printf("Burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Read arrival times
    printf("Enter the arrival times:\n");
    for(i = 0; i < n; i++) {
        printf("Arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }

    // Calculate waiting and turnaround times
    calculateTimes(n, burst_time, arrival_time, waiting_time, turnaround_time);

    // Display results
    displayResults(n, waiting_time, turnaround_time);

    // Calculate and display averages
    calculateAndDisplayAverages(n, waiting_time, turnaround_time);

    return 0;
}

void calculateTimes(int n, int burst_time[], int arrival_time[], int waiting_time[], int turnaround_time[]) {
    int i, completion_time[10];
    int current_time = 0;

    // Calculate completion times
    for(i = 0; i < n; i++) {
        if(current_time < arrival_time[i]) {
            current_time = arrival_time[i];
        }
        current_time += burst_time[i];
        completion_time[i] = current_time;
    }

    // Calculate waiting and turnaround times
    for(i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }
}

void displayResults(int n, int waiting_time[], int turnaround_time[]) {
    int i;
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i + 1, waiting_time[i], turnaround_time[i]);
    }
}

void calculateAndDisplayAverages(int n, int waiting_time[], int turnaround_time[]) {
    int i;
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Calculate total waiting and turnaround times
    for(i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    // Calculate and display averages
    printf("The average waiting time is: %.2f\n", total_waiting_time / n);
    printf("The average turnaround time is: %.2f\n", total_turnaround_time / n);
}

