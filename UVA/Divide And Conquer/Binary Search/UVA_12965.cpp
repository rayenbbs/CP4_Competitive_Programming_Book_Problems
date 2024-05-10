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

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>t;
    int p,c;
    vi vp;
    vi vc;
    vi vall;
    while(t--){
        cin >>p>>c;
        vp.assign(p,0);
        vc.assign(c,0);
        vall.assign(p+c,0);
        f(i,0,p){
            cin >>vp[i];
            vall[i]=vp[i];
        }
        f(i,0,c){
            cin >>vc[i];
            vall[p+i]=vc[i];
        }
        sort(vp.begin(),vp.end());
        sort(vc.begin(),vc.end());
        sort(vall.begin(),vall.end());
        pii result={INF,INF};
        if (vp.empty()){
            result={0,0};
        }
        else if(vc.empty()){
            result={vp[p-1],0};
        }
        else {
            auto it1 = upper_bound(vp.begin(), vp.end(), 0);
            int indp = vp.end() - it1;
            auto it2 = lower_bound(vc.begin(), vc.end(), 0);
            int indc = it2 - vc.begin();
            if (result.second > indp + indc) {
                result.first = 0;
                result.second = indp + indc;
            }
            f(i, 0, vall.size()) {
                auto it1 = upper_bound(vp.begin(), vp.end(), vall[i]);
                int indp = vp.end() - it1;
                auto it2 = lower_bound(vc.begin(), vc.end(), vall[i]);
                int indc = it2 - vc.begin();
                if (result.second > indp + indc) {
                    result.first = vall[i];
                    result.second = indp + indc;
                }
            }
        }
        cout<<result.first<<" "<<result.second<<'\n';
    }
}


