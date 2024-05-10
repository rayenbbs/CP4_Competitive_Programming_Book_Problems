#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const int INF=1e9;
typedef long long ll;

int main() {
    int T;
    cin >>T;
    for(int t=0;t<T;++t){
        int V,E;
        cin >>V>>E;
        vector<vector<ii>> AL(V,vector<ii>());
        for(int j=0;j<E;++j){
            int u,v,w;
            cin >>u>>v>>w;
            AL[u].emplace_back(v,w);
        }
        vi dist(V, INF); dist[0] = 0; // INF = 1e9 here
        for (int i = 0; i < V-1; ++i) { // total O(V*E)
            bool modified = false; // optimization
            for (int u = 0; u < V; ++u) // these two loops = O(E)
                if (dist[u] != INF) // important check
                    for (auto &[v, w] : AL[u]) { // C++17 style
                        if (dist[u]+w >= dist[v]) continue; // not improving, skip
                        dist[v] = dist[u]+w; // relax operation
                        modified = true; // optimization
                    }
            if (!modified) break; // optimization
        }
        bool hasNegativeCycle = false;
        for (int u = 0; u < V; ++u) // one more pass to check
            if (dist[u] != INF)
                for (auto &[v, w] : AL[u]) // C++17 style
                    if (dist[v] > dist[u]+w) // should be false
                        hasNegativeCycle = true; // if true => -ve cycle
        if (hasNegativeCycle)
            printf("possible\n");
        else {
            printf("not possible\n");

        }
    }
}




/*

2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60


 */
