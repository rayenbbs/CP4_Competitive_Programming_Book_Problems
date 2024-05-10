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

vector<ll> weights;
ll n;
ll total;
ll result;
vector<ll> used;

void backtrack(ll indice){
    if (total>=200)
        return;
    else if (total<200){
        result+=total;
    }
    f(i,indice,n){
        if (!used[i]){
            total+=weights[i];
            used[i]=1;
            backtrack(i+1);
            used[i]=0;
            total-=weights[i];
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n;
    weights.assign(n,0);
    used.assign(n,0);
    total=0;
    result=0;
    ll sum=0;
    f(i,0,n){
        cin>>weights[i];
        sum+=weights[i]*(pow(2,n-1));
    }
    backtrack(0);
    cout<<sum-result<<'\n';
}