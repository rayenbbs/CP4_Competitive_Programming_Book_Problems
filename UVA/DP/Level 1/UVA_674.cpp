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


#define f(i,s,e) for(int i=s;i<e;i++)
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

/*inline ll mul(ll a, ll b) {
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


ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll lcm(ll a,ll b){
    return((a*b)/gcd(a,b));
}


double log_base(ll x, double base) {
    return std::log(x) / std::log(base);
}*/


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n=7490;
    vector<vector<ll>> dp(n,vector<ll>(5));
    vi coins={50,25,10,5,1};
    f(j,0,5){
        dp[0][j]=1;
    }
    f(i,0,n){
        f(j,0,5){
            if(i+coins[j]<7490)
                dp[i+coins[j]][j]+=dp[i][j];
            if(j+1<5 && i!=0)
                dp[i][j+1]+=dp[i][j];
        }
    }
    while(cin>>n){
        cout<<dp[n][4]<<'\n';
    }





    return 0;
}