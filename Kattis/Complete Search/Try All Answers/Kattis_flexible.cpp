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
    int w,p;
    cin >>w>>p;
    vi distances(p+2);
    distances[0]=0;
    f(i,1,p+1){
        cin >>distances[i];
    }
    set<int> myset;
    distances[p+1]=w;
    f(i,0,p+2){
        f(j,i+1,p+2){
            myset.insert(distances[j]-distances[i]);
        }
    }
    int t=1;
    for(int p:myset){
        if (t==1){
            ++t;
        }
        else cout<<" ";
        cout<<p;
    }
    cout<<'\n';
}
