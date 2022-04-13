#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,m,s=0,h;
    cout<<"Enter size of disk:";
    cin>>m;
    cout<<"Enter number of requests:";
    cin>>n;
    cout<<"Enter requests:";
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>m){
            cout<<"!Error!"<<a[i]<<"\n";
            return 0;
        }
    }
    cout<<"Enter head position:";
    cin>>h;
    int c=h;
    cout<<c;
    for(int i=0;i<n;i++){
        cout<<" -> "<<a[i]<<' ';
        s+=abs(a[i]-c);
        c=a[i];
    }
    cout<<'\n';
    cout<<"Total head movements = "<< s<<'\n';
    return 0;
}