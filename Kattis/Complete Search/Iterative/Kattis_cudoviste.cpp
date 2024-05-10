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
    int r,c;
    cin >>r>>c;
    vector<vector<char>> grid(r,vector<char>(c));
    f(i,0,r){
        f(j,0,c) {
            cin >>grid[i][j];
        }
    }
    umap <int,int> mymap;
    f(i,0,r-1){
        f(j,0,c-1){
            int count1=0;
            int count2=0;
            f(i1,i,i+2){
                f(j1,j,j+2){
                    if (grid[i1][j1]=='#'){
                        ++count1;
                    }
                    if (grid[i1][j1]=='X'){
                        ++count2;
                    }
                }
            }
            if (count1!=0){
                continue;
            }
            else mymap[count2]++;
        }
    }
    cout<<mymap[0]<<endl<<mymap[1]<<endl<<mymap[2]<<endl<<mymap[3]<<endl<<mymap[4]<<endl;


}