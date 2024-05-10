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

const double EPS=1e-6;
vector<pair<double,double>> v1;
vector<pair<double,double>> v2;
int a,b;
double length;

bool can(double mid){
    double time=0;
    double xa=0;
    double xb=0;
    f(i,0,a){
        if (time+v1[i].second<mid){
            xa+=v1[i].first;
            time+=v1[i].second;
        }
        else {
            xa+=(mid-time)*(v1[i].first/v1[i].second);
            break;
        }
    }
    time=0;
    f(i,0,b){
        if (time+v2[i].second<mid){
            xb+=v2[i].first;
            time+=v2[i].second;
        }
        else {
            xb+=(mid-time)*(v2[i].first/v2[i].second);
            break;
        }
    }
    return (xa>=length-xb);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>a>>b;
    v1.assign(a,pair<double,double>());
    v2.assign(b,pair<double,double>());
    double sum=0;
    length=0;
    f(i,0,a){
        cin >>v1[i].first;
        cin >>v1[i].second;
        sum+=v1[i].second;
        length+=v1[i].first;
    }
    f(i,0,b){
        cin >>v2[i].first;
        cin >>v2[i].second;
    }
    double l=0;
    double r=sum;
    while(fabs(r-l)>EPS){
        double mid=(r+l)/2;
        can(mid)? r=mid : l=mid;
    }
    printf("%0.6lf\n",l);
}
