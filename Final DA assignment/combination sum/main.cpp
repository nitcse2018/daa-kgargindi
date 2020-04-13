#include<iostream>
#include<vector>
#include<algorithm>
int n,sum,flag=0;
using namespace std;
void superfunc(vector<int> &v,int cum,vector<int>&soln)
{
    if(cum<0)
        return;
    if(cum==0)
    {
        cout<<"(";
        for(auto it=soln.begin();it!=soln.end();it++)
        {
            if(it==soln.begin())
                cout<<*it;
            else
            cout<<" "<<*it;
        }
        cout<<")";
        flag=1;
        return;
    }
    int j=1;
    if(soln.size()>0)
        j=soln.back();
    for(;j<10;j++)
    {
        if(v[j])
        {
            soln.push_back(j);
            cum=cum-j;
            v[j]--;
            superfunc(v,cum,soln);
            cum=cum+j;
            v[j]++;
            soln.pop_back();
            
        }
    }
    return;
}
int main()
{
    int tes,temp;
    cin>>tes;
    for(int t=0;t<tes;t++)
    {
        cin>>n;
        vector<int>q(10,0);
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            q[temp]++;
        }
        cin>>sum;
        vector<int>soln;
        superfunc(q,sum,soln);
        if(!flag)
            cout<<"Empty";
        cout<<endl;
        flag=0;
    }
}
