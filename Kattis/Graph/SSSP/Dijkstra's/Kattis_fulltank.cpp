#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;
const int INF=1e9;
typedef long long ll;

int main() {
    int n,m;
    cin >>n>>m;
    vi fuelPrice(n,0);
    vector<vector<vector<ii>>> AL(n,vector<vector<ii>>(101,vector<ii>()));
    for(int i=0;i<n;++i){
        cin>>fuelPrice[i];
    }
    for(int i=0;i<m;++i){
        int u,v,w;
        cin >>u >>v>>w;
        for(int c=0;c<=100;++c)
        {
            AL[u][c].emplace_back(v, w);
            AL[v][c].emplace_back(u, w);
        }
    }
    int q; cin>>q;
    for(int i=0;i<q;++i){
        int c,s,e;
        cin >>c>>s>>e;
        vii dist(n,vi(c+1,INF)); dist[s][0] = 0; // INF = 1e9 here
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.emplace(0, s,0);
// sort the pairs by non-decreasing distance from s
        while (!pq.empty()) { // main loop
            auto [d, u,f] = pq.top(); pq.pop(); // shortest unvisited u
            if (d > dist[u][f]) continue; // a very important check
            if (f+1<=c){
                if (dist[u][f]+fuelPrice[u]>=dist[u][f+1]) continue;
                else
                {
                    dist[u][f+1]=dist[u][f]+fuelPrice[u];
                    pq.emplace(dist[u][f+1],u,f+1);
                }
            }

            for (auto &[v, w] : AL[u][f]) { // all edges from u
                if (w>f) continue;
                if (dist[u][f] >= dist[v][f-w]) continue; // not improving, skip
                dist[v][f-w] = dist[u][f]; // relax operation
                pq.emplace(dist[v][f-w], v,f-w); // enqueue better pair
            }
        }
        int min=INF;
        for(int c1=0;c1<c;++c1){
            if (dist[e][c1]<min)
                min=dist[e][c1];
        }
        if (min==INF)
            cout<<"impossible\n";
        else cout<<min<<endl;
    }

}




/*

5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
2
10 0 3
20 1 4



 */
