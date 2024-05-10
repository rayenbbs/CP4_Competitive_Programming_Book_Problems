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
    int n;
    while(cin >>n){
        if (n==0)
            break;
        vector<pii> cord(n,{-1,-1});
        f(i,0,n){
            int x,y;
            cin >>x>>y;
            cord[i]={x,y};
        }
        vector<vector<double>> AM(n,vector<double>(n,INF));
        vector<vector<double>> edgeAM(n,vector<double>(n,INF));

        f(i,0,n){
            AM[i][i]=0;
        }
        int m;
        cin>>m;
        f(i,0,m){
            int u,v;
            cin >>u>>v;

            AM[u][v]=sqrt((int)(pow(cord[u].first-cord[v].first,2)+pow(cord[u].second-cord[v].second,2)));
            AM[v][u]=sqrt((int)(pow(cord[u].first-cord[v].first,2)+pow(cord[u].second-cord[v].second,2)));
            edgeAM[u][v]=1;
            edgeAM[v][u]=1;

        }
        int V=n;
        for (int k = 0; k < V; ++k) // loop order is k->i->j
            for (int i = 0; i < V; ++i)
                for (int j = 0; j < V; ++j) {
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
                    AM[j][i]=AM[i][j];
                }
        double intitialtotal=0;
        for (int i = 0; i < V; ++i)
            for (int j = i; j < V; ++j)
                if (AM[i][j]!=INF){
                    intitialtotal+=AM[i][j];
                }
        double min=intitialtotal;
        pii result={-1,-1};
        queue<pair<int,int>> q;
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (edgeAM[i][j]==INF){
                    q.emplace(i,j);
                }
        while(!q.empty()) {
            pii u=q.front();q.pop();
            int i=u.first; int j=u.second;

            double diff = 0;
            vector<vector<double>> tempAM(n, vector<double>(n, INF));
            for (int i1 = 0; i1 < V; ++i1)
                for (int j1 = 0; j1 < V; ++j1) {
                    tempAM[i1][j1] = AM[i1][j1];
                }
            diff += tempAM[i][j] -
                    (sqrt((int) (pow(cord[i].first - cord[j].first, 2) + pow(cord[i].second - cord[j].second, 2))));
            tempAM[i][j] = sqrt(
                    (int) (pow(cord[i].first - cord[j].first, 2) + pow(cord[i].second - cord[j].second, 2)));
            tempAM[j][i] = sqrt(
                    (int) (pow(cord[i].first - cord[j].first, 2) + pow(cord[i].second - cord[j].second, 2)));
            for (int i1 = 0; i1 < V; ++i1)
                for (int j1 = 0; j1 < V; ++j1) {
                    if (tempAM[i1][j1] > tempAM[i1][i] + tempAM[i][j] + tempAM[j][j1]) {
                        tempAM[i1][j1] = tempAM[i1][i] + tempAM[i][j] + tempAM[j][j1];
                    }
                    if (tempAM[i1][j1] > tempAM[i1][j] + tempAM[j][i] + tempAM[i][j1]) {
                        tempAM[i1][j1] = tempAM[i1][j] + tempAM[j][i] + tempAM[i][j1];
                    }
                }
            double newsum=0;
            for(int i1 = 0; i1 < V; i1++) {
                for(int j1 = i1; j1 < V; j1++) {
                    newsum += tempAM[i1][j1];
                }
            }
            if (newsum<min){
                result={i,j};
                min=newsum;
            }
        }

        if (result.first!=-1){
            cout<<fixed<<"adding "<<result.first<<" "<<result.second<<" reduces "<<intitialtotal<<" to "<<min<<endl;
        }
        else cout<<fixed<<"no addition reduces "<<intitialtotal<<endl;
    }

    return 0;

}