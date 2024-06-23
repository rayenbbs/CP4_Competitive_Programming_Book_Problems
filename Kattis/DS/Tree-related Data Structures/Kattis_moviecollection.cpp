#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define umap unordered_map
#define uset unordered_set


#define f(i,s,e) for(ll i=(ll)s;i<(ll)e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


#define PI 3.1415926535897932384626433832795

#define LSOne(S) ((S) & -(S))

const int INF = 2e9;
const int MOD = 1000000007;

#include <bits/extc++.h>
// pbds
using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
tree_order_statistics_node_update> ost;

inline ll mul(ll a, ll b) {
    return (a%MOD * b%MOD) % MOD;
}

inline ll sum(ll a, ll b) {
    return (a%MOD + b%MOD) % MOD;
}

inline ll sub(ll a, ll b) {
    return (((a-b)%MOD)+MOD)%MOD;
}

ll int_sqrt (ll x) {
    ll ans = 0;
    for (ll k = 1LL << 30; k != 0; k /= 2) {
        if ((ans + k) * (ans + k) <= x) {
            ans += k;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;
    while(t--) {
        int m,r; cin>>m>>r;
        vi v(m);
        ost tree;
        umap<int,int> values;
        f(i,0,m){
            tree.insert({i,i+1});
            values[i+1]=i;
        }
        int distinct=-1;
        f(i,0,r){
            int target; cin>>target;
            cout<<tree.order_of_key({values[target],target})<<' ';
            tree.erase({values[target],target});
            values[target]=distinct;
            tree.insert({distinct,target});
            distinct--;
        }
        cout<<'\n';


    }

    return 0;
}
