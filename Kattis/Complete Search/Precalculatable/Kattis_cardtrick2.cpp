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



vector<deque<pair<int,int>>> v(14,deque<pair<int,int>>());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vii result(14,vi(14));
    f(i,1,14){
        f(j,1,i+1){
            v[i].emplace_back(0,j);
        }
    }
    f(i,1,14){
        f(j,1,i+1) {
            if (!v[i].empty()) {
                f(t, 0, j) {
                    int temp = v[i].front().second;
                    v[i].pop_front();
                    v[i].emplace_back(0, temp);
                }
                pair<int, int> temp = v[i].front();
                v[i].pop_front();
                result[i][temp.second] = j;
            }
        }
    }

    int t;
    cin >>t;
    while(t--){
        int q;
        cin >>q;
        f(i,1,q+1){
            if (i!=1)
                cout <<" ";
            cout<<result[q][i];
        }
        cout<<endl;
    }



}