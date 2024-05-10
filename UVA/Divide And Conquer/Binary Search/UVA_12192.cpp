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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R,C;
    int Q;
    int l,r;
    int ind;
    cin >>R>>C;
    int result;
    vii v(R,vi(C));
    while(R!=0 || C!=0){
        v.assign(R,vi(C));
        f(r,0,R){
            f(c,0,C){
                cin >>v[r][c];
            }
        }
        cin >>Q;
        f(q,0,Q){
            cin >>l>>r;
            result=0;
            f(j,0,R) {
                ind = lower_bound(v[j].begin(), v[j].end(), l) - v[j].begin();
                for (int i = min(R-j+1, C-ind+1)-1; i >= result + 1; i--) {
                    if (j+i - 1 < R && ind + i - 1 < C) {
                        if (v[j + i - 1][ind + i - 1] <= r) {
                            result = max(result, i);
                            break;
                        }
                    }
                }
            }
            cout<<result<<'\n';
        }
        cout<<"-\n";
        cin >>R>>C;
    }
}


