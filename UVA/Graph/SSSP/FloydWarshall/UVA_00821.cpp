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
    int u,v;
    cin >>u>>v;
    int t=1;
    while(u!=0 || v!=0) {

        vector<vector<double>> AM(101,vector<double>(101,INF));
        int V=101;
        printf("Case %d: ", t++);
        while(u!=0 || v!=0)
        {
            AM[u][v] = 1;
            cin >>u>>v;
        }

        for (int k = 0; k < V; ++k) // loop order is k->i->j
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                }

        double totaledges = 0;
        double totalscore = 0;
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (AM[i][j] != INF) {
                    if (i!=j){
                        ++totaledges;
                        totalscore += AM[i][j];
                    }
                }

        printf("average length between pages = %.3f clicks\n",totalscore/totaledges);
        cin >>u>>v;

    }

    return 0;

}