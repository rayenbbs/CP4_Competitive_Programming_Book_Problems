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


ll a,b;

ll electomoney(ll x)
{
    ll result=0;
    if (x>1000000){
        result=(x-1000000)*7+990000*5+9900*3+2*100;
    }
    else if(x>10000){
        result=(x-10000)*5+9900*3+2*100;
    }
    else if(x>100){
        result=(x-100)*3+2*100;
    }
    else{
        result=x*2;
    }
    return  result;
}

ll moneytoelec(ll x){
    ll total=0;
    if (x>2*100+3*9900+5*990000){
        total=(x-(2*100+3*9900+5*990000))/7;
        total+=1000000;
    }
    else if (x>2*100+3*9900){
        total=(x-(2*100+3*9900))/5;
        total+=10000;
    }
    else if (x>2*100){
        total=(x-2*100)/3;
        total+=100;
    }
    else{
        total=x/2;
    }
    return total;
}

bool rcan(ll x){
    ll total= moneytoelec(a);
    ll y=total-x;
    ll costy= electomoney(y);
    ll costx= electomoney(x);
    return (costy-costx==b);
}

bool can(ll x){
    ll total= moneytoelec(a);
    ll y=total-x;
    ll costy= electomoney(y);
    ll costx= electomoney(x);
    return (costy-costx<=b);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >>a>>b;
    while(a!=0 || b!=0)
    {
        ll lo=0,hi=a;
        ll mid;
        while(true){
            mid=(lo+hi)/2;
            if( rcan(mid)) {
                break;
            }
            can (mid) ? hi=mid-1: lo = mid+1;
        }
        cout<<electomoney(mid)<<'\n';
        cin >>a>>b;
    }
}


