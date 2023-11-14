#include <iostream>
using namespace std;

int findbest(int blocksize[100], int i, int processsize[100], int b, int allocated[100])
{
    int min = -1;
    int c = 0;
    for (int j = 0; j < b; j++)
    {
        if (allocated[j] != 1)
        {
            if (processsize[i] <= blocksize[j])
            {
                if (c == 0)
                {
                    min = j;
                    c++;
                }
                if ((blocksize[j] - processsize[i]) < (blocksize[min] - processsize[i]))
                {
                    min = j;
                }
            }
        }
    }
    return min;
}

int findworst(int blocksize[100], int i, int processsize[100], int b, int allocated[100])
{
    int max = -1;
    int c = 0;
    for (int j = 0; j < b; j++)
    {
        if (allocated[j] != 1)
        {
            if (processsize[i] <= blocksize[j])
            {
                if (c == 0)
                {
                    max = j;
                    c++;
                }
                if ((blocksize[j] - processsize[i]) > (blocksize[max] - processsize[i]))
                {
                    max = j;
                }
            }
        }
    }
    return max;
}

int findfirst(int blocksize[100], int i, int processsize[100], int b, int allocated[100])
{
    for (int j = 0; j < b; j++)
    {
        if (allocated[j] != 1)
        {
            if (processsize[i] <= blocksize[j])
            {
                return j;
            }
        }
    }
    return -1;
}

int findnext(int blocksize[100], int i, int processsize[100], int b, int allocated[100], int lastAllocated)
{
    for (int j = (lastAllocated + 1) % b; j != lastAllocated; j = (j + 1) % b)
    {
        if (allocated[j] != 1)
        {
            if (processsize[i] <= blocksize[j])
            {
                return j;
            }
        }
    }
    return -1;
}

int main()
{
    int blocksize[100];
    int processsize[100];
    int allocated[100];
    int blockallocated[100];
    int func;
    int b, n;
    cout << "enter the no of processes" << endl;
    cin >> n;
    cout << "enter the no of blocks" << endl;
    cin >> b;

    for (int i = 0; i < n; i++)
    {
        cout << "enter the size of process:" << i + 1 << ":";
        cin >> processsize[i];
    }
    for (int i = 0; i < b; i++)
    {
        cout << "enter the size of blocks:" << i + 1 << ":";
        cin >> blocksize[i];
    }
    for (int i = 0; i < b; i++)
    {
        allocated[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        blockallocated[i] = -1;
    }
    cout << "1.BF.2.FF.3.WF.4.NF" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        for (int i = 0; i < n; i++)
        {
            func = findbest(blocksize, i, processsize, b, allocated);
            if (func != -1)
            {
                allocated[func] = 1;
                blockallocated[i] = func + 1;
            }
        }
    }
    else if (choice == 2)
    {
        for (int i = 0; i < n; i++)
        {
            func = findfirst(blocksize, i, processsize, b, allocated);
            if (func != -1)
            {
                allocated[func] = 1;
                blockallocated[i] = func + 1;
            }
        }
    }
    else if (choice == 3)
    {
        for (int i = 0; i < n; i++)
        {
            func = findworst(blocksize, i, processsize, b, allocated);
            if (func != -1)
            {
                allocated[func] = 1;
                blockallocated[i] = func + 1;
            }
        }
    }
    else if (choice == 4)
    {
        int lastAllocated = -1;
        for (int i = 0; i < n; i++)
        {
            func = findnext(blocksize, i, processsize, b, allocated, lastAllocated);
            if (func != -1)
            {
                allocated[func] = 1;
                blockallocated[i] = func + 1;
                lastAllocated = func;
            }
        }
    }
    printf("blockallocated=[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", blockallocated[i]);
    }
    printf("]\n");
    printf("allocated=[ ");
    for (int i = 0; i < b; i++)
    {
        printf("%d ", allocated[i]);
    }
    printf("]\n");
    return 0;
}
