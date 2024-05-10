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
    int n,m,q;
    cin >>n>>m>>q;
    while(n!=0 || m!=0 || q!=0){
        vii AM(150,vi(150,INF));
        int V=150;
        f(i,0,V)
        {
            AM[i][i]=0;
        }

        f(i,0,m){
            int u,v,w;
            cin >>u>>v>>w;
            AM[u][v]=min(AM[u][v],w);
        }

        for (int k = 0; k < V; ++k) // loop order is k->i->j
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j)
                    if (AM[i][k]!=INF && AM[k][j]!=INF) {
                        AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                    }


        for (int k = 0; k < V; ++k) // loop order is k->i->j
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j)
                    if (AM[i][k]!=INF && AM[k][j]!=INF && AM[k][k]<0) {

                        AM[i][j]=-INF;
                    }

        f(i,0,q){
            int u,v;
            cin >>u >>v;
            if ((int)AM[u][v]==INF){
                printf("Impossible\n");
            }
            else if ((int)AM[u][v]==-INF){
                printf("-Infinity\n");
            }
            else
                printf("%d\n",AM[u][v]);
        }
        cin >>n>>m>>q;
        if (n!=0 || m!=0 || q!=0){
            printf("\n");
        }
    }
    return 0;

}