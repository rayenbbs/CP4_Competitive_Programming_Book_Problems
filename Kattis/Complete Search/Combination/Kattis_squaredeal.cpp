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
    int h,w;
    vector<pair<int,int>> dimensions(3);
    f(i,0,3){
        cin >>h>>w;
        dimensions[i]={h,w};
    }
    f(i,0,1<<3){
        vector<pair<int,int>> interdimensions=dimensions;
        f(j,0,3) {
            if (i & 1 << j) {
                int temp = interdimensions[j].first;
                interdimensions[j].first = interdimensions[j].second;
                interdimensions[j].second = temp;
            }
        }
        sort(interdimensions.begin(),interdimensions.end());
        do{
            int target1=-2;
            int target2=-1;
            if (interdimensions[0].first==interdimensions[1].first){
                target1=interdimensions[0].second+interdimensions[1].second;
            }
            if (target1==interdimensions[2].first){
                target2=interdimensions[0].first+interdimensions[2].second;
                if (target1==target2){
                    printf("YES\n");
                    return 0;
                }
            }
            else if (interdimensions[0].first==interdimensions[2].first){
                target2=target1+interdimensions[2].second;
                if (interdimensions[0].first==target2){
                    printf("YES\n");
                    return 0;
                }            }

        }while(next_permutation(interdimensions.begin(),interdimensions.end()));
    }
    printf("NO\n");
    return 0;
}
