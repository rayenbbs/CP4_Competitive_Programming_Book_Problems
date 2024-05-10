#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const int INF=1e9;
typedef long long ll;

void dfs(int u,vector<vector<pair<int,ll>>> &AL,vector<ll>&dist){
dist[u]=-INF;
for(auto[v,w]:AL[u]){
if (dist[v]!=-INF){
dist[v]=-INF;
dfs(v,AL,dist);
}
}
}

int main() {
    int V,E,Q,s;
    cin >>V>>E>>Q>>s;
    while (V!=0|| E!=0|| Q!=0||s!=0) {
        vector<vector<pair<int,ll>>> AL(V, vector<pair<int,ll>>());
        for (int i = 0; i < E; ++i) {
            ll u, v, w;
            cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
        }
        // inside int main()
        vector<ll> dist(V, INF);
        dist[s] = 0; // INF = 1e9 here
        for (int i = 0; i < V - 1; ++i) { // total O(V*E)
            bool modified = false; // optimization
            for (int u = 0; u < V; ++u) // these two loops = O(E)
                if (dist[u] != INF) // important check
                    for (auto &[v, w]: AL[u]) { // C++17 style
                        if (dist[u] + w >= dist[v]) continue; // not improving, skip
                        dist[v] = dist[u] + w; // relax operation
                        modified = true; // optimization
                    }
            if (!modified) break; // optimization
        }
        for (int u = 0; u < V; ++u) // one more pass to check
            if (dist[u] != INF)
                for (auto &[v, w]: AL[u]) // C++17 style
                    if (dist[v] > dist[u] + w) // should be false
                    {
                        dfs(u,AL,dist); // if true => -ve cycle
                    }



        for (int i = 0; i < Q; ++i) {
            int a;
            cin >> a;
            if (dist[a] == INF)
                cout << "Impossible\n";
            else if (dist[a] == -INF) {
                cout << "-Infinity\n";
            } else {

                cout << dist[a] << endl;
            }
        }
        cout << endl;
        cin >>V>>E>>Q>>s;

    }
}




/*

5 4 3 0
0 1 999
1 2 -2
2 1 1
0 3 2
1
3
4
2 1 1 0
0 1 -100
1
0 0 0 0




 */
