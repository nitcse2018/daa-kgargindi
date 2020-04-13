#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct job
{
    int id;
    int dead;
    int prof;
    job(int id,int dead,int prof)
    {
        this->id=id;
        this->dead=dead;
        this->prof=prof;
    }
};
bool comparator(job &j1,job &j2)
{
    return j1.dead<j2.dead;
}


int main()
{
    int tes,n,temp1,temp2,temp3,sum;
    cin>>tes;
    for(int t=0;t<tes;t++)
    {
        cin>>n;
        vector<job>v;
        for(int i=0;i<n;i++)
        {
            cin>>temp1>>temp2>>temp3;
            job j(temp1,temp2,temp3);
            v.push_back(j);
        }
        sort(v.begin(),v.end(),comparator);
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(v[0].prof);
        int pqsize=1;
        for(int j=1;j<n;j++)
        {
            if(pqsize<v[j].dead)
            {
                pq.push(v[j].prof);
                pqsize++;
            }
            else if(v[j].prof>pq.top())
            {
                pq.pop();
                pq.push(v[j].prof);
            }
        }
        cout<<pqsize<<" ";
        sum=0;
        while(pqsize!=0)
        {
            sum=sum+pq.top();
            pq.pop();
            pqsize--;
        }
        cout<<sum<<endl;

    }
    return 0;
}
