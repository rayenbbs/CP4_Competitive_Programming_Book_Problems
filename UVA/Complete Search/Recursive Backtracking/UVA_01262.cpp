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

vector<string> grid1;
vector<string> grid2;
vector<string> solutions;
uset <string> used;

void backtrack(int indice,string &temp){
    if(temp.size()==5){
        solutions.pb(temp);
        return ;
    }
    else if (indice==5)
        return ;
    else
    {
        f(r1,0,6){
            f(r2,0,6){
                if (grid1[r1][indice]==grid2[r2][indice]){
                    temp.pb(grid1[r1][indice]);
                    if (used.find(temp)==used.end()) {
                        used.insert(temp);
                        backtrack(indice + 1, temp);
                    }
                    temp.pop_back();
                    break;
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        grid1.assign(6,string(5,'a'));
        grid2.assign(6,string(5,'a'));
        int k;
        cin>>k;
        f(r,0,6){
            f(c,0,5){
                cin >>grid1[r][c];
            }
        }
        f(r,0,6){
            f(c,0,5){
                cin >>grid2[r][c];
            }
        }
        solutions.clear();
        string temp;
        used.clear();
        backtrack(0,temp);
        if (k-1>=solutions.size())
            cout<<"NO\n";
        else {sort(solutions.begin(),solutions.end());
            cout<<solutions[k-1]<<endl;
        }
    }
}