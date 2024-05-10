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
    int n,k;
    cin >>n>>k;
    vi positions(n);
    vector<ll> mail(n);
    f(i,0,n){
        int x,m;
        cin>>x>>m;
        positions[i]=x;
        mail[i]=m;
    }
    ll ind= lower_bound(positions.begin(),positions.end(),0)-positions.begin();
    ll startl=ind-1; ll startr=ind;
    ll result=0;
    ll l=0,r=n-1;
    ll tempk=k;
    while(l<=startl){
        if (tempk==k) {
            result += abs(positions[l]) * 2;
        }
        ll temp=mail[l];
        mail[l]-=min(tempk,mail[l]);
        tempk-=min(tempk,temp);
        if (tempk==0){
            tempk=k;
        }
        if (mail[l]==0){
            l++;
        }
    }
    tempk=k;
    while(r>=startr){
        if (tempk==k) {
            result += positions[r] * 2;
        }
        ll temp=mail[r];
        mail[r]-=min(tempk,mail[r]);
        tempk-=min(tempk,temp);
        if (tempk==0){
            tempk=k;
        }
        if (mail[r]==0){
            r--;
        }
    }
    cout<<result<<'\n';

}