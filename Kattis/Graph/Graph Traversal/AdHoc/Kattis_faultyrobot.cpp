#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
const int INF=1e9;
vector<vi> ALf;
vector<vi> ALnf;
void dfsnf(int u,int&count);
void dfsf(int u,int&count);
enum { UNVISITED = -1, VISITED = -2 }; // basic flags
vi dfs_num; // initially all UNVISITED
void dfsf(int u,int &count) { // normal usage
    dfs_num[u] = VISITED;
    if (ALf[u].empty()) {
        count++;
    }
    // mark u as visited
    for (auto &v : ALf[u]) // C++17 style, w ignored
        if (dfs_num[v] == UNVISITED) // to avoid cycle
            dfsf(v,count); // recursively visits v
    for (auto&v:ALnf[u])
    {
        if (dfs_num[v]==UNVISITED)
            dfsnf(v,count);
    }
}
void dfsnf(int u,int &count)
{
    dfs_num[u]=VISITED;
    if (ALf[u].empty())
    {
        count++;
    }
    else {
        for(auto&v:ALf[u]) {
            if (dfs_num[v] == UNVISITED)
            {
                dfsnf(v,count);
            }
        }
    }
}

int main()
{
    int v,e;
    cin >>v>>e;
    ALf.assign(v,vi());
    ALnf.assign(v,vi());
    dfs_num.assign(v,UNVISITED);
    for(int i=0;i<e;++i)
    {
        int a,b;
        cin>>a>>b;
        if (a>0)
        {
            ALnf[a-1].push_back(b-1);
        }
        else if (a<0)
        {
            ALf[-a-1].push_back(b-1);
        }
    }
    int count=0;
    dfsf(0,count);
    cout<<count<<endl;

}