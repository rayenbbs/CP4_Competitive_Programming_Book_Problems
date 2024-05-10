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
    int m;
    int c;
    cin >>m>>c;
    vector<string> vm(m);
    vector<string> vc(c);
    f(i,0,m){
        cin >>vm[i];
    }
    f(i,0,c){
        cin >>vc[i];
    }
    f(i,0,c){
        pair<int,int> result={-1,-1};
        bool test=true;
        f(j,0,m){
            if (!test)
                break;
            if (vm[j].size()<vc[i].size()){
                continue;
            }
            else{
                f(l,0,vm[j].size()-vc[i].size()+1){
                    int count=0;
                    f(p,0,vc[i].size()){
                        if (vc[i][p]==vm[j][l+p]){
                            ++count;
                        }
                    }
                    if (result.first<count){
                        result={count,j+1};
                    }
                    if (count==vc[i].size()){
                        test=false;
                        break;
                    }
                }
            }
        }
        printf("%d\n",result.second);
    }


}