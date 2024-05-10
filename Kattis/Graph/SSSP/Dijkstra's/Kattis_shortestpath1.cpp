#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;

const int INF=1e9;



int main(){
    int n,m,q,s;
    cin >>n>>m>>q>>s;
    while(n!= 0 || m!=0 || q!=0 || s!=0) {
        vector<vector<ii>> AL(n, vector<ii>());
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
        }

        // inside int main()
        vi dist(n, INF);
        dist[s] = 0; // INF = 1e9 here
        set<ii> pq; // balanced BST version
        for (int u = 0; u < n; ++u) // dist[u] = INF
            pq.emplace(dist[u], u); // but dist[s] = 0
// sort the pairs by non-decreasing distance from s
        while (!pq.empty()) { // main loop
            auto [d, u] = *pq.begin(); // shortest unvisited u
            pq.erase(pq.begin());
            for (auto &[v, w]: AL[u]) { // all edges from u
                if (dist[u] + w >= dist[v]) continue; // not improving, skip
                pq.erase(pq.find({dist[v], v})); // erase old pair
                dist[v] = dist[u] + w; // relax operation
                pq.emplace(dist[v], v); // enqueue better pair
            }
        }
        for (int i = 0; i < q; ++i) {
            int a;
            cin >> a;
            if (dist[a] == INF) {
                cout << "Impossible\n";
            } else
                cout << dist[a] << endl;
        }
        cout<<endl;
        cin >>n>>m>>q>>s;
    }

}

/*

4 3 4 0
0 1 2
1 2 2
3 0 2
0
1
2
3
2 1 1 0
0 1 100
1
0 0 0 0


 */