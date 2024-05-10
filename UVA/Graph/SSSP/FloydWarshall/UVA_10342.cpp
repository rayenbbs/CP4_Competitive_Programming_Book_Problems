#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vii vector<vector<int>>
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

void dfs(int u,int v,int w,vii &AM,vii &result,vector<vector<pair<int,int>>> &AL){
if (w>result[u][v]) return ;
if (w > AM[u][v]) {
result[u][v] = w;
}
for (auto &[k, c]: AL[v]) {
dfs(u, k, w + c, AM, result, AL);
}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V,E;
    int testcount=1;
    while(cin >>V>>E){
        cout<<"Set #"<<testcount++<<endl;
        vii AM(V,vi(V,INF));
        vector<vector<pair<int,int>>> AL(V,vector<pair<int,int>>());
        f(i,0,E){
            int u,v,w;
            cin >>u>>v>>w;
            AL[u].emplace_back(v,w);
            AL[v].emplace_back(u,w);
            AM[u][v]=w;
            AM[v][u]=w;
        }
        f(i,0,V){
            AM[i][i]=0;
        }
        for (int k = 0; k < V; ++k) // loop order is k->i->j
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j)
                    AM[i][j] = min(AM[i][j], AM[i][k]+AM[k][j]);
        vii result(V,vi(V,INF));
        f(i,0,V){
            dfs(i,i,0,AM,result,AL);
        }
        /*f(i,0,V){
            f(j,0,V){
                cout<<result[i][j]<<endl;
            }
        }*/
        int q;
        cin >>q;
        f(i,0,q){
            int s,d;
            cin >>s>>d;
            if (result[s][d]==INF)
            {
                cout<<"?\n";
            }
            else cout<<result[s][d]<<endl;
        }
    }

    return 0;

}