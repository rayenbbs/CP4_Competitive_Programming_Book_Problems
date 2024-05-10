#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
const int VISITED=-1;
const int UNVISITED=-2;

vector<vi> AL;


vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

void dfs(int s,int &count,set<int>&myset)
{
    dfs_num[s]=VISITED;
    count++;
    for(auto v:AL[s])
    {
        if (dfs_num[v]==UNVISITED && myset.find(v)==myset.end())
        {
            dfs(v,count,myset);
        }
    }
}
void articulationPointAndBridge(int u,set<int> &myset) {
    dfs_num[u] = dfsNumberCounter++;
    dfs_low[u] = dfs_num[u]; // dfs_low[u]<=dfs_num[u]
    for (auto &v : AL[u]) {
        if (dfs_num[v] == UNVISITED) { // a tree edge
            dfs_parent[v] = u;
            if (u == dfsRoot) ++rootChildren; // special case, root
            articulationPointAndBridge(v,myset);
            if (dfs_low[v] >= dfs_num[u]) // for articulation point
                articulation_vertex[u] = 1; // store this info first
            if (dfs_low[v] > dfs_num[u]) // for bridge
                myset.insert(v);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // subtree, always update
        }
        else if (v != dfs_parent[u]) // if a non-trivial cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // then can update
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int N,M;
    cin >> N>>M;
    AL.assign(N, vi());
    for (int i=0;i<M;++i)
    {
        int a, b;
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    set<int> myset;
    dfs_num.assign(N, UNVISITED); dfs_low.assign(N, 0);
    dfs_parent.assign(N, -1); articulation_vertex.assign(N, 0);
    dfsNumberCounter = 0;
    dfsRoot = 0; rootChildren = 0;
    articulationPointAndBridge(0,myset);
    articulation_vertex[dfsRoot] = (rootChildren > 1);
    if (myset.empty())
    {
        cout<<N<<endl;
    }
    else {
        for (int i = 0; i < N; ++i) {
            dfs_num[i] = UNVISITED;
        }
        int count = 0;
        dfs(0, count, myset);
        cout << count << endl;
    }



    return 0;
}

