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
#define mll map<ll, ll>
#define si set<int>
#define sc set<char>
#define umap unordered_map
#define uset unordered_set

#define endl '\n'
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
const ll MOD = 1000000007;



ll binpow(ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res%MOD;
}




ll Cat[1000+5];


void solve(){
    Cat[0]=1;
    int n;
    bool first=true;
    while(cin>>n) {
        if(!first){
            cout<<endl;
        } else first=false;
        for (int i = 0; i <= n; ++i) {
            Cat[i + 1] = (((4 * i + 2) * Cat[i]) / (i + 2));
        }
        cout << Cat[n] << endl;
    }


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t=1;
//    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}