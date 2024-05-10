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



void printPath(int i, int j,vii &p,char dest) {
    if (i != j) printPath(i, p[i][j],p,dest);
    if (j+'A'!=dest)
        printf("%c ", j+'A');
    else      printf("%c", j+'A');

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s,e;
    cin >>s>>e;
    vii AM(26,vi(26,INF));
    vii p(26,vi(26,INF));
    vii pcount(26,vi(26,1));
    f(i,0,e){
        char u,v;
        int w;
        cin >>u >>v >>w;
        AM[u-'A'][v-'A']=w;
        AM[v-'A'][u-'A']=w;

    }
    int V=26;
    // inside int main()
// let p be a 2D parent matrix, where p[i][j] is the last vertex before j
// on a shortest path from u to v, i.e., i -> ... -> p[i][j] -> j
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            p[i][j] = i; // initialization
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j) {
                if (AM[i][k] + AM[k][j] < AM[i][j]) { // use if statement
                    AM[i][j] = AM[i][k] + AM[k][j];
                    pcount[i][j]=pcount[i][k]+pcount[k][j];
                    p[i][j] = p[k][j]; // update the p matrix
                }
                if (AM[i][k] + AM[k][j] == AM[i][j]) { // use if statement
                    if (pcount[i][j]>pcount[i][k]+pcount[k][j]){
                        p[i][j] = p[k][j]; // update the p matrix
                        pcount[i][j]=pcount[i][k]+pcount[k][j];
                    }
                }
            }
    int n;
    cin >>n;

    f(i,0,n){
        char a,b;
        cin >>a>>b;
        printPath((int)a-'A',(int)b-'A',p,b);
        printf("\n");
    }
    return 0;

}