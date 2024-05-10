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

    int k;
    cin >>k;
    int t=1;
    while(k!=0){
        if (t!=1)
            cout<<endl;
        ++t;
        vi v;
        f(i,0,k){
            int a;
            cin >>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        f(a,0,k-5){
            f(b,a+1,k-4){
                f(c,b+1,k-3){
                    f(d,c+1,k-2){
                        f(e,d+1,k-1){
                            f(f,e+1,k){
                                cout<<v[a]<<" "<<v[b]<<" "<<v[c]<<" "<< v[d]<<" "<<v[e]<<" "<<v[f]<<endl;
                            }
                        }
                    }
                }
            }
        }
        cin >>k;
    }
    return 0;




}