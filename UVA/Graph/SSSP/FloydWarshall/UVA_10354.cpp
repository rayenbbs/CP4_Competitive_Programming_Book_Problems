#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vii vector<vi>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define umap unordered_map
#define uset unordered_set


#define f(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back


#define MOD 998244353
#define PI 3.1415926535897932384626433832795
#define INF 1e9

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V,E,BH,OF,H,M;
    while(cin >>V>>E>>BH>>OF>>H>>M){
        --BH;
        --OF;
        --H;
        --M;
        vii AM(V, vi(V, INF));
        f(i, 0, E) {
            int u, v, w;
            cin >> u >> v >> w;
            --u;
            --v;
            AM[u][v] = w;
            AM[v][u] = w;
        }
        if (BH==M || OF==M || BH==H || OF==H){
            cout<<"MISSION IMPOSSIBLE.\n";
        }
        else {
            f(i, 0, V) {
                AM[i][i] = 0;
            }
            vii tempAM(V,vi(V,INF));
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j)
                    tempAM[i][j] = AM[i][j]; // initialization


            for (int k = 0; k < V; ++k)
                for (int i = 0; i < V; ++i)
                    for (int j = 0; j < V; ++j) {
                        if (tempAM[i][k] + tempAM[k][j] < tempAM[i][j]) { // use if statement
                            tempAM[i][j] = tempAM[i][k] + tempAM[k][j];
                        }
                    }
            vi visited(V,0);
            for (int k = 0; k < V; ++k)
                if (tempAM[BH][k] + tempAM[k][OF] == tempAM[BH][OF]) { // use if statement
                    visited[k]=1;
                }

            for (int k = 0; k < V ; ++k)
                for (int i = 0; i < V ; ++i)
                    for (int j = 0; j < V ; ++j) {
                        if ( !visited[j]&& !visited[i]&& !visited[k])
                            if (AM[i][k] + AM[k][j] < AM[i][j]) { // use if statement
                                AM[i][j] = AM[i][k] + AM[k][j];
                            }
                    }
            if (AM[H][M]==INF || visited[H] || visited[M]){
                cout<<"MISSION IMPOSSIBLE.\n";
            }
            else cout<<AM[H][M]<<endl;
        }



    }

    return 0;

}