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


//#define f(i,s,e) for(int i=s;i<e;i++)
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


ll lcm(ll a, ll b){
    return ((a*b)/ gcd(a,b));
}


int dr[] = { -1, 0, -1};
// the order is:
int dc[] = { 0, 1, 1};
// S/SE/E/NE/N/NW/W/SW

class FenwickTree {
private:
    vll ft;
public:
    FenwickTree(int m) { ft.assign(m+1, 0); }
    void build(const vll &f) {
        int m = (int)f.size()-1;
        ft.assign(m+1, 0);
        for (int i = 1; i <= m; ++i) {
            ft[i] += f[i];
            if (i+LSOne(i) <= m)
                ft[i+LSOne(i)] += ft[i];
        }
    }
    FenwickTree(const vll &f) { build(f); }
    FenwickTree(int m, const vi &s) {
        vll f(m+1,0);
        for (int i = 0; i < (int)s.size(); ++i)
            ++f[s[i]];
        build(f);
    }
    ll rsq(int j) {
        ll sum = 0;
        for (; j; j-= LSOne(j))
            sum += ft[j];
        return sum;
    }

    ll rsq(int i, int j) { return rsq(j)- rsq(i-1); } // inc/exclusion
// updates value of the i-th element by v (v can be +ve/inc or-ve/dec)
    void update(int i, ll v) {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n,q; cin>>n>>q;
    FenwickTree ft(n);
    for(int i=0;i<q;++i){
        char query; cin>>query;
        if(query=='+'){
            ll a,b; cin>>a>>b;
            ft.update(a+1,b);
        }
        else{
            ll a; cin>>a;
            cout<<ft.rsq(a)<<'\n';
        }
    }



    return 0;
}
