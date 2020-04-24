#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
class graph
{
private:
    int v;
    vector <int> *adj;
public:
    graph(int v0)
    {
        v=v0;
        adj = new vector<int>[v];
    }
    void depth_first(int v_start)
    {
        bool *p=new bool[v];
        int *disp= new int[v];
        int k=0,val;
        for(int k=0;k<v;k++)
        {
            p[k]=false;
        }
        stack <int> s;
        s.push(v_start);
        while(1)
        {
            while(!s.empty())
            {
                val =s.top();
                s.pop();
                if(p[val]==false)
                {
                    disp[k]=val;
                    k++;
                    p[val]=true;
                    for(auto it =adj[val].begin();it!=adj[val].end();it++)
                    {
                        if(p[*it]==false)
                        {
                            s.push(*it);
                        }
                    }
                }
            }
            for(int k=0;k<v;k++)
            {
                if(p[k]==false)
                {
                    s.push(k);
                    break;
                }
            }
            if(k==v)
                break;
            
        }
        for(int h=0;h<v;h++)
        {
            cout<<disp[h]<<" ";
        }
        
    }
    void display()
    {
        int k=0;
        for(k=0;k<v;k++)
        {
            cout<<"For vertix "<<k<<"- ";
            for(auto it=adj[k].begin();it!=adj[k].end();it++)
            {
                cout<<*it<<" ";
            }
            cout<<endl;
        }
    }
    void add_edge(int a,int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    void directed_add_edge(int a,int b)
    {
        adj[a].push_back(b);
      
    }
    
};




int main()
{
    graph g(7);
    g.add_edge(0,1);
    g.add_edge(0,3);
    g.add_edge(1,2);
    g.add_edge(2,5);
    g.add_edge(3,4);
    g.add_edge(4,5);
    g.add_edge(3,6);
    g.add_edge(5,6);
    g.display();
    g.depth_first(0);
    graph g1(8);
    g1.add_edge(0,1);
    g1.add_edge(1,2);
    g1.add_edge(2,4);
    g1.add_edge(0,4);
    g1.add_edge(0,5);
    g1.add_edge(4,5);
    g1.add_edge(3,4);
    g1.add_edge(2,3);
    g1.add_edge(6,7);
    g1.display();
    g1.depth_first(6);
    graph g3(5);
    g3.directed_add_edge(0,1);
    g3.directed_add_edge(1,2);
    g3.directed_add_edge(2,3);
    g3.directed_add_edge(3,4);
    g3.directed_add_edge(1,4);
    g3.directed_add_edge(4,1);
    
    g3.display();
    g3.depth_first(0);
    
    return 0;
}
