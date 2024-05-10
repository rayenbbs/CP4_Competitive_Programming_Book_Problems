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
    int n;
    int t=1;
    while(cin >>n){
        cout<<"Case "<<t++<<":\n";
        vi v(n,0);
        f(i,0,n){
            cin >>v[i];
        }
        int m;
        cin >>m;
        f(i,0,m){
            int query;
            cin >>query;
            int dist=INF;
            int result=-1;
            f(j,0,n){
                f(k,j+1,n){
                    int sum=v[j]+v[k];
                    if (abs(sum-query)<dist){
                        dist=abs(sum-query);
                        result=sum;
                    }
                }
            }
            cout<<"Closest sum to "<<query<<" is "<<result<<"."<<endl;
        }
    }
}