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

struct node {
    int sum;
    int l;
    int r;
    node(){
        sum=0;
        l=0;
        r=-1;
    }
    node(int s,int left,int right){
        sum=s;
        l=left;
        r=right;
    }
};

class SegmentTree {
private:
    int n;
    vector<node> st;
    vi A, lazy;
    int l(int p) { return p<<1; }
    int r(int p) { return (p<<1)+1; }
    int conquer(int a, int b) {
        if (a ==-1) return b;
        if (b ==-1) return a;
        return (a + b);
    }
    void build(int p, int L, int R) {
        if (L == R) {
            st[p].sum =A[L];
            st[p].l=L;
            st[p].r=R;
        }
        else {
            int m = (L+R)/2;
            build(l(p), L , m);
            build(r(p), m+1, R);
            st[p].sum =conquer(st[l(p)].sum, st[r(p)].sum);
            st[p].l=L;
            st[p].r=R;
        }
    }
    void propagate(int p, int L, int R) {
        if (lazy[p] !=-1) {
            if(lazy[p]==0){
                st[p].sum=0;
            }
            else if(lazy[p]==1){
                st[p].sum=st[p].r-st[p].l+1;
            }
            else if(lazy[p]==2){
                st[p].sum=st[p].r-st[p].l+1-st[p].sum;
            }
            if (L != R){
                if(lazy[p]==2){
                    if(lazy[l(p)]==1){
                        lazy[l(p)]=0;
                    }
                    else if(lazy[l(p)]==0){
                        lazy[l(p)]=1;
                    }
                    else if(lazy[l(p)]==2){
                        lazy[l(p)]=-1;
                    }
                    else {
                        lazy[l(p)]=lazy[p];
                    }
                    if(lazy[r(p)]==1){
                        lazy[r(p)]=0;
                    }
                    else if(lazy[r(p)]==0){
                        lazy[r(p)]=1;
                    }
                    else if(lazy[r(p)]==2){
                        lazy[r(p)]=-1;
                    }
                    else {
                        lazy[r(p)]=lazy[p];
                    }
                }
                else
                    lazy[l(p)] = lazy[r(p)] = lazy[p];
            }
            else {
                if(lazy[p]==0)
                    A[L] = 0;
                else if(lazy[p]==1){
                    A[L]=1;
                }
                else if (lazy[p]==2){
                    A[L]+=1; A[L]%=2;
                }
            }
            lazy[p] =-1;
        }
    }
    int query(int p, int L, int R, int i, int j) { // O(log n)
        propagate(p, L, R);
        if (i > j) return-1;
        if ((L >= i) && (R <= j))
        {
            return st[p].sum;
        }
        int m = (L+R)/2;
        return conquer(query(l(p), L , m, i
                               , min(m, j)),
                       query(r(p), m+1, R, max(i, m+1), j));
    }
    void update(int p, int L, int R, int i, int j, int val) {
        propagate(p, L, R);
        if (i > j) return;
        if ((L >= i) && (R <= j)) {
            lazy[p] = val;
            propagate(p, L, R);
        }
        else {
            int m = (L+R)/2;
            update(l(p), L , m, i, min(m, j), val);
            update(r(p), m+1, R, max(i, m+1), j,val);
            st[p].sum =  conquer(st[l(p)].sum,st[r(p)].sum);
        }
    }
public:
    SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n,-1) {}
    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
    int query(int i, int j) { return query(1, 0, n-1, i, j); }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    int testcase=1;


    while(t--){
        cout<<"Case "<<testcase++<<":\n";
        int size=0;

        int m; cin>>m;
        vector<string> inputs(m);
        vi repetitions(m);
        f(i,0,m){
            cin>>repetitions[i];
            cin>>inputs[i];
            size+=repetitions[i]*inputs[i].size();
        }
        vi a(size);
        int indice=0;
        f(i,0,m){
            f(j,0,repetitions[i]){
                for(char e:inputs[i]){
                    a[indice]=e-'0';
                    indice++;
                }
            }
        }
        SegmentTree st(a);
        int q; cin>>q;
        int querynumber=1;
        while(q--){
            char query; cin>>query;  int l,r; cin>>l>>r;
            switch(query){
                case 'F':
                    st.update(l,r,1);
                    break;
                case 'E':
                    st.update(l,r,0);
                    break;
                case 'I':
                    st.update(l,r,2);
                    break;
                case 'S':
                    cout<<"Q"<<querynumber++<<": ";
                    cout<<st.query(l,r)<<'\n';
                    break;
            }
        }
    }




    return 0;
}
