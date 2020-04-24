#include <iostream>
#include<vector>
#include<queue>
using namespace std;

vector<string> split_string(string);

class node{
    public:
    int index,weight;
    node(int i,int w)
    {
        index=i;
        weight=w;
    }

};

bool operator<(const node &n1,const node &n2)
{
    return n1.weight>n2.weight;
}

// Complete the prims function below.
int prims(int n, vector<vector<int>> edges, int start)
{
    vector<vector<int>>adj(n+1,vector<int>(n+1,INT_MAX));
  
    for(int v=0;v<edges.size();v++)
    {
        
        adj[edges[v][0]][edges[v][1]]=min(edges[v][2],adj[edges[v][0]][edges[v][1]]);
        adj[edges[v][1]][edges[v][0]]=min(edges[v][2],adj[edges[v][1]][edges[v][0]]);
    }

    for(int i=1;i<=n;i++)
    {
    
        for(int j=1;j<=n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    priority_queue <node>pq;
    vector<bool>vis(n+1,false);
    vector<int>dist(n+1,INT_MAX);
    dist[start]=0;
    pq.push(node(start,0));

    while(!pq.empty())
    {
        node top =pq.top();
        pq.pop();
        if(!vis[top.index])
        {
            cout<<"top"<<top.index<<endl;
            for(int i=1;i<=n;i++)
            {
                if(adj[top.index][i]!=INT_MAX and dist[i]>adj[top.index][i] and !vis[i])
                {
                    dist[i]=adj[top.index][i];
                    cout<<dist[i]<<" "<<i<<endl;
                    pq.push(node(i,dist[i]));
                }
            }
        }
        vis[top.index]=true;
    }

    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=dist[i];
    }

    return sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        edges[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> edges[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int start;
    cin >> start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = prims(n, edges, start);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
