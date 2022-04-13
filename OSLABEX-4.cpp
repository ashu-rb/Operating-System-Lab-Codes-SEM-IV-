//OS LAB Assignment-4 Aayush Patel 2K20/CO/11 Shortest Job First (SJF) job scheduling algorithm
#include <iostream>
#include <climits>
using namespace std;

struct process {
    int pn;
    int bt;
    int at;
};

void turnAroundTime(process p[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = p[i].bt + wt[i];
}

void waitingTime(process p[], int n, int wt[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = p[i].bt;
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((p[j].at <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if (check == false)
        {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;
        if (rt[shortest] == 0)
        {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - p[shortest].bt - p[shortest].at;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

void avgTime(process p[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    waitingTime(p, n, wt);
    turnAroundTime(p, n, wt, tat);
    cout<<"Processes "<<" Burst Time "<<" Arrival Time "<<" Waiting Time "<<
    " Turn-Around Time\n ";
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "\t" << p[i].pn << "\t\t\t" << p[i].bt << "\t\t\t"
        << p[i].at << "\t\t\t" << wt[i] << "\t\t\t\t"
        << tat[i]<<endl;
    }
    cout<<endl;
    cout<<"\nAverage Waiting Time  = "<<(float)total_wt / (float)n;
    cout<<"\nAverage Turn Around Time = "<<(float)total_tat / (float)n;
}

int main()
{
    int n;
    cout<<"Enter the number of processes : ";
    cin>>n;
    process p[n];
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        p[i].pn = i+1;
        cout<<"Enter the details for Process "<<i+1<<"\n";
        cout<<"Enter Arrival Time : ";
        cin>>p[i].at;
        cout<<"Enter Burst Time : ";
        cin>>p[i].bt;
    }
    avgTime(p, n);
    cout<<endl;
    return 0;
}