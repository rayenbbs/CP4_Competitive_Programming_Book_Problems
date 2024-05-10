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
    int l,w,n,r;
    cin >>l>>w>>n>>r;
    vector<pair<double,double>> centers(4);
    centers[0]={-(double)l/2,0};
    centers[1]={(double)l/2,0};
    centers[2]={0,-(double)w/2};
    centers[3]={0,(double)w/2};
    vector<pair<double,double>> coordinates;
    vii covered(n,vi());
    vector<int> countcovered(4,0);
    f(j,0,n){
        int a,b;
        cin >>a>>b;
        coordinates.eb(a,b);
        f(i,0,4){
            if (pow(centers[i].first-a,2)+pow(centers[i].second-b,2)<=r*r){
                covered[j].pb(i);
                countcovered[i]++;
            }
        }
    }
    f(i,0,4){
        if (countcovered[i]==0){
            cout<<"Impossible\n";
            return 0;
        }
    }
    int result=4;
    vector<pair<int,int>> result2;
    f(j,0,n){
        if (covered[j].size()==4){
            result=min(result,1);
        }
        else if (covered[j].size()==3){
            result=min(result,2);
        }
        else if (covered[j].size()==2){
            result=min(result,3);
            result2.eb(covered[j][0],covered[j][1]);
        }
    }
    f(i,0,result2.size()){
        f(j,i+1,result2.size()){
            vi set(4,0);
            set[result2[j].first]=1;
            set[result2[j].second]=1;
            set[result2[i].first]=1;
            set[result2[i].second]=1;
            bool test=true;
            f(i,0,4){
                if (set[i]==0)
                    test=false;
            }
            if (test){
                result=min(result,2);
            }
        }
    }
    cout<<result<<'\n';

}