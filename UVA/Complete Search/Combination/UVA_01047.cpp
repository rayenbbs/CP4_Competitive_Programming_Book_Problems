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
    int n,b;
    cin >>n>>b;
    int testcount=1;
    while (n!=0 || b!=0){
        printf("Case Number  %d\n",testcount++);
        vi covered(n);
        f(i,0,n){
            cin >>covered[i];
        }
        vector<pair<int,vi>> common;
        int m;
        cin >>m;
        f(i,0,m){
            int l;
            cin>>l;
            common.eb(0,vi(l));
            f(j,0,l){
                cin>>common.back().second[j];
            }
            cin >>common.back().first;
        }
        vi result;
        int best=-1;
        //what if the number of towers to be build is bigger than the planned?
        f(i,0,1<<n){
            uset <int> setselected;
            int count=0;
            vi selected;
            int total=0;
            f(j,0,n){
                if (1<<j & i){
                    selected.pb(j);
                    total+=covered[j];
                    setselected.insert(j+1);
                    ++count;
                }
            }
            if (count!=b){
                continue;
            }
            f(p,0,common.size()){
                int countinter=0;
                bool test=false;
                f(k,0,common[p].second.size()){
                    if (setselected.find(common[p].second[k])!=setselected.end()){
                        test=true;
                        countinter++;
                    }
                }
                if (test){
                    total-=(countinter-1)*common[p].first;
                }
            }
            if (total>best){
                best=total;
                result=selected;
            }
        }
        printf("Number of Customers: %d\n",best);
        printf("Locations recommended:");
        f(i,0,result.size()){
            printf(" %d",result[i]+1);
        }
        printf("\n\n");
        cin >>n>>b;
    }
}
