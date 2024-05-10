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

    int n,g;
    while(cin>>n>>g){
        vi diff(n);
        f(i,0,n){
            int l,r;
            cin>>l>>r;
            diff[i]=r-l;
        }
        sort(diff.begin(),diff.end());
        int points=0;
        f(i,0,n){
            if (diff[i]<0){
                points+=3;
                continue;
            }
            while(diff[i]>=0 && g>0){
                diff[i]--;
                g--;
            }
            if (diff[i]<0){
                points+=3;
            }
            else if (diff[i]==0){
                points+=1;
            }
        }
        cout<<points<<'\n';
    }

    return 0;

}
