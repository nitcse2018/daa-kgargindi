#include<iostream>
#include<vector>
using namespace std;

int superfunc(int start,int end,string s,int size)
{
    int temp1,temp2;
    if(end>start)
    {
        if(s[start]==s[end])
        {
            // cout<<"DEBUG1"<<endl<<start<<" "<<end<<" "<<s[start]<<" "<<s[end]<<" ";
            return superfunc(start+1,end-1,s,size+2);
        }
        else
        {
            // cout<<"DEBUG2"<<endl<<start<<" "<<end<<" "<<s[start]<<" "<<s[end]<<" "<<size<<endl;
            temp1=superfunc(start+1,end,s,size);
            temp2=superfunc(start,end-1,s,size);
            // cout<<"DEBUG3"endl<<temp1<<" "<<temp2<<" "<<endl;
            return temp1>temp2?temp1:temp2;
            
        }
    }
    else
    {
        if(end==start)
        {
            return size+1;
        }
        else
        {
            return size;
        }
    }
    
}


int main()
{
    string str;
    cin>>str;
    int n=(int)str.length();
    n--;
    int m=superfunc(0,n,str,0);
    cout<<endl<<m<<endl;
}
