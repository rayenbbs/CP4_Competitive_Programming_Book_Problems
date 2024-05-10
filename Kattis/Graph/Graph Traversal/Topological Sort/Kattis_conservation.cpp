#include <bits/stdc++.h>
using namespace std;

/* clang-format off */

/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { for (auto x : v) cout << x; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

const int INF=1e9;
const int VISITED=-1;
const int UNVISITED=-2;
vi dfs_num;
vector<vi> AL;
vi ts;


int main()
{
    //ios_base::sync_with_stdio(false);
    int t;
    cin >>t;
    while(t--) {
        int V, m;
        cin >> V >> m;
        vi in_degree1(V, 0);
        vi in_degree2(V, 0);
        vi lab(V,0);
        AL.assign(V, vi());
        for (int i=0;i<V;++i)
        {
            cin>>lab[i];
        }
        while(m--)
        {
            int a,b;
            cin >>a>>b;
            AL[a-1].push_back(b-1);
            in_degree1[b-1]++;
            in_degree2[b-1]++;
        }
        int t=0;
        int labswitch1 = 0;
        int labswitch2 = 0;
        if (t==0) {
            t++;
            queue<int> q1, q2;
            for (int i = 0; i < V; ++i) {
                if (in_degree1[i] == 0) {
                    if (lab[i] == 1)
                        q1.push(i);
                    else
                        q2.push(i);
                }
            }
            int prec=1;


            while (!q1.empty() || !q2.empty()) {
                int u;
                if (prec == 1 && !q1.empty()) {
                    u = q1.front();
                    q1.pop();
                } else if (prec == 2 && !q2.empty()) {
                    u = q2.front();
                    q2.pop();
                } else if (!q1.empty()) {
                    u = q1.front();
                    q1.pop();
                    ++labswitch1;
                    prec = 1;

                } else if (!q2.empty()) {
                    u = q2.front();
                    q2.pop();
                    ++labswitch1;
                    prec = 2;

                } else
                    cout << "ERROR" << endl;

                for (auto &v: AL[u]) {
                    in_degree1[v]--;
                    if (in_degree1[v] > 0) continue;
                    if (lab[v] == 1)
                        q1.push(v);
                    else
                        q2.push(v);
                }
            }
        }
        queue<int> q1, q2;
        for (int i = 0; i < V; ++i) {
            if (in_degree2[i] == 0) {
                if (lab[i] == 1)
                    q1.push(i);
                else
                    q2.push(i);
            }
        }
        int prec=2;


        while (!q1.empty() || !q2.empty()) {
            int u;
            if (prec == 1 && !q1.empty()) {
                u = q1.front();
                q1.pop();
            } else if (prec == 2 && !q2.empty()) {
                u = q2.front();
                q2.pop();
            } else if (!q1.empty()) {

                u = q1.front();
                q1.pop();
                ++labswitch2;
                prec = 1;

            } else if (!q2.empty()) {

                u = q2.front();
                q2.pop();
                ++labswitch2;
                prec = 2;

            } else
                cout << "ERROR" << endl;

            for (auto &v: AL[u]) {
                in_degree2[v]--;
                if (in_degree2[v] > 0) continue;
                if (lab[v] == 1)
                    q1.push(v);
                else
                    q2.push(v);
            }
        }
        cout<<min(labswitch1,labswitch2)<<endl;


    }


}
