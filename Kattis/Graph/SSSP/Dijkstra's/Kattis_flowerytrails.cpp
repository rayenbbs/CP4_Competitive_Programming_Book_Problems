#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;

const int INF=1e9;

void predecessor(int u, vector<unordered_set<int>> &p ,unordered_set<int> &resultset){
    for (int i:p[u]) {
        if (resultset.find(i)==resultset.end()) { //avoid infinite loop
            resultset.insert(i);
            predecessor(i, p, resultset);
        }
        else continue;
    }
}

int main(){
    int n,m;
    cin >>n>>m;
    vector<vector<ii>> AL(n, vector<ii>());
    vector<unordered_set<int>> p(n, unordered_set<int>());
    unordered_set<int> resultset;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
    }
    int s=0;

    // inside int main()
    vector<long long> dist(n, 1e17);
    vector<long long> result(n, 0);
    dist[s] = 0; // INF = 1e9 here
    set<ii> pq; // balanced BST version
    for (int u = 0; u < n; ++u) // dist[u] = INF
        pq.emplace(dist[u], u); // but dist[s] = 0
// sort the pairs by non-decreasing distance from s
    while (!pq.empty()) { // main loop
        auto [d, u] = *pq.begin(); // shortest unvisited u
        pq.erase(pq.begin());
        for (auto &[v, w]: AL[u]) { // all edges from u
            if (dist[u] + w > dist[v]) continue; // not improving, skip
            if (dist[u]+w==dist[v] ){
                result[v]+=w;
                p[v].insert(u);
            }
            else {
                pq.erase(pq.find({dist[v], v})); // erase old pair
                dist[v] = dist[u] + w; // relax operation
                pq.emplace(dist[v], v); // enqueue better pair
                result[v]=w;
                p[v].clear(); //remove the previous predecessors as they are no longer valid
                p[v].insert(u);
            }
        }
    }
    long long resul=0;
    predecessor(n-1,p,resultset);
    for(int i:resultset){
        resul+=result[i];
    }
    resul+=result[n-1];
    cout<<resul*2<<endl;
}




/*



 */