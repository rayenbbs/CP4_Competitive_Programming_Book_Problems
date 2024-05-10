#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const long long INF=1e18;
typedef long long ll;

int main() {

    string line;
    getline(cin,line);
    while(!line.empty()) {
        stringstream ss(line);
        ll V, E;
        ss >> V >> E;
        vector<vector<pair<ll, ll>>> AL(V, vector<pair<ll, ll>>());
        for (ll i = 0; i < E; ++i) {
            getline(cin, line);
            stringstream ss(line);
            ll u, v, w;
            ss >> u >> v >> w;
            u--;
            v--;
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);

        }
        // inside int main()

        vector<vector<long long>> dist(V, vector<long long>(2, INF));
        dist[0][0] = 0; // INF = 1e9 here
        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
        pq.emplace(0, 0, 0);
// sort the pairs by non-decreasing distance from s
        while (!pq.empty()) { // main loop
            auto [d, u, k] = pq.top();
            pq.pop(); // shortest unvisited u
            if (d > dist[u][k]) continue; // a very important check
            for (auto &[v, w]: AL[u]) { // all edges from u
                if (dist[u][k] + w >= dist[v][(k + 1) % 2]) continue; // not improving, skip
                dist[v][(k + 1) % 2] = dist[u][k] + w; // relax operation
                pq.emplace(dist[v][(k + 1) % 2], v, (k + 1) % 2); // enqueue better pair
            }
        }

        if (dist[V - 1][0] == INF) {
            cout << -1 << endl;
        } else
            cout << dist[V - 1][0] << endl;
        getline(cin,line);

    }
}




/*
4 4
1 2 2
2 3 1
2 4 10
3 4 6
5 6
1 2 3
2 3 5
3 5 2
5 1 8
2 4 1
4 5 4


 */
