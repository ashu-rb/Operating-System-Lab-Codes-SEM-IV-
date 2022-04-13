#include<bits/stdc++.h>
using namespace std;

int main()
{
        fstream of,cf;//of-original file pointer cf-copied file pointer
        char ch,f1[30], f2[30];
        cout<<"Enter original file name:";
        cin>>f1;
        of.open(f1);
        if(!of)
        {
                cout<<"!Error!";
                
                exit(1);
        }
        cout<<"Enter copied file name:";
        cin>>f2;
        cf.open(f2);
        if(!cf)
        {
                cout<<"!Error!";
                of.close();
                exit(2);
        }
        while(of.eof()==0)
        {
                of>>ch;
                cf<<ch;
        }
        cout<<"File Sucessfully Copied!!";
        of.close();
        cf.close();
        return 0;
}