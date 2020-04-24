#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class node
{
public:
    int v,w;
    node(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};

bool operator<(const node& n1, const node& n2)
{
    return n1.w>n2.w;
}


void dijkstra(vector<vector<int>> graph, int src, int V)
{
    priority_queue<node> pq;
    vector<int> soln(V,INT_MAX);
    vector<bool> vis(V,false);
    pq.push(node(src,0));
    soln[src]=0;
    while(!pq.empty())
    {
        node top=pq.top();
        pq.pop();
        if(!vis[top.v])
        {
            vis[top.v]=true;
            for(int n=0;n!=V;n++)
                if(graph[top.v][n]!=0 and soln[n]>soln[top.v]+graph[top.v][n])
                    {
                        soln[n]=soln[top.v]+graph[top.v][n];
                        pq.push(node(n,soln[n]));
                    }
        }
    }
    for(auto it=soln.begin();it!=soln.end();it++) cout<<*it<<" ";
}

int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
              for(int j=0;j<V;j++)
              {
                  cin>>g[i][j];
              }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}
