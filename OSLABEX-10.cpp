//OS LAB Experiment-10 First In First OUT(FIFO) Page Replacement Algorithm By Aayush Patel 2K20/CO/11
#include <bits/stdc++.h> 
using namespace std; 
const int N=10001;  
void fifo(int fs, int n,int p[]) 
{ 
 	int mark[N];
    queue<int> Q; 
    int pf=0; 
    for(int i=0; i<n; i++) 
    { 
        if(mark[p[i]]==true) 
        { }         
        else 
        { 
            Q.push(p[i]);
            mark[p[i]]=true; 
            if(Q.size()>fs) 
            { 
                int p= Q.front();
                mark[p]=false; 
                Q.pop(); 
            } 
            pf++; 
        } }    
    cout<<"Size of Frame\t\tNo. of Page faults\t\tPage Hits\n"; 
    cout<<"\t"<<fs<<"\t\t"<<pf<<"\t\t\t"<<n-pf<<"\n"; 
 	return; 
} 
int main() 
{ 
 	int fs=4; int p[N]; 
    int n;    
    cout<<"OS LAB Experiment-10 First In First OUT(FIFO) Page Replacement Algorithm By Aayush Patel 2K20/CO/11 \n\n";
    cout<<"Page Reference Length:";
    cin>>n; 
    cout<<"Page References:";    
    for(int i=0; i<n; i++)         
    cin>>p[i]; 
  	fifo(fs,n,p);  	
    return 0; 
} 
 

			 
						  
			 
		