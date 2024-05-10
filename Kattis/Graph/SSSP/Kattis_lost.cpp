#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;

int main(){
    int n,m;
    cin >>n>>m;
    vector <vector<pair<int,int>>> AL(n+1,vector<pair<int,int>>());
    queue<int> q;
    vector<int> dist(n+1,INF);
    unordered_map<string,int> mymap;
    unordered_map<int,string> revmap;
    for(int i=0;i<n;++i){
        string a;
        cin >>a;
        mymap[a]=i;
    }
    vi vcost(n+1,0);
    mymap["English"]=n;
    while(m--){
        string a,b;
        int cost;
        cin >>a>>b >>cost;
        AL[mymap[a]].emplace_back(mymap[b],cost);
        AL[mymap[b]].emplace_back(mymap[a],cost);
    }
    q.push(mymap["English"]);
    dist[mymap["English"]]=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(auto &[v,w]: AL[u]){
            if (dist[v]!=INF){
                if (dist[v]==dist[u]+1)
                {
                    if (w<vcost[v]){
                        vcost[v]=w;
                    }
                }
            }
            else {
                dist[v] = dist[u] + 1;
                vcost[v] = w;
                q.push(v);
            }
        }
    }
    bool test=true;
    for(int i=0;i<n;++i){
        if (dist[i]==INF)
            test=false;
    }
    if (test) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result += vcost[i];
        }
        cout << result << endl;
    }
    else
        cout<<"Impossible\n";
}
