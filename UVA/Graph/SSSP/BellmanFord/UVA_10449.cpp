#include <bits/stdc++.h>
using namespace std;


typedef vector<int> vi;
typedef vector<vi> vii;
const int INF=1e9;

void dfs(int u,vector<vi> &AL,vi&dist){
    dist[u]=-INF;
    for(auto &v:AL[u]){
        if (dist[v]!=-INF){
            dist[v]=-INF;
            dfs(v,AL,dist);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int t=1;
    while(cin >>n)
    {
        cout << "Set #" << t++ << "\n";
        if (n!=0) {
            vii AL(n, vi());
            for(int i=0;i<n;++i){
                AL[i].reserve(n);
            }
            vi business(n, 0);
            for (int i=0; i < n; ++i) {
                int b;
                cin >>b;
                business[i]=b;
            }
            int r;
            cin >> r;
            for (int i = 0; i < r; ++i) {
                int u, v;
                cin >> u >> v;
                --u;
                --v;
                AL[u].emplace_back(v);
            }
            int q;
            cin >> q;
            int s = 0;
            // inside int main()
            vi dist(n, INF);
            dist[s] = 0; // INF = 1e9 here
            for (int i = 0; i < n - 1; ++i) { // total O(V*E)
                bool modified = false; // optimization

                for (int u = 0; u < n; ++u) // these two loops = O(E)
                    if (dist[u] != INF) // important check
                        for (auto &v: AL[u]) {
                            if (dist[u] + (int)pow(business[v] - business[u],3) >= dist[v]) continue; // not improving, skip
                            dist[v] = dist[u] + (int)pow(business[v] - business[u],3); // relax operation
                            modified = true; // optimization
                        }
                if (!modified) break; // optimization
            }
            for (int u = 0; u < n; ++u) // one more pass to check
                if (dist[u]!=INF)
                    for (auto &v : AL[u]) // C++17 style
                        if (dist[v] > dist[u]+(int)pow(business[v] - business[u],3) ) { // should be false
                            dfs(v,AL,dist);
                        }

            for (int i = 0; i < q; ++i) {
                int u;
                cin >> u;
                --u;
                if (dist[u]!=INF){
                    if (dist[u] < 3)
                        cout << "?\n";
                    else cout << dist[u] << "\n";
                }
                else cout<<"?\n";

            }

        }
        else
        {
            int a,b;
            cin >>a>>b;
        }




    }
}

/*

5 6 7 8 9 10
6
1 2
2 3
3 4
1 5
5 4
4 5
2
4
5
  5 6 7 8 9 20
6
1 2
2 3
3 4
1 5
5 4
4 5
2
4
5
 5 6 7 8 9 10
6
1 2
2 3
3 4
1 5
5 4
4 5
2
4
5

 *
 */