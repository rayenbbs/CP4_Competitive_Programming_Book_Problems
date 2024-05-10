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




void backtrack(string& temp,int &solution, int target,vii&grid,int r,int c){
    if (grid[r][c]<0){
        return ;
    }
    else if (temp.size()>3){
        return ;
    }
    else{
        temp.pb(grid[r][c]);
        int test=0;
        f(i,0,temp.size()){
            test+= temp[i]*pow(10,temp.size()-1-i);
        }
        if (abs(test-target)<abs(target-solution)){
            solution=test;
        }
        f(i,r,4){
            f(j,c,3){
                backtrack(temp,solution,target,grid,i,j);
            }
        }
        temp.pop_back();


    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    vii grid(4,vi(3));
    f(i,1,10){
        int r=(i-1)/3;
        int c=(i-1)%3;
        grid[r][c]=i;
    }
    grid[3][0]=-1;
    grid[3][1]=0;
    grid[3][2]=-1;
    while(t--){
        int k;
        cin>>k;
        string temp;
        int solution=INF;
        f(r,0,4){
            f(c,0,3){
                backtrack(temp,solution,k,grid,r,c);
            }
        }
        cout<<solution<<'\n';
    }
}
