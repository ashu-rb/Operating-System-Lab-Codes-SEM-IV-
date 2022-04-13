//Aayush Patel 2K20/CO/11 Experiment-5 Priority Scheduling Algorithm
#include<iostream>
using namespace std;
int main()
{
    int a[10],b[10],x[10],pr[10]={0};
    int wt[10],tat[10],cp[10];
    int i,j,s,ct=0,t,n;
    double avg=0,tt=0,e;
    cout<<"\nEnter the number of Processes:";
    cin>>n;
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter Arrival Time of process:";
      cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter Burst Time of process:";
      cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
      cout<<"\nEnter Priority of process:";
      cin>>pr[i];
    }
    for(i=0;i<n;i++)
    x[i]=b[i];
    pr[9]=-1;
    for(t=0;ct!=n;t++)
    {
        s=9;
        for(i=0;i<n;i++)
        {
            if(a[i]<=t && pr[i]>pr[s] && b[i]>0 )
                s=i;
        }
        t+=b[s]-1;
        b[s]=-1;
        ct++;
        e=t+1;
        cp[s] = e;
        wt[s] = e - a[s] - x[s];
        tat[s] = e - a[s];
    }
    cout<<"Process"<<"\t"<< "bt-t"<<"\t"<<"at-t" <<"\t"<<"wt-t" <<"\t"<<"tat-t"<<"\t"<<"cp-t"<<"\t"<<"Priority"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"p"<<i+1<<"\t\t"<<x[i]<<"\t\t"<<a[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<"\t\t"<<cp[i]<<"\t\t"<<pr[i]<<endl;
        avg = avg + wt[i];
        tt = tt + tat[i];
    }
    cout<<"\n\nAverage Wating Time, t ="<<avg/n;
    cout<<"Average Turnaround Time ="<<tt/n<<endl;
}