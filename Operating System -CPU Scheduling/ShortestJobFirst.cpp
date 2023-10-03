#include <iostream>
#include <algorithm>
using namespace std;

// Structure to represent a process
struct Process
{
    int id;          // Process ID
    int arrivalTime; // Arrival time
    int burstTime;   // Burst time
};

// Function to compare processes based on burst time
bool compareBurstTime(Process p1, Process p2)
{
    return p1.burstTime < p2.burstTime;
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

void calculateTurnaroundTime(Process processes[], int n, int completionTime[], int turnaroundTime[])
{
    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = completionTime[i] - processes[i].arrivalTime;
    }
}

void calculateWaitingTime(Process processes[], int n, int waitingTime[], int turnaroundTime[])
{
    for (int i = 0; i < n; i++)
    {
        waitingTime[i] = turnaroundTime[i] - processes[i].burstTime;
    }
}

void calculateAverageTimes(Process processes[], int n, int completionTime[])
{
    int waitingTime[n], turnaroundTime[n];
    calculateTurnaroundTime(processes, n, completionTime, turnaroundTime);
    calculateWaitingTime(processes, n, waitingTime, turnaroundTime);

    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

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

    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }

    sort(processes, processes + n, compareBurstTime);

    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n";

    calculateCompletionTime(processes, n, completionTime);
    calculateTurnaroundTime(processes, n, completionTime, turnaroundTime);
    calculateWaitingTime(processes, n, waitingTime, turnaroundTime);

    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t" << completionTime[i] << "\t\t";
        cout << waitingTime[i] << "\t\t";
        cout << turnaroundTime[i] << endl;
    }

    calculateAverageTimes(processes, n, completionTime);

    return 0;
}
