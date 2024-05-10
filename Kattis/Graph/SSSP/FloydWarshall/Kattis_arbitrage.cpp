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
    int V;
    cin >>V;
    while(V!=0){
        umap<string,int> mymap;
        umap <int,string> revmap;
        vector<vector<double>> AM(V,vector<double>(V,INF));
        f(i,0,V){
            string a;
            cin >>a;
            mymap[a]=i;
            revmap[i]=a;
        }
        int E;
        cin >>E;
        f(i,0,E){
            string u,v;
            string w;
            cin >>u>>v>>w;
            f(j,0,w.size()){
                if (w[j]==':')
                    w[j]=' ';
            }
            stringstream ss(w);
            double w1,w2;
            ss>>w1>>w2;
            AM[mymap[u]][mymap[v]]=w1/w2;
        }
        f(i,0,V){

            AM[i][i]=1;

        }
        for (int k = 0; k < V; ++k) // loop order is k->i->j
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j)
                    AM[i][j] = min(AM[i][j], AM[i][k]*AM[k][j]);
        bool test=true;
        f(i,0,V){

            if (AM[i][i]<1 && AM[i][i]!=INF){
                test=false;
            }
        }
        if (!test)
            cout<<"Arbitrage\n";
        else cout<<"Ok\n";
        cin >>V;
    }


    return 0;

}