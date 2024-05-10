#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> ii;

const int INF=1e9;



int main(){
    int n;
    cin >>n;
    n+=2;
    vector<pair<int,int>> coord;
    for(int i=0;i<n;++i){
        int x,y;
        cin >>x>>y;
        coord.emplace_back(x,y);
    }
    vector<vector<pair<int,int>>> AL(n,vector<pair<int,int>>());
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if (i!=j){
                int x1=coord[i].first,y1=coord[i].second,x2=coord[j].first,y2=coord[j].second;
                int w=pow(x1-x2,2)+pow(y1-y2,2);
                AL[i].emplace_back(j,w);
                AL[j].emplace_back(i,w);
            }
        }
    }
    // inside int main()
    vi p(n,-1);
    vi dist(n, INF); dist[n-2] = 0; // INF = 1e9 here
    p[n-2]=n-2;
    set<ii> pq; // balanced BST version
    for (int u = 0; u < n; ++u) // dist[u] = INF
        pq.emplace(dist[u], u); // but dist[s] = 0
// sort the pairs by non-decreasing distance from s
    while (!pq.empty()) { // main loop
        auto [d, u] = *pq.begin(); // shortest unvisited u
        pq.erase(pq.begin());
        for (auto &[v, w] : AL[u]) { // all edges from u
            if (dist[u]+w >= dist[v]) continue; // not improving, skip
            pq.erase(pq.find({dist[v], v})); // erase old pair
            dist[v] = dist[u]+w; // relax operation
            pq.emplace(dist[v], v); // enqueue better pair
            p[v]=u;
        }
    }
    int inter=p[n-1];
    vi result;
    while (p[inter]!=inter)
    {
        result.push_back(inter);
        inter=p[inter];
    }
    reverse(result.begin(),result.end());
    if (!result.empty()) {
        for (int i: result) {
            cout << i << endl;
        }
    }
    else
        cout<<'-'<<endl;

}




/*



 */