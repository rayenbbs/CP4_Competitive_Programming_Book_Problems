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

int R,C;
vector<vector<string>> grid;

int dr[] = { 1,  0,-1, 0 }; // the order is:
int dc[] = { 0, 1,  0,-1}; // S/SE/E/NE/N/NW/W/SW
int floodfill(int r, int c, string c1, string c2) { // returns the size of CC
    if ((r < 0) || (r >= R)) return 0; // outside grid, part 1
    if ((c < 0) || (c >= C)) return 0; // outside grid, part 2
    if (grid[r][c] != c1) return 0; // does not have color c1
    int ans = 1;
    grid[r][c] = c2;
    for (int d = 0; d < 4; ++d)
        ans += floodfill(r+dr[d], c+dc[d], c1, c2);
    return ans;
}






int main()
{

    cin >> R >> C;
    grid.assign(R,vector<string>(C,"0"));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            char a;
            cin >>a;
            grid[r][c]=a;
        }
    }
    int count=2;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c)
        {
            if (grid[r][c]=="0")
            {
                floodfill(r, c, "0", (string) (to_string(count)));
            }
            else if(grid[r][c]=="1")
            {
                floodfill(r,c,"1",(string)('-'+ to_string(count)));
            }
            count++;
        }
    }
    int n;
    cin >>n;
    while(n--)
    {
        int r1,c1,r2,c2;
        cin >>r1>>c1>>r2>>c2;
        if (grid[r1-1][c1-1]!=grid[r2-1][c2-1])
            cout<<"neither\n";
        else
        {
            if (grid[r1-1][c1-1][0]=='-')
                cout<<"decimal\n";
            else
                cout<<"binary\n";
        }
    }
}