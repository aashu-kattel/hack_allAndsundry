#include <iostream>
#include <algorithm>
using namespace std;

// Structure to represent a process
class Process
{
public:
    int id;          // Process ID
    int arrivalTime; // Arrival time
    int burstTime;   // Burst time
};

// Function to compare processes based on arrival time
bool compareArrivalTime(Process p1, Process p2)
{
    return p1.arrivalTime < p2.arrivalTime;
}
void calculateCompletionTime(Process processes[], int n, int completionTime[])
{
    completionTime[0] = processes[0].arrivalTime + processes[0].burstTime;
    for (int i = 1; i < n; i++)
    {
        if (processes[i].arrivalTime > completionTime[i - 1])
            completionTime[i] = processes[i].arrivalTime + processes[i].burstTime;
        else
            completionTime[i] = completionTime[i - 1] + processes[i].burstTime;
    }
}
// Function to calculate turnaround time for each process
void calculateTurnaroundTime(Process processes[], int n, int completionTime[], int turnaroundTime[])
{
    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = completionTime[i] - processes[i].arrivalTime;
    }
}
// Function to calculate waiting time for each process
void calculateWaitingTime(Process processes[], int n, int waitingTime[], int turnAroundTime[])
{
    waitingTime[0] = 0; // The first process doesn't wait

    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = turnAroundTime[i] - processes[i].burstTime;
    }
}
// Function to calculate average waiting time and average turnaround time
void calculateAverageTimes(Process processes[], int n, int completionTime[])
{
    int waitingTime[n], turnaroundTime[n];
    // Calculate turnaround time for each process
    calculateTurnaroundTime(processes, n, completionTime, turnaroundTime);
    // Calculate waiting time for each process
    calculateWaitingTime(processes, n, waitingTime, turnaroundTime);

    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    // Calculate the total waiting time and total turnaround time
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    // Calculate and display average waiting time and average turnaround time
    float averageWaitingTime = totalWaitingTime / n;
    float averageTurnaroundTime = totalTurnaroundTime / n;

    cout << "Average Waiting Time: " << averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;
}

int main()
{
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];
    int completionTime[n], waitingTime[n], turnaroundTime[n];

    // Input process details
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }

    // Sort processes based on arrival time
    sort(processes, processes + n, compareArrivalTime);

    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";

    // Calculate and display waiting time and turnaround time for each process
    calculateCompletionTime(processes, n, completionTime);

    // Calculate turnaround time for each process
    calculateTurnaroundTime(processes, n, completionTime, turnaroundTime);
    // Calculate waiting time for each process
    calculateWaitingTime(processes, n, waitingTime, turnaroundTime);
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t" << completionTime[i] << "\t\t";

        cout << waitingTime[i] << "\t\t";

        cout << turnaroundTime[i] << endl;
    }

    // Calculate and display average waiting time and average turnaround time
    calculateAverageTimes(processes, n, completionTime);

    return 0;
}
