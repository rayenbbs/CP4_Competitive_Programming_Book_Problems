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

vi rd={1,0,-1,0};
vi cd={0,1,0,-1};
int n;
vector<vector<char>> v;


bool check(int r,int c, char a){
    f(i,0,4){
        if (r+rd[i]<n && r+rd[i]>=0 && c+cd[i]>=0 && c+cd[i]<n){
            if (v[r+rd[i]][c+cd[i]]==a)
                return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    int testcount=1;
    while(t--){
        cin>>n;
        v.assign(n,vector<char>(n));
        f(i,0,n){
            f(j,0,n){
                cin>>v[i][j];
            }
        }
        f(r,0,n){
            f(c,0,n){
                if (v[r][c]=='.'){
                    char a='A';
                    while(!check(r,c,a)){
                        a=a+1;
                    }
                    v[r][c]=a;
                }
            }
        }
        cout<<"Case "<<testcount++<<":\n";
        f(r,0,n){
            f(c,0,n){
                cout<<v[r][c];
            }
            cout<<'\n';
        }
    }

}
