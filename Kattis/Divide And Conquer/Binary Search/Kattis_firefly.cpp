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

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int L,H;
    cin >>L>>H;
    vi vc;
    vi vf;
    f(i,0,L){
        int a;
        cin >>a;
        if (i%2==0){
            vf.pb(a);
        }
        else{
            vc.pb(a);
        }
    }
    sort(vf.begin(),vf.end());
    sort(vc.begin(),vc.end());
    pii result={INF,INF};
    f(i,1,H+1){
        int nb1= vf.size()-(lower_bound(vf.begin(),vf.end(),i)-vf.begin());
        int nb2 =vc.size()- (lower_bound(vc.begin(),vc.end(),H+1-i)-vc.begin());
        if (nb1+nb2<result.second){
            result={1,nb1+nb2};
        }
        else if(result.second==nb1+nb2){
            result.first++;
        }
    }
    cout<<result.second<<" "<<result.first<<'\n';
}


