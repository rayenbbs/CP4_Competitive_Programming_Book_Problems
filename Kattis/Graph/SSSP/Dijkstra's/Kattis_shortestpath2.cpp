#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;

const int INF=1e9;


int main(){

    int n,m,q1,s;
    cin >>n>>m>>q1>>s;
    while (n!=0 || m!=0 || q1!=0 || s!=0) {
        vector<vector<tuple<int, int, int, int>>> AL(n, vector<tuple<int, int, int, int>>());
        for (int i = 0; i < m; ++i) {
            int u, v, t0, p, d;
            cin >> u >> v >> t0 >> p >> d;
            AL[u].emplace_back(v, t0, p, d);
        }
        vi dist(n,INF);
        dist[s]=0;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.emplace(0, s);
// sort the pairs by non-decreasing distance from s
        while (!pq.empty()) { // main loop
            auto [dis, u] = pq.top(); pq.pop(); // shortest unvisited u
            if (dis > dist[u]) continue; // a very important check
            for (auto &[v, t0,p,d] : AL[u]) {
                int w=0;
                if (p!=0) {
                    if (t0 >= dist[u]) {
                        w += t0 - dist[u];
                    }
                    else{
                        int coef=ceil((float)(dist[u]-t0)/(float)p);
                        t0+=p*coef;
                        w+=t0-dist[u];
                    }
                    w +=d;
                }
                else if (p==0){
                    if (t0>=dist[u]){
                        w+=t0-dist[u]+d;
                    }
                    else continue;
                }
                if (dist[u]+w >= dist[v]) continue; // not improving, skip
                dist[v] = dist[u]+w; // relax operation
                pq.emplace(dist[v], v); // enqueue better pair
            }
        }


        for (int i = 0; i < q1; ++i) {
            int d;
            cin >> d;
            if (dist[d] != INF)
                cout << dist[d] << endl;
            else cout << "Impossible" << endl;
        }
        cout << endl;
        cin >>n>>m>>q1>>s;
    }

}




/*



 */