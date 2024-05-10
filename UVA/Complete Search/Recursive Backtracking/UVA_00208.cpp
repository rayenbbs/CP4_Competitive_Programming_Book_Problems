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


#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void backtrack(vii& routes,vi & used,int &count, vii& adj,int curr,int dest, vi& path){
    if (curr==dest)
    {
        ++count;
        routes.pb(path);
    }
    else
    {
        f(i, 0, adj[curr].size()) {
            if (!used[adj[curr][i]]) {
                path.pb(adj[curr][i]);
                used[adj[curr][i]] = 1;
                backtrack(routes,used, count, adj, adj[curr][i], dest, path);
                path.pop_back();
                used[adj[curr][i]] = 0;
            }
        }
    }
}

void dfs(vii & adj, int curr, vi& exp){
    exp[curr]=1;
    f(i,0,adj[curr].size()){
        if (!exp[adj[curr][i]]){
            dfs(adj,adj[curr][i],exp);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int testcount=1;
    while(cin >>n){
        cout<<"CASE "<<testcount++<<":\n";
        --n;
        vii adj(25,vi());
        vi used(25,0);
        int a,b;
        cin >>a>>b;
        while(a!=0 || b!=0){
            --a; --b;
            adj[a].pb(b);
            adj[b].pb(a);
            cin >>a>>b;
        }
        vi path;
        int count=0;
        path.pb(0);
        used[0]=1;
        vi exp(25,0);
        dfs(adj,0,exp);
        vii routes;
        if (exp[n]){
            backtrack(routes,used,count,adj,0,n,path);
            sort(routes.begin(),routes.end());
            f(i,0,routes.size()){
                f(j,0,routes[i].size()){
                    if(j!=0){
                        cout<<" ";
                    }
                    cout<<routes[i][j]+1;
                }
                cout<<'\n';
            }
            cout<<"There are "<< count<<" routes from the firestation to streetcorner "<<n+1<<".\n";
        }
        else  cout<<"There are "<< 0<<" routes from the firestation to streetcorner "<<n+1<<".\n";
    }

}