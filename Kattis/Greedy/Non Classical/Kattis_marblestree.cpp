#include <bits/stdc++.h>
using namespace std;


#define LSOne(S) ((S) & -(S))
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

vector<ll> outdeg;
vii AL;
vector<ll> marbles;
int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    while(n!=0){
        AL.assign(n,vi());
        marbles.assign(n,0);
        outdeg.assign(n,0);
        f(i,0,n){
            int v,m,d;
            cin>>v>>m>>d;
            v--;
            marbles[v]=m;
            f(j,0,d){
                int child;
                cin>>child;
                child--;
                AL[child].pb(v);
                outdeg[v]++;
            }
        }
        queue <int> leafs;
        f(i,0,n){
            if (outdeg[i]==0){
                leafs.push(i);
            }
        }
        ll score=0;
        while (!leafs.empty()){
            int top=leafs.front(); leafs.pop();
            if (!AL[top].empty()){
                int next=AL[top][0];
                outdeg[next]--;
                if (outdeg[next]==0){
                    leafs.push(next);
                }
                int diff=marbles[top]-1;
                marbles[next]+=diff;
                score+=abs(diff);
            }
        }
        cout<<score<<'\n';
        cin>>n;

    }
}