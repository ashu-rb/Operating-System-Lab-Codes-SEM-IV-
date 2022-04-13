#include<iostream>
using namespace std;
#include<climits>
struct process{
int pn;
int bt;
int at;
};
void fwt(process *p,int n,int wt[])
{
    int rt[n];
for(int i=0;i<n;i++)
        rt[i]=p[i].bt;
     int ct=0,t=0,min=INT_MAX;
     int st=0,ft;
        bool ck=0;
       while(ct!=n)
        {
            for(int j=0;j<n;j++)
            {
                if((p[j].at<=t)&&(rt[j]<min) && rt[j]>0)
                    {
                    min=rt[j];st=j;ck=1;
                    }
            }
            if(ck==0){
                t++;
                continue;
            }
            rt[st]--;
            min=rt[st];
            if(min==0)
                min=INT_MAX;
if(rt[st]==0){
            ct++;
            ck=0;
            ft=t+1;
            wt[st]=ft-p[st].bt-p[st].at;
               if(wt[st]<0)
                    wt[st]=0;
            }
            t++;
        }
}
void fat(process p[],int n,int wt[],int tat[])
{
    for(int i=0;i<n;i++){
        tat[i] = p[i].bt + wt[i];
    }
}

void favt(process p[], int n)
{
    int wt[n], twt=0,tat[n],tata = 0;
    fwt(p,n,wt);
    fat(p,n,wt,tat);
   cout<<"process "<<" Burst Time "<<"Waiting Time "<<" Turn Around Time\n";
   for(int i=0;i<n;i++)
    {
        twt+=wt[i];
        tata+=tat[i];
        cout<<" "<<p[i].pn<<"\t\t"<<p[i].bt<<"\t\t"<<wt[i]
        <<"\t\t"<<tat[i]<<endl;
    }
    cout<<"\nAverage waiting time="<<(float)twt/(float)n;
    cout<<"\nAverage Turn Around Time="<<(float)tata/(float)n;
}
int main()
{
    int n;
    cout<<"Enter number of processes ";
    cin>>n;
    process p[n];
for(int i=0;i<n;i++)
    {
        p[i].pn=i+1;
        cout<<"Enter burst time for process "<<i+1<<": ";
        cin>>p[i].bt;
        cout<<"Enter arrival time for process "<<i+1<<": ";
        cin>>p[i].at;
    }
    favt(p,n);
    return 0;
}