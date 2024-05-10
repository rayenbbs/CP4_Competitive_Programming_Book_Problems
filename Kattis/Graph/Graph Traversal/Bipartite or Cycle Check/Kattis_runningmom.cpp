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
const int EXPLORED=-3;
vi dfs_num;
vector<vi> AL;
vi ts;
vi dfs_parent;


void cycleCheck(int u,bool &test) { // check edge properties
    dfs_num[u] = EXPLORED; // color u as EXPLORED
    for (auto &v : AL[u]) { // C++17 style, w ignored

        if (dfs_num[v] == UNVISITED) { // EXPLORED->UNVISITED
            // a tree edge u->v
            cycleCheck(v,test);
        }
        else if (dfs_num[v] == EXPLORED) { // EXPLORED->EXPLORED
            test=true;// a non trivial cycle
        }
        else if (dfs_num[v] == VISITED) // EXPLORED->VISITED
            ; // rare application
    }
    dfs_num[u] = VISITED; // color u as VISITED/DONE
}

int main()
{
    //ios_base::sync_with_stdio(false);
    int n;
    cin >>n;
    unordered_map<string,int> mymap;
    unordered_map<int,string> revmap;
    int ind=-1;
    while(n--)
    {
        string a,b;
        cin>>a>>b;
        if (mymap.find(a)==mymap.end())
        {
            ind++;
            mymap[a]=ind;
            revmap[ind]=a;
            AL.push_back(vi());
        }
        if (mymap.find(b)==mymap.end())
        {
            ind++;
            mymap[b]=ind;
            revmap[ind]=b;
            AL.push_back(vi());
        }

        AL[mymap[a]].push_back(mymap[b]);
    }
    string target;
    while(cin>>target)
    {
        dfs_num.assign(ind+1,UNVISITED);
        bool test=false;
        cycleCheck(mymap[target],test);
        if (test)
            cout<<target<<" safe\n";
        else
            cout<<target<<" trapped\n";

    }





}
