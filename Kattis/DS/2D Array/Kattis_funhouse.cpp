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

vector<vector<char>> v;
int w,h;

void simulate(int direction,int row,int column){
    if (direction==0){
        for(int i=column-1;i>=0;--i){
            if (v[row][i]=='\\'){
                simulate(1,row,i);
                return;
            }
            else if (v[row][i]=='/'){
                simulate(3,row,i);
                return;
            }
            else if(v[row][i]=='x'){
                v[row][i]='&';
                return ;
            }
        }

    }
    else if(direction==1){
        for(int i=row-1;i>=0;--i){
            if (v[i][column]=='\\'){
                simulate(0,i,column);
                return;
            }
            else if(v[i][column]=='/'){
                simulate(2,i,column);
                return;
            }
            else if(v[i][column]=='x'){
                v[i][column]='&';
                return ;
            }
        }
    }
    else if (direction==2) {
        for (int i = column + 1; i < w; ++i) {
            if (v[row][i] == '\\') {
                simulate(3, row, i);
                return;
            } else if (v[row][i] == '/') {
                simulate(1, row, i);
                return;
            } else if (v[row][i] == 'x') {
                v[row][i] = '&';
                return;
            }
        }
    }
    else if(direction==3){
        for(int i=row+1;i<h;++i){
            if (v[i][column]=='\\'){
                simulate(2,i,column);
                return;
            }
            else if(v[i][column]=='/'){
                simulate(0,i,column);
                return;
            }
            else if(v[i][column]=='x'){
                v[i][column]='&';
                return ;
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcount=1;
    while(cin>>w>>h && w){
        cout<<"HOUSE "<<testcount++<<'\n';
        v.assign(h,vector<char> (w));
        f(r,0,h) {
            f(c, 0, w) {
                cin>>v[r][c];
            }
        }
        f(r,0,h) {
            f(c, 0, w) {
                if (v[r][c] == '*') {
                    if (r + 1 < h && v[r + 1][c] != 'x' ) {
                        simulate(3, r, c);
                    }  else if (r - 1 >= 0 && v[r - 1][c] != 'x') {
                        simulate(1, r, c);
                    } else if (c + 1 < w && v[r][c + 1] != 'x') {
                        simulate(2, r, c);
                    } else if (c - 1 >= 0 && v[r][c - 1] != 'x') {
                        simulate(0, r, c );
                    }
                }
            }
        }
        f(r,0,h){
            f(c,0,w){
                cout<<v[r][c];
            }
            cout<<'\n';
        }
    }
    return 0;
}