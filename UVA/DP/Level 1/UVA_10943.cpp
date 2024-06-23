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

const int INF = 1e9;
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

    int n,k;
    while(cin>>n>>k && n) {
        vector<vi> dp(n + 1, vi(k + 1));
        for(int i=0;i<k;++i){
            dp[0][i]=1;
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < k; ++j) {
                for (int x = 0; x <= n; ++x) {
                    if(i+x==0) continue;
                    if (i + x <= n) {
                        dp[i + x][j + 1]+=dp[i][j];
                        dp[i + x][j + 1] %= 1000000;
                    }
                }
            }
        }
        cout << dp[n][k] %1000000 << '\n';
    }







    return 0;
}