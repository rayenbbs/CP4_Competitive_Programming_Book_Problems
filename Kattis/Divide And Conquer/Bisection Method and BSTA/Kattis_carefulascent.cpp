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

int x;
int y;
vector<pair<pair<int,int>,double>> v;
const double EPS = 1e-7; // this EPS is adjustable

bool can(double target) {
    double xcoord=0;
    double prev=0;
    f(i,0,v.size()){
        xcoord+=target*(v[i].first.first-prev);
        xcoord+=target*v[i].second*(v[i].first.second-v[i].first.first);
        prev=v[i].first.second;
    }
    xcoord+=target*(y-prev);
    return(xcoord>x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >>x>>y;
    double n;
    cin >>n;
    v.assign(n,pair<pair<int,int>,double>());
    f(i,0,n){
        int l,u;
        double f;
        cin >> l >> u >> f;
        v[i]={{l,u},f};
    }

    sort(v.begin(),v.end());
    double lo = -10000000.0, hi = 10000000.0;
    while (fabs(hi-lo) > EPS) { // answer is not found yet
        double mid = (lo+hi) / 2.0; // try the middle value
        can(mid) ? hi = mid : lo = mid; // then continue
    }
    printf("%.10lf\n", hi);

}


