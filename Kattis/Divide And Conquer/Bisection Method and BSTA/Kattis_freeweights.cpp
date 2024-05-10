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

const double EPS=1e-7;
vi v1;
vi v2;
int n;

bool can(int mid){
    int prev=-1;
    int prev2=-1;
    int test=true;
    f(i,0,n){
        if (v1[i]>mid && prev==-1){
            prev=v1[i];
        }
        else if (v1[i]>mid && prev!=-1){
            if (v1[i]!=prev){
                test=false;
            }
            prev=-1;
        }
        if (v2[i]>mid && prev2==-1){
            prev2=v2[i];
        }
        else if (v2[i]>mid && prev2!=-1){
            if (v2[i]!=prev2){
                test=false;
            }
            prev2=-1;
        }
    }
    return test && prev==-1 && prev2==-1;
}

//simple calculation
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    v1.assign(n,0);
    v2.assign(n,0);
    int maxi=-1;
    f(i,0,n){
        cin >>v1[i];
        maxi=max(v1[i],maxi);
    }
    f(i,0,n){
        cin >>v2[i];
        maxi=max(v2[i],maxi);
    }
    int l=0;
    int r=maxi;
    while(r-l>1){
        int mid=(r+l)/2;
        can(mid)? r=mid : l=mid;
    }
    if (can(l)) {
        cout << l << '\n';
    }
    else{
        cout<<r<<'\n';
    }
}
