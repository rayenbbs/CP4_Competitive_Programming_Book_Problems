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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >>n>>m;
    vector<pair<int,int>> restrictions(m);
    f(i,0,m){
        int a,b;
        cin >>a>>b;
        --a; --b;
        restrictions[i].first=a;
        restrictions[i].second=b;
    }
    vi perm(n);
    f(i,0,n){
        perm[i]=i;
    }
    uset <int> selected;
    int best=0;
    bool test;
    int countselected;
    f(i,0,1<<n){
        selected.clear();
        selected.reserve(2*n);
        countselected=0;
        f(j,0,n){
            if(i & 1<<j){
                selected.insert(perm[j]);
            }
        }
        test=true;
        f(j,0,restrictions.size()){
            if (selected.find(restrictions[j].first)!=selected.end() && selected.find(restrictions[j].second)!=selected.end()){
                test=false;
                break;
            }
        }
        if(!test){
            continue;
        }
        ++best;
    }
    cout<<best<<'\n';
}
