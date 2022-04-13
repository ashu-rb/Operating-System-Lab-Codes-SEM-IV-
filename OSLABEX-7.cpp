// Aayush patel 2K20/CO/11 OS LAB Assignment-7 Banker's Algorithm
#include<bits/stdc++.h>
using namespace std;
void Calculate();
void IMP();
int all[10][3],nd[10][3],Max[10][3],av[10][3];
int p,curr[3];
bool executed[10],come;
int main (){
int keepon = 1;
cout<<"Enter No. of processes: ";
cin>>p;
cout<<"\n";
cout<<"Enter the curr resources: ";
cin>>curr[0]>>curr[1]>>curr[2];
for (int i = 0; i < p; ++i)
{
cout<<"\n\n\t\t\tProcess P"<<i+1<<" Details\n";
cout<<"Enter Allocation : ";
cin>>all[i][0]>>all[i][1]>>all[i][2];
cout<<"Enter Max :";
cin>>Max[i][0]>>Max[i][1]>>Max[i][2];
nd[i][0]=Max[i][0]-all[i][0];nd[i][1]=Max[i][1]-

all[i][1];nd[i][2]=Max[i][2]-all[i][2];

}
cout<<"\n\n\t\t\tTable for Bankers Algo\n\n";
cout<<"Initial Resources: "<<curr[0]<<" "<<curr[1]<<" "<<curr[2]<<"\n\n";
cout<<"Process Max Allocation Need\n";
for (int i = 0; i < p; ++i)
{
cout<<" P"<<i+1<<" ";
cout<<" "<<Max[i][0]<<" "<<Max[i][1]<<" "<<Max[i][2]<<" ";
cout<<" "<<all[i][0]<<" "<<all[i][1]<<" "<<all[i][2]<<" ";
cout<<" "<<nd[i][0]<<" "<<nd[i][1]<<" "<<nd[i][2];
cout<<"\n";
}
cout<<"\n\n";
Calculate();
while(keepon){
int val,pro;
cout<<"\n\nSelect Below oprations:\n\n";
cout<<"1.Change Max of process: \n";
cout<<"2.Change Allocation of process\n";
cout<<"3.Change Initial Resources\n";
cout<<"4.Exit\n\n";
cin>>val;
if (val==1)
{
cout<<"\n\nEnter Process No: ";
cin>>pro;
cout<<"\nEnter New Max: ";
cin>>Max[pro-1][0]>>Max[pro-1][1]>>Max[pro-1][2];
}

else if (val==2)
{
cout<<"\n\nEnter Process No: ";
cin>>pro;
cout<<"\nEnter New Allocation: ";
cin>>all[pro-1][0]>>all[pro-1][1]>>all[pro-1][2];
}
else if (val==3)
{
cout<<"\nEnter Initial Resources: ";
cin>>curr[0]>>curr[1]>>curr[2];
}
else{
break;
}
Calculate();
}
return 0;
}

void Calculate(){
IMP();
int i,j;
for (i = 0; i < p; ++i)
{
for (j = 0; j < p; ++j)
{
while(executed[j] && j<p-1){
j++;

}
if (nd[j][0]<=curr[0]&&nd[j][1]<=curr[1]&&nd[j][2]<=curr[2])
{
if (!executed[j])
{
executed[j]=true;

curr[0]+=all[j][0];curr[1]+=all[j][1];curr[2]+=all[j][2];

cout<<"\nProcess P"<<j+1;
cout<<"\nCurrent: "<<curr[0]<<" "<<curr[1]<<"

"<<curr[2]<<"\n";

cout<<"\nProcess executed without deadlock";
come=true;
break;
}
}
}
if (!come)
{
cout<<"\n\t\t\tDead lock\n\n";
break;
}else{
come=false;
}
}
}

void IMP(){
come=false;

for (int i = 0; i < 10; ++i)
{
executed[i]=false;
}
}