#include <iostream>
using namespace std;

int counter = 0;

void Initialization(int *p, int *a, int *b, int *priority, int size)
{
    int arr = 0, burst = 0, prio = 0;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the arrival time, burst time, and priority for process " << i + 1 << ": ";
        cin >> arr >> burst >> prio;
        p[i] = i + 1;
        a[i] = arr;
        b[i] = burst;
        priority[i] = prio;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapbypriority(int *p, int *a, int *b, int *priority, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (priority[j] > priority[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                swap(&b[j], &b[j + 1]);
                swap(&p[j], &p[j + 1]);
                swap(&priority[j], &priority[j + 1]);
            }
        }
    }
}

void execution(int *p, int *a, int *b, int *priority, int size)
{
    int tat = 0, wt = 0;
    float avg_tat = 0, avg_wt = 0;

    cout << "GANTT CHART" << endl;
    cout << "\n___________________________________________________________________________\n";
    for (int i = 0; i < size; i++)
    {
        cout << "| p" << p[i] << " ";
    }
    cout << "\n_____________________________________\n";
    for (int i = 0; i < size; i++)
    {

        cout << "| P" << p[i] << " ";
        counter += b[i];
        tat = counter - a[i];
        wt = tat - b[i];
        avg_tat += tat;
        avg_wt += wt;

        cout << "|";
        cout << p[i] << "\t\t" << a[i] << "\t\t" << b[i] << "\t\t" << priority[i] << "\t\t" << counter << "\t\t" << tat << "\t\t" << wt << endl;
    }

    cout << "___________________________________________________________________________" << endl;
    cout << "Average Turnaround Time: " << avg_tat / size << endl;
    cout << "Average Waiting Time: " << avg_wt / size << endl;
}

int main()
{
    int process[20];
    int arr_time[30];
    int burst_time[20];
    int priority[20];
    int size = 0;

    cout << "Enter the number of processes: ";
    cin >> size;

    Initialization(process, arr_time, burst_time, priority, size);
    swapbypriority(process, arr_time, burst_time, priority, size);

    execution(process, arr_time, burst_time, priority, size);

    return 0;
}