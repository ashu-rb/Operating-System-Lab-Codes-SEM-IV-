//OS LAB Experiment-11 LRU Page Replacement Algorithm By Aayush Patel 2K20/CO/11
#include<bits/stdc++.h>
using namespace std;

int main()
{
int A[20],n=0,size=0;
cout<<"OS LAB Experiment-11 LRU Page Replacement by Aayush Patel 2K20/CO/11\n\n";
cout<<"Enter the Page Reference Length:";
cin>>n;
cout<<"Enter the Page's Size:";
cin>>size;
cout<<"Enter the Page Reference:";

for(int i=0;i<n;i++){
    cin>>A[i];

}
deque<int> q(size);
int count=0;
int pf=0;
deque<int>::iterator itr;
q.clear();
for(int i:A)
{
	itr = find(q.begin(),q.end(),i);
	if(!(itr != q.end()))
	{

	++pf;
	if(q.size() == size)
	{
		q.erase(q.begin());
		q.push_back(i);
	}
	else{
		q.push_back(i);
       }
	}
	else
	{
	q.erase(itr);
	q.push_back(i);		
	}}
    cout<<"Total Number of Page Faults:";
  cout<<pf;
  return 0;
}

