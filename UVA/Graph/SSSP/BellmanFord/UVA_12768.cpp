#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const int INF=1e9;
typedef long long ll;

void dfs(int u,vector<vector<ii>>& AL,vi &dist){
    dist[u]=-INF;
    for(auto &[v,w]: AL[u]){
        if (dist[v]!=-INF){
            dfs(v,AL,dist);
        }
    }

}

int main() {

    int V,E;
    cin >>V>>E;
    while(V!=0 || E!=0) {
        vector<vector<ii>> AL(V, vector<ii>());
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            w = -w;
            AL[u].emplace_back(v, w);
        }
        // inside int main()
        vi dist(V, INF);
        dist[0] = 0; // INF = 1e9 here
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
        for (int u = 0; u < V; ++u)
        { // one more pass to check
            if (dist[u] != INF)
                for (auto &[v, w]: AL[u]) // C++17 style
                    if (dist[v] > dist[u] + w) // should be false
                        dfs(v, AL, dist); // if true => -ve cycle
        }
        int min=INF;
        for(int u=0;u<V;++u){
            if (dist[u]<min){
                min=dist[u];
            }
        }
        if (min!=-INF){
            cout<<-min<<"\n";
        }
        else cout<<"Unlimited!\n";
        cin >>V>>E;
    }
}