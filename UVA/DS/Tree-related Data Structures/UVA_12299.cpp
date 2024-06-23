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

vi a;

class SegmentTree {
private:
    int n;
    vi A, st;
    int l(int p) { return p<<1; }
    int r(int p) { return (p<<1)+1; }
    int conquer(int a, int b) {
        if (a ==-1) return b;
        if (b ==-1) return a;
        return min(a, b);
    }
    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            int m = (L+R)/2;
            build(l(p), L , m);
            build(r(p), m+1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    int RMQ(int p, int L, int R, int i, int j) {
        if (i > j) return-1;
        if ((L >= i) && (R <= j)) return st[p];
        int m = (L+R)/2;
        return conquer(RMQ(l(p), L , m, i , min(m, j)),


                       RMQ(r(p), m+1, R, max(i, m+1), j));
    }
    void update(int p, int L, int R, int i, int val) {
        if(i<L || i>R)
            return;
        if (R==L) {
            st[p] = val;
            a[i]=val;
        }
        else {
            int m = (L+R)/2;
            update(l(p), L , m, i , val);
            update(r(p), m+1, R,i, val);
            st[p] = conquer( st[l(p)] , st[r(p)]);
        }
    }
public:
    SegmentTree(int sz) : n(sz), st(4*n) {}
    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    void update(int i, int val) { update(1, 0, n-1, i, val); }
    int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n,q; cin>>n>>q;
    a.assign(n,0);
    f(i,0,n){
        cin>>a[i];
    }
    SegmentTree st(a);
    while(q--){
        string op; cin>>op;
        if(op[0]=='s'){
            vi rotate;
            string number;
            f(i,0,op.size()){
                if('0'<=op[i] && op[i]<='9'){
                    number.pb(op[i]);
                }
                else{
                    if(!number.empty()){
                        rotate.pb(atoi(number.c_str())-1);
                        number.clear();
                    }
                }
            }
            int temp=a[rotate[0]];
            f(i,1,rotate.size()){
                st.update(rotate[i-1],a[rotate[i]]);
            }
            st.update(rotate[rotate.size()-1],temp);
        }
        else{
            string number;
            vi query;
            f(i,0,op.size()){
                if('0'<=op[i] && op[i]<='9'){
                    number.pb(op[i]);
                }
                else{
                    if(!number.empty()){
                        query.pb(atoi(number.c_str())-1);
                        number.clear();
                    }
                }
            }
            cout<<st.RMQ(query[0],query[1])<<'\n';
        }
    }




    return 0;
}
