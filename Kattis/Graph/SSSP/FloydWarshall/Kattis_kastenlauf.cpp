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
    int t;
    cin >>t;
    while(t--){
        int V;
        cin >>V;
        V+=2;
        vii AM(V,vi(V,INF));
        vector<pair<int,int>> coord;
        f(i,0,V){
            int x,y;
            cin>>x>>y;
            coord.emplace_back(x,y);
        }
        f(i,0,V){
            f(j,0,V){
                int dist=abs(coord[i].first-coord[j].first)+abs(coord[i].second-coord[j].second);
                if (dist>20*50){
                    AM[i][j]=0;
                    AM[j][i]=0;
                }
                else {
                    AM[i][j] = 1;
                    AM[j][i] =1;
                }
            }
        }
        f(k,0,V)
        {
            f(i,0,V){
                f(j,0,V){
                    AM[i][j]|=(AM[i][k]&AM[k][j]);
                }
            }
        }
        if (AM[0][V-1])
            cout<<"happy\n";
        else cout<<"sad\n";
    }
    return 0;

}