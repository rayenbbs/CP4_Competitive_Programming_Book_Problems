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


int n;
int t;
vector<pair<double,double>> v;

double fu(double r){
    double k=n-r;
    double vr=v[t-1].first; double vk=v[t-1].second;
    double mind=INF;
    f(i,0,t-1){
        mind=min(r/v[i].first+k/v[i].second,mind);
    }
    return (mind*60*60-(r/vr+k/vk)*60*60);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(cin >>n){
        cin>>t;
        v.assign(t,pair<double,double>());
        f(i,0,t){
            cin>>v[i].first;
            cin>>v[i].second;
        }
        double hi=n;
        double lo=0;
        for (int i = 0; i < 50; ++i) { // similar as BSTA
            double delta = (hi-lo)/3.0; // 1/3rd of the range
            double m1 = lo+delta; // 1/3rd away from lo
            double m2 = hi-delta; // 1/3rd away from hi
            (fu(m1) < fu(m2)) ? lo = m1 : hi = m2; // f is unimodal
        }
        double result=fu(lo);
        if (result>=0){
            printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n",round(result),lo,n-lo);
        }
        else printf("The cheater cannot win.\n");
    }
}