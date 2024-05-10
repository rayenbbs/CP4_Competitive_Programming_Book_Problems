#include <bits/stdc++.h>
using namespace std;


#define LSOne(S) ((S) & -(S))
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

vector<vector<char>> v(5,vector<char>(5));

int vr[]={2,2,-2,-2,1,1,-1,-1};
int vc[] ={1,-1,1,-1,2,-2,2,-2};

bool check(int r,int c){
    f(i,0,8){
        if (r+vr[i]<5 && r+vr[i]>=0 && c+vc[i]<5 && c+vc[i]>=0){
            if (v[r+vr[i]][c+vc[i]]=='k'){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool result=true;
    f(r,0,5){
        f(c,0,5){
            cin>>v[r][c];
        }
    }
    int count=0;
    f(r,0,5){
        f(c,0,5){
            if (v[r][c]=='k'){
                ++count;
                result= result && check(r,c);
            }
        }
    }
    if (result && count==9){
        cout<<"valid\n";
    }
    else{
        cout<<"invalid\n";
    }



    return 0;
}

