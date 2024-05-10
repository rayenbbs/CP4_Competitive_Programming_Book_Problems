#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const int INF=1e9;
typedef long long ll;


void dfs(int u,vector<vi> &AL,vi&dist){
    dist[u]=-INF;
    for(auto &v:AL[u]){
        if (dist[v]!=-INF){
            dist[v]=-INF;
            dfs(v,AL,dist);
        }
    }
}

int main() {
    int V;
    cin >>V;
    while(V!=-1) {

        vi energy(V, 0);
        vector<vi> AL(V, vi());

        for (int i = 0; i < V; ++i) {
            int en, n;
            cin >> en >> n;
            energy[i] = -en;
            for (int j = 0; j < n; ++j) {
                int v;
                cin >> v;
                v--;
                AL[i].push_back(v);
            }
        }
        int s=0;
        // inside int main()
        vi dist(V, INF); dist[s] = -100; // INF = 1e9 here
        for (int i = 0; i < V-1; ++i) { // total O(V*E)
            bool modified = false; // optimization
            for (int u = 0; u < V; ++u) // these two loops = O(E)
                if (dist[u]<0) // important check
                    for (auto &v : AL[u]) { // C++17 style
                        if (dist[u]+energy[v] >= dist[v] || dist[u]+energy[v]>=0 ) continue; // not improving, skip
                        dist[v] = dist[u]+energy[v]; // relax operation
                        modified = true; // optimization
                    }
            if (!modified) break; // optimization
        }
        bool hasNegativeCycle = false;
        for (int u = 0; u < V; ++u) // one more pass to check
            if (dist[u]<0)
                for (auto &v : AL[u]) // C++17 style
                    if (dist[v] > dist[u]+energy[v] && dist[u]+energy[v]<0) { // should be false
                        hasNegativeCycle = true; // if true => -ve cycle
                        dfs(v,AL,dist);
                    }

        if (dist[V-1]<0){
            cout<<"winnable\n";
        }
        else cout<<"hopeless\n";


        cin >>V;

    }

}




/*

6
0 1 2
-100 1 3
60 1 4
20 1 5
-5 2 6 4
0 0
-1

 5
0 1 2
-60 1 3
-60 1 4
20 1 5
0 0
 -1



 */