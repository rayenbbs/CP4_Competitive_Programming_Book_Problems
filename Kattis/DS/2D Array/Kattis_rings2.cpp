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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;

    vii v(n,vi(m));
    f(r,0,n){
        f(c,0,m){
            char a;
            cin>>a;
            if (a=='T'){
                if (r==0 || c==0 || r==n-1 || c==m-1){
                    v[r][c]=1;
                }
                else{v[r][c]=-1;}
            }
            else{
                v[r][c]=0;
            }
        }
    }
    int maxi=0;
    f(test,0,max(n,m)+1){
        f(r,0,n){
            f(c,0,m){
                if (v[r][c]==test){
                    if (r+1<n && v[r+1][c]==-1){
                        v[r+1][c]=test+1;
                        maxi=test+1;
                    }
                    if (c+1<m &&  v[r][c+1]==-1){
                        v[r][c+1]=test+1;
                        maxi=test+1;
                    }
                    if(c-1>=0 &&  v[r][c-1]==-1){
                        v[r][c-1]=test+1;
                        maxi=test+1;
                    }
                    if(r-1>=0 && v[r-1][c]==-1){
                        v[r-1][c]=test+1;
                        maxi=test+1;
                    }
                }
            }
        }
    }
    f(r,0,n){
        f(c,0,m){
            cout<<'.';
            if (v[r][c]==0) {
                if (maxi%10==maxi)
                    cout << ".";
                else cout<<"..";
            }
            else {
                if (v[r][c]%10 == v[r][c] && maxi %10 !=maxi)
                    cout<<".";
                cout << v[r][c];
            }
        }
        cout<<"\n";
    }
    return 0;
}