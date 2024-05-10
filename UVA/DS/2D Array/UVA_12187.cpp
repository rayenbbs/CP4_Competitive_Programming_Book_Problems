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


#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int rd[] ={ 0 , 0, 1 , -1};
int cd[] = { 1, -1, 0, 0};

int n,R,C,k;
vii v;

void battle(){
    vii temp(R,vi(C));
    f(r,0,R){
        f(c,0,C){
            temp[r][c]=v[r][c];
        }
    }
    f(r,0,R){
        f(c,0,C){
            f(i,0,4){
                if (r+rd[i]>=0 && r+rd[i]<R && c+cd[i]>=0 && c+cd[i]<C){
                    if ((v[r][c]+1)%n==v[r+rd[i]][c+cd[i]]){
                        temp[r+rd[i]][c+cd[i]]=v[r][c];
                    }
                }
            }
        }
    }
    f(r,0,R) {
        f(c, 0, C) {
            v[r][c]=temp[r][c];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin>>n>>R>>C>>k && n && R && C && k){
        v.assign(R,vi(C));
        f(r,0,R){
            f(c,0,C){
                cin>>v[r][c];
            }
        }
        while(k--){
            battle();
        }
        f(r,0,R){
            f(c,0,C){
                if (c){
                    cout<<' ';
                }
                cout<<v[r][c];
            }
            cout<<'\n';
        }
    }

    return 0;
}

