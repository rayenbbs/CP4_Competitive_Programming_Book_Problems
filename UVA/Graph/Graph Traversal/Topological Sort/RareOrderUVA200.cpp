#include <bits/stdc++.h>
using namespace std;

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


void toposort(int u) {
    dfs_num[u] = VISITED;
    for (auto &v : AL[u])
        if (dfs_num[v] == UNVISITED)
            toposort(v);
    ts.push_back(u);
}

int main()
{

    ios_base::sync_with_stdio(false);
    unordered_map<char, int> mymap;
    unordered_map<int, char> revmap;
    string line;
    int V=0;
    char temp;
    int countline=0;
    vector<vector<char>>templist;
    while(true) {
        if (temp=='#')
            break;
        templist.push_back(vector<char>());
        getline(cin,line);
        stringstream l (line);
        while (l >> temp) {
            if (temp=='#')
                break;
            if (mymap.find(temp) == mymap.end()) {
                mymap[temp] = V;
                revmap[V] = temp;
                V++;
            }
            templist[countline].push_back(temp);

        }
        countline++;
    }
    AL.assign(V, vi());
    for (int i=0;i<countline-2;++i)
    {
        for (int j=0;j<min(templist[i].size(),templist[i+1].size());++j)
        {
            if (templist[i][j]!=templist[i+1][j])
            {
                AL[mymap[templist[i][j]]].push_back(mymap[templist[i+1][j]]);
                break;
            }
        }
    }

    char s=templist[0][0];
    dfs_num.assign(V, UNVISITED);
    ts.clear();
    toposort(mymap[s]);
    reverse(ts.begin(), ts.end());
    for (auto &u: ts)
        cout << revmap[u];
    cout<<endl;
}
