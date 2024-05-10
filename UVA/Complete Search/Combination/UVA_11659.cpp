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
    int n,m;
    cin >>n>>m;
    while(n!=0|| m!=0){
        int best=-1;
        vii reliable(n+1,vi());
        f(i,0,m){
            int a,b;
            cin >>a>>b;
            reliable[a].pb(b);
        }
        uset <int> selectedset(2*n);
        vi selected;
        int count=0;
        bool test;
        f(i,0,1<<n){
            selectedset.clear();
            selected.clear();
            count=0;
            f(j,0,n){
                if (i & 1<<j){
                    ++count;
                    selected.pb(j+1);
                    selectedset.insert(j+1);
                }
            }
            test=true;
            f(j,0,selected.size()){
                if(!test)
                    break;
                f(t,0,reliable[selected[j]].size()){
                    if (reliable[selected[j]][t]<0 && selectedset.find(-reliable[selected[j]][t])!=selectedset.end()){
                        test=false;
                        break;
                    }
                    if (reliable[selected[j]][t]>0 && selectedset.find(reliable[selected[j]][t])==selectedset.end()){
                        test=false;
                        break;
                    }
                }
            }
            if (!test){
                continue;
            }
            else best=max(best,count);
        }
        cout<<best<<'\n';
        cin>>n>>m;
    }
}
