#include<iostream>
#include<map>
#include<queue>
using namespace std;
struct edge
{
    int src,des,w;
};
struct comparator
{
    bool operator()(edge & e1,edge & e2)
    {
        return e1.w>e2.w;
    }
};
class graph
{
private:
    priority_queue<edge,vector<edge>,comparator>pq;
    int vertix_count;
    map <int,int> mymap;
public:
    graph(int v)
    {
        vertix_count=v;
        for(int k=0;k<vertix_count;k++)
        {
            mymap[k]=k;
            cout<<k<<" "<<mymap[k]<<endl;
        }
    }
    void add_edge(int x, int y, int w)
    {
        edge s;
        s.src=x;
        s.des=y;
        s.w=w;
        pq.push(s);
    }
    int find_set(int x)
    {
        if(mymap[x]==x)
            return x;
        else
        {
            return find_set(mymap[x]);
        }
    }
    void my_union(int x,int y)
    {
        int x_=find_set(x);
        int y_=find_set(y);
        if(x_==y_)
            return;
        else
        {
            mymap[x_]=y_;
        }
    }
    void krushal()
    {
        auto rq=pq;
        cout<<endl;
        int val=0;
        edge temp;
        while(!rq.empty())
        {
            temp=rq.top();
            rq.pop();
            int s1 = temp.src;
            int d1 =temp.des;
            if(find_set(s1)==find_set(d1))
            {
                
            }
            else
            {
                my_union(s1,d1);
                val = val + temp.w;
                cout<<s1<<" "<<d1<<endl;
            }
        }
        cout<<"Total cost="<<val<<endl;
    }
    void display()
    { auto rq=pq;
        while(!rq.empty())
        {
            auto it =rq.top();
            cout<<it.src<<" "<<it.des<<" "<<it.w<<endl;
            rq.pop();
        }
        cout<<endl;
    }
};
int main()
{
    int vetrix,src,des,w,edge;
    cin>>vetrix>>edge;
    graph g1(vetrix);
    for(int k=0;k<edge;k++)
    {
        cin>>w>>src>>des;
        g1.add_edge(src,des,w);
    }
    
    g1.display();
    g1.krushal();
    return 0;
}
