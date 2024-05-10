#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const int INF=1e9;


int main() {
    int V, E, a, k;
    cin >> V >> E >> a >> k;
    while (V!=0 || E!=0 || a!=0 || k!=0){
        vector<vector<pair<int, int>>> AL(V, vector<pair<int, int>>());
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
        }
        vi dist(V, INF);

        int s;
        for (int t = 0; t < a; ++t) {
            cin >> s;
            s--;
            // inside int main()
            dist[s] = 0; // INF = 1e9 here
            priority_queue<ii, vector<ii>, greater<ii>> pq;
            pq.emplace(0, s);
// sort the pairs by non-decreasing distance from s
            while (!pq.empty()) { // main loop
                auto [d, u] = pq.top(); pq.pop(); // shortest unvisited u
                if (d > dist[u]) continue; // a very important check
                for (auto &[v, w] : AL[u]) { // all edges from u
                    if (dist[u]+w >= dist[v]) continue; // not improving, skip
                    dist[v] = dist[u]+w; // relax operation
                    pq.emplace(dist[v], v); // enqueue better pair
                }
            }

            long long result = 0;
            for (int i = 0; i < V; ++i) {
                if (dist[i] >= k && dist[i]!=INF) {
                    result++;
                }
            }

            cout << result << endl;

        }
        cout << endl;
        cin >> V >> E >> a >> k;
    }
}





/*

7 6 3 3
1 2 1
1 3 1
2 5 1
3 6 1
1 4 1
4 7 2
2
1
4
1 0 1 1
1
0 0 0 0


 */