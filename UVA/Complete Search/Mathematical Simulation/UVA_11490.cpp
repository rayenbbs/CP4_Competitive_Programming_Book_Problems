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
    ll n;
    cin >>n;
    while(n!=0){
        int test=false;
        for(ll i=1;i<=(ll)sqrt(n/6)+1;++i){
            if (n-6*i*i<7*i)
                break;
            else
            if ((n-6*i*i)%(7*i)==0){
                ll temp=(n-6*i*i)/(7*i);
                test=true;
                ll result=temp%100000007;
                result=(result*result)%100000007;
                result*=2;
                result%=100000007;
                cout<<"Possible Missing Soldiers = "<<result<<'\n';
            }
        }
        if (!test){
            cout<<"No Solution Possible\n";
        }
        cout<<'\n';
        cin >>n;
    }
}

