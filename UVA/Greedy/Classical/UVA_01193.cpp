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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    double d;
    cin >>n>>d;
    int testcount=1;
    while(n!=0 || d!=0) {
        vector<pair<double,double> > v(n);
        vector<pair<double,double>> intervals(n,{0,0});
        bool possible=true;
        f(i, 0, n) {
            double x, y;
            cin >> x >> y;
            v[i] = {x, y};
            double sidesquare=d*d-y*y;
            if (sidesquare<0){
                possible=false;
            }
            else{
                sidesquare=sqrt(sidesquare);
                intervals[i]={x-sidesquare,x+sidesquare};
            }
        }
        if (!possible){
            cout<<"Case "<<testcount++<<": -1\n";
        }
        else{
            sort(intervals.begin(),intervals.end(),[](pair<double,double> a,pair<double,double>b){
                return a.second<b.second;
            });
            int result=0;
            int indice=0;
            while(indice<n) {
                double candidate=intervals[indice].second;
                result++;
                while (indice<n && intervals[indice].first <= candidate && intervals[indice].second >= candidate) {
                    indice++;
                }
            }
            cout<<"Case "<<testcount++<<": "<<result<<"\n";
        }
        cin>>n>>d;
    }
}