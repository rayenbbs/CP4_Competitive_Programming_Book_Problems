include <bits/stdc++.h>
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
const int EXPLORED=-3;

vector<vi> AL;
vector<vi> AL1;
vi ts;
vi dfs_parent;
vector<vector<char>>grid;
vector<vi> dfs_num;
int R,C;


int main()
{
    //ios_base::sync_with_stdio(false);
    int N;
    cin >>N;
    AL.assign(N,vi());
    queue<int> resultqueue;
    for (int i=0;i<N-1;++i)
    {
        int a,b;
        cin >>a>>b;
        resultqueue.push(b);
        AL[a-1].push_back(b-1);
        AL[b-1].push_back(a-1);
    }

    int s = 0;
    queue<int> q; q.push(s);
    vi color(N, INF); color[s] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &v : AL[u]) {
            if (color[v] == INF) {
                color[v] = 1-color[u];
                q.push(v);
            }
        }
    }
    while (!resultqueue.empty())
    {
        cout<<color[resultqueue.front()-1]<<endl;
        resultqueue.pop();

    }

    return 0;
}

