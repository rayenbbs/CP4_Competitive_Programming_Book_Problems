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

bool check(vector<vector<char>>&grid,int radius,int r,int c){
    char a=grid[r][c];
    f(i,0,radius+1){
        f(j,0,radius+1){
            if (grid[r+i][c+j]!=a){
                return false;
            }
            if (grid[r+i][c-j]!=a){
                return false;
            }
            if (grid[r-i][c-j]!=a){
                return false;
            }
            if (grid[r-i][c+j]!=a){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    vector<vector<char>> grid;
    while(t--){
        int m,n,q;
        cin >>m>>n>>q;
        cout<<m<<" "<<n<<" "<<q<<"\n";
        grid.assign(m,vector<char>(n));
        f(r,0,m){
            f(c,0,n){
                cin>>grid[r][c];
            }
        }
        f(i,0,q){
            int r,c;
            cin >>r>>c;
            int radius=INF;
            radius=min(radius,r-0);
            radius=min(radius,c-0);
            radius=min(radius,m-1-r);
            radius=min(radius,n-1-c);
            while(true){
                if (radius==0){
                    cout<<1<<endl;
                    break;
                }
                if(check(grid,radius,r,c)){
                    cout<<radius*2+1<<endl;
                    break;
                }
                else --radius;

            }
        }
    }
}
