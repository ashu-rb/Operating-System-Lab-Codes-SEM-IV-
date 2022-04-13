//OS LAB Experiment-8 Aayush Patel 2K20/CO/11 Round Robin Scheduling C++ Program  
#include <iostream>
#include <vector>
using namespace std;
int main(){
	int i,n,t,r,tp=0,tq;
     int wt=0,tat=0;
    cout<<"OS LAB Experiment-8  Round Robin Scheduling C++ Program by Aayush Patel 2K20/CO/11 \n\n";
   cout<<"Enter the number of process:";
	cin>>n;
    r=n;
    vector<int>at(n);
	vector<int>bt(n);
	vector<int>rt(n);
   cout<<"Enter the Arrival&Burst Time of processes"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>at[i];
		cin>>bt[i];
		rt[i]=bt[i];
	}
   cout<<"Enter the value of Time QUANTUM:";
   cin>>tq;
   cout<<"\n\nProcess\t:Turnaround Time:Waiting Time\n\n";
	for(t=0,i=0;r!=0;)
	{
		if(rt[i]<=tq && rt[i]>0)
		{
			t += rt[i];
			rt[i]=0;
			tp=1;
		}
     else if(rt[i]>0)
		{
			rt[i] -= tq;
			t += tq;
		}
     if(rt[i]==0 && tp==1)
		{
            r--;
			printf("Process[%d]\t:\t%d\t:\t%d\n",i+1,t-at[i],t-at[i]-bt[i]);
			cout<<endl;
            wt += t-at[i]-bt[i];
			tat += t-at[i];
			tp=0;
		}
       if(i == n-1)
			i=0;
		else if(at[i+1] <= t)
			i++;
		else
			i=0;
	}
    cout<<"Average Waiting Time :"<<wt*1.0/n<<endl;
	cout<<"Average Turn Around Time"<<tat*1.0/n<<endl;;
    return 0;
}
