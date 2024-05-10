#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vii vector<vector<int>>
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

void dfs(int u,int v,int w,vii &AM,vii &result,vector<vector<pair<int,int>>> &AL){
if (w>result[u][v]) return ;
if (w > AM[u][v]) {
result[u][v] = w;
}
for (auto &[k, c]: AL[v]) {
dfs(u, k, w + c, AM, result, AL);
}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    int countest=1;
    while(t--){
        cout<<"Case #"<<countest++<<":"<<endl;
        int lines;
        cin >>lines;
        vii AM(lines+1,vi(lines+1,INF));
        f(i,0,lines-1) {
            f(j, 0, i+1) {
                int a;
                cin >> a;
                AM[i + 1][j] = a;
                AM[j][i + 1] = a;
                //cout<<i+1<<" "<<j<<endl;
            }
        }
        f(i,0,lines) {
            AM[i][i]=0;
        }

        vii result(lines+1,vi(lines+1,INF));
        f(i,0,lines){
            f(j,0,lines){
                bool test=true;
                f(k,0,lines) {
                    if (AM[i][j] == AM[i][k] + AM[k][j] && k!=j && k!=i)
                        test = false;
                }
                if (test){
                    result[i][j]=AM[i][j];
                }
            }
        }
        bool test=true;
        for (int k = 0; k < lines; ++k) // loop order is k->i->j
            for (int i = 0; i < lines; ++i)
                for (int j = 0; j < lines; ++j) {
                    if (result[i][k] + result[k][j]<result[i][j] && result[i][j]!=INF){
                        test=false;
                    }
                }
        int count=0;

        if (!test){
            cout<<"Need better measurements.\n";
        }
        else {
            f(i, 0, lines) {
                f(j, i + 1, lines) {
                    if (result[i][j] != INF) {
                        ++count;
                    }
                }
            }
            cout<<count<<endl;
            f(i, 0, lines) {
                f(j, i + 1, lines) {
                    if (result[i][j] != INF) {
                        cout << i + 1 << " " << j + 1 << " " << result[i][j] << endl;
                    }
                }
            }


        }
        cout<<endl;


    }


    return 0;

}