#include <iostream>
using namespace std;
#define max 20
int main()
{

    int P[max], CT[max], AT[max], BT[max], TAT[max], WT[max], RT[max], time, curr_time = 0, completed = 0;
    float AvgWT = 0, AvgTAT = 0, Pno;
    
    int exe_ord[max], exe_time[max], exe_index = 0;

    int x = 0;
    cout << "\n ---- ---- MENU ---- ----\n";
    cout << "Enter number of processes: ";
    cin >> Pno;
    for (int i = 0; i < Pno; i++)
    {
        P[i] = i + 1;
        cout << "Enter Arrival time of P" << i + 1;
        cin >> AT[i];
        cout << "Enter Burst time of P" << i + 1;
        cin >> BT[i];
        RT[i] = BT[i];
    }

    cout << "\nProcess No.\tArrival Time\tBurst Time";
    for (int i = 0; i < Pno; i++)
    {
        cout << "\n"
             << P[i] << "\t\t" << AT[i] << "\t\t" << BT[i];
    }

    while (completed < Pno)
    {
        int shortest_time = 99;
        int shortest_ind = -1;
        for (int i = 0; i < Pno; i++)
        {
            if (AT[i] <= curr_time && RT[i] > 0 && RT[i] < shortest_time)
            {
                shortest_ind = i;
                shortest_time = RT[i];
            }
        }

        if (shortest_ind != exe_ord[exe_index - 1])
        {
            exe_ord[exe_index] = shortest_ind;
            exe_time[exe_index] = curr_time;
            exe_index++;
        }

        if (shortest_ind == -1)
        {
            curr_time++;
        }
        else
        {
            RT[shortest_ind]--;
            curr_time++;
            if (RT[shortest_ind] == 0)
            {
                CT[shortest_ind] = curr_time;
                TAT[shortest_ind] = CT[shortest_ind] - AT[shortest_ind];
                WT[shortest_ind] = TAT[shortest_ind] - BT[shortest_ind];
                completed++;
            }
        }
        time = curr_time;
    }

    cout << "\n --------  GANTT CHART  --------\n";
    for (int i = 0; i < exe_index; i++)
    {
        cout << "|  P" << exe_ord[i] << "\t";
    }
    cout << "|\n";
    for (int i = 0; i < exe_index; i++)
    {
        cout << exe_time[i] << "\t";
    }
    cout << time;

    for (int i = 0; i < Pno; i++)
    {
        cout << "\nWaiting time for P" << P[i] << ": " << WT[i];
        AvgWT += WT[i];
    }
    cout << "\nAvg WT:   " << AvgWT / Pno;
    for (int i = 0; i < Pno; i++)
    {
        cout << "\nTurn Around time for P" << P[i] << ": " << TAT[i];
        AvgTAT += TAT[i];
    }
    cout << "\nAvg TAT:   " << AvgTAT / Pno;

    return 0;
}
