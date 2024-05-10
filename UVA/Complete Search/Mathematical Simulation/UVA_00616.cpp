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
    int n;
    cin >>n;
    while(n>=0){
        bool test5=false;
        for(int i=sqrt(n)+1 ;i>=2;--i){
            bool test=true;
            int temp=n;
            f(j,0,i){
                if (temp%i==1){
                    --temp;
                    temp-=(temp/i);
                }
                else {
                    test=false;
                    break;
                }
            }
            if (!test)
                continue;
            else
            {
                if (temp%i==0)
                {
                    test5=true;
                    printf("%d coconuts, %d people and 1 monkey\n",n,i);
                    break;
                }
            }
        }
        if (!test5){
            printf("%d coconuts, no solution\n",n);
        }
        cin >>n;
    }
}