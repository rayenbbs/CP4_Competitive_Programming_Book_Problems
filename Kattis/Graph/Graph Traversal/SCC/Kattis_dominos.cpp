#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
const int VISITED=-1;
const int UNVISITED=-2;

vector<vi> AL;
vector<vi> AL_T;
vi S;


vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

void Kosaraju(int u, int pass,int &head,int &count) { // pass = 1 (original), 2 (transpose)
    dfs_num[u] = 1;
    vi &neighbor = (pass == 1) ? AL[u] : AL_T[u]; // by ref to avoid copying
    for (auto &v : neighbor)
    {
        if (v==head)
            count++;
        if (dfs_num[v] == UNVISITED) {
            Kosaraju(v, pass, head, count);
        }
    }
    S.push_back(u);
}


int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >>t;

    while(t--) {
        int V,l;
        cin >>V>>l;
        AL.assign(V,vi());
        AL_T.assign(V,vi());
        vi in_degree(V,0);
        while(l--)
        {
            int a,b;
            cin >> a >> b;
            AL[a-1].push_back(b-1);
            AL_T[b-1].push_back(a-1);
            in_degree[b-1]++;
        }
        vi result;
        int head=0;
        int count=0;
        S.clear();
        dfs_num.assign(V, UNVISITED);
        for (int u = 0; u < V; ++u)
            if (dfs_num[u] == UNVISITED)
                Kosaraju(u, 1,head,count);
        dfs_num.assign(V, UNVISITED);
        for (int i = V-1; i >= 0; --i)
            if (dfs_num[S[i]] == UNVISITED)
            {
                count=0;
                head=S[i];
                Kosaraju(S[i], 2,head,count);
                result.push_back(in_degree[S[i]]-count);
            }
        int res=0;
        for (auto v:result)
        {
            if (v==0)
                res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
