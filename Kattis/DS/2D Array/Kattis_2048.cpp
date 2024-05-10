#include <bits/stdc++.h>
using namespace std;


#define LSOne(S) ((S) & -(S))
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


#define MOD 998244353
#define PI 3.1415926535897932384626433832795
#define INF 1e9

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

vii v(4,vi(4));


void rotate(){
    vii v1(4,vi(4));
    f(r,0,4) {
        f(c, 0, 4) {
            v1[c][r] = v[3-r][c];
        }
    }
    f(r,0,4){
        f(c,0,4){
            v[r][c]=v1[r][c];
        }
    }
}

void shiftleft(){
    f(r,0,4){
        f(c,0,4){
            if (v[r][c]!=0){
                f(c1,0,c){
                    if (v[r][c1]==0){
                        v[r][c1]=v[r][c];
                        v[r][c]=0;
                    }
                }
            }
        }
    }
}

//shorter solution utilizing symmetries

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    f(r,0,4){
        f(c,0,4){
            cin>>v[r][c];
        }
    }
    int position; cin>>position;
    f(i,0,4-position){
        rotate();
    }
    shiftleft();
    f(r,0,4){
        f(c,0,4){
            if (c+1<4) {
                if (v[r][c] == v[r][c + 1]) {
                    v[r][c] += v[r][c + 1];
                    v[r][c + 1]=0;
                }
            }
        }
    }
    shiftleft();
    f(i,0,position){
        rotate();
    }
    f(r,0,4){
        f(c,0,4){
            if(c){
                cout<<" ";
            }
            cout<<v[r][c];
        }
        cout<<'\n';
    }
    return 0;
}