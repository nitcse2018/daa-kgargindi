#include <iostream>
#include<vector>
#include<limits.h>

using namespace std;
class edge
{
    public:
        int u,v,w;
        edge(int u,int v,int w)
        {
            this->u=u;
            this->v=v;
            this->w=w;
        }
};
int main()
{
    int t,V,e,u,v,w,flag;
    cin>>t;
    for(int tes=0;tes<t;tes++)
    {
        cin>>V>>e;
        flag=0;
    
    vector<edge>g;
    vector<int>dist(V,INT_MAX);
    dist[0]=0;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        g.push_back(edge(u,v,w));
    }
    for(int v=0;v<V;v++)
    {
        for(int i=0;i<e;i++)
        {
           if(dist[g[i].u]!=INT_MAX)
           {
               if(dist[g[i].u]+g[i].w<dist[g[i].v])
               {
                    dist[g[i].v]=dist[g[i].u]+g[i].w;
               }
           }
        }
    }
    for(int i=0;i<e;i++)
    {
        if(dist[g[i].u]+g[i].w<dist[g[i].v])
        {
            flag=1;
        }
    
    }
    cout<<flag<<endl;
    }

    return 0;
}
