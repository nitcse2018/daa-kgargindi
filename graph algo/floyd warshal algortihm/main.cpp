#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
class graph
{
private:
    int **a;
    int v_count;
public:
    graph(int v_)
    {
        v_count=v_;
        a = new int*[v_count];
        for(int i = 0; i < v_count;++i)
        {
            a[i] = new int[v_count];
            for (int j = 0; j < v_count; j++)
                if(i==j)
                {
                    a[i][j]=0;
                }
            else
                a[i][j] = 100;
        }
        
        
    }
    void add_edge_directed(int x,int y ,int weight)
    {
        a[x][y]=weight;
    }
    bool isEdge(int x,int y)
    {
        return a[x][y]!=100;
    }
    void floyd_warshal()
    {
        for(int k=0;k<v_count;k++)
        {
            for(int i=0;i<v_count;i++)
            {
                for(int j=0;j<v_count;j++)
                {
                    
                    if(a[i][j]>a[i][k]+a[k][j])
                    {
                        a[i][j]=a[i][k]+a[k][j];
                        
                    }
                }
                
            }
        }
        
        for(int i=0;i<v_count;i++)
        {
            
            for(int j=0;j<v_count;j++)
            {
                if(a[i][j]==100)
                {
                    cout<<"∞"<<"\t";
                }
                else
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
            
        }
        
        
        
        
        
        
    }
    
    
    
    
};

int main()
{
    graph g1(4);
    g1.add_edge_directed(0,1,1);
    g1.add_edge_directed(0,2,8);
    g1.add_edge_directed(1,2,2);
    g1.add_edge_directed(1,3,9);
    g1.add_edge_directed(3,0,4);
    g1.add_edge_directed(2,3,1);
   
    
    g1.floyd_warshal();
    
    
    
    
    
    return 0;
}
