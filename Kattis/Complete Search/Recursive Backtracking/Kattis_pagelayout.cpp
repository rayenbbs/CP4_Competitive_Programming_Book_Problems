#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vii vector<vi>
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


#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

vector<pair<pii,pii>> v;
vector<pair<pii,pii>> taken;

vii grid;
ll total;
int n;
int temp;
int result;


void backtrack(int indice){
    result=max(result,temp);
    if (indice==n)
        return;
    backtrack(indice+1);
    int w, h, x, y;
    w = v[indice].first.first;
    h = v[indice].first.second;
    x = v[indice].second.first;
    y = v[indice].second.second;
    bool test=true;
    for(auto u:taken){
        if (x<u.second.first+u.first.first && y<u.second.second+u.first.second && x+w > u.second.first && y+h>u.second.second){
            test=false;
        }
    }
    if (test){
        taken.pb({{w,h},{x,y}});
        temp+=w*h;
        backtrack(indice+1);
        taken.pop_back();
        temp-=w*h;
    }
    else{
        return ;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n;
    while(n!=0)
    {
        v.assign(n,pair<pii,pii>());
        f(i, 0, n) {
            int w, h, x, y;
            cin >> w >> h >> x >> y;
            v[i]={{w,h},{x,y}};
        }
        result=-1;
        temp=0;
        grid.assign(1001, vi(1001, -1));
        backtrack(0);
        cout << result << '\n';
        cin >> n;

    }
}