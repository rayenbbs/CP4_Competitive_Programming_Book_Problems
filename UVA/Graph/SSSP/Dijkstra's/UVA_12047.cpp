#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const int INF=1e9;


vector<int> dijsktra(int V,int s,vector<vector<pair<int,int>>> &AL){
// inside int main()
vi dist(V, INF); dist[s] = 0; // INF = 1e9 here
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
return dist;
}

int main() {
    int t;
    cin >>t;
    while(t--){
        int V,E,s,dest,p;
        cin >>V>>E>>s>>dest>>p;
        s--;
        dest--;
        vector<vector<pair<int,int>>> AL(V,vector<pair<int,int>>());
        vector<vector<pair<int,int>>> revAL(V,vector<pair<int,int>>());

        vector<tuple<int,int,int>> edges;
        for(int i=0;i<E;++i){
            int u,v,w;
            cin >>u>>v>>w;
            u--;
            v--;
            AL[u].emplace_back(v,w);
            revAL[v].emplace_back(u,w);
            edges.emplace_back(u,v,w);
        }
        long long result=-1;
        vi distFromSource= dijsktra(V,s,AL);
        vi distFromDest= dijsktra(V,dest,revAL);
        for(auto [u,v,w]:edges){
            long long totalcost= distFromSource[u]+distFromDest[v]+w;
            if (totalcost<=p){
                if (w>result)
                    result=w;
            }
        }
        cout<<result<<endl;
    }


}


