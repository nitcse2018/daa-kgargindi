#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
void add_edge(int a,int b,vector<int>*adj)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
void display(vector<int>*adj,int v)
{
    for(int k=0;k<v;k++)
    {
        cout<<"For vextix "<<k<<" ";
        for(auto it=adj[k].begin();it!=adj[k].end();it++)
        {
            cout<<*it<<"->";
            
        }
        cout<<endl;
        
    }
    
}
void bread_first(vector<int>*adj,int v)
{
    map <int,string> mymap;
    for(int k=0;k<v;k++)
    {
        mymap[k]="Unvisited";
    }
    int *p=new int[v];
    int temp1=0,val,v_count;
    queue <int> q;
    while(1)
    {
        v_count=v;
        for(auto it=mymap.begin();it!=mymap.end();it++)
        {
            if(it->second=="Unvisited")
            {
                q.push(it->first);
                break;
            }
            v_count--;
        }
        if(v_count==0)
        {
            break;
        }
        
        while(!q.empty())
        {
            val=q.front();
            q.pop();
            if(mymap[val]=="Unvisited")
            {
                mymap[val]="Visited";
                p[temp1]=val;
                temp1++;
                for(auto it=adj[val].begin();it!=adj[val].end();it++)
                {
                    if(mymap[*it]=="Unvisited")
                    {
                        q.push(*it);
                    }
                }
            }
            
        }
        
    }
    for(int n=0;n<v;n++)
    {
        cout<<p[n]<<" ";
    }
    
}


int main()
{
    cout<<"Enter the number of vertices"<<endl;
    int v;
    cin>>v;
    cout<<" Enter the number of edges"<<endl;
    int e;
    cin>>e;
    vector<int>* adj = new vector<int>[e];
    int a,b;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        add_edge(a,b,adj);
    }
    display(adj,v);
    cout<<endl;
    bread_first(adj,v);
    delete []adj;
    return 0;
}
